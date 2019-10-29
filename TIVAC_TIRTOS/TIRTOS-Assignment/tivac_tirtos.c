//---------------------------------------------------------------------------------
// Project: Blink TM4C BIOS Using Swi (SOLUTION)
// Author: Eric Wilbur
// Date: June 2014
//
// Note: The function call TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT) HAS
//       to be in the ISR. This fxn clears the TIMER's interrupt flag coming
//       from the peripheral - it does NOT clear the CPU interrupt flag - that
//       is done by hardware. The author struggled figuring this part out - hence
//       the note. And, in the Swi lab, this fxn must be placed in the
//       Timer_ISR fxn because it will be the new ISR.
//
// Follow these steps to create this project in CCSv6.0:
// 1. Project -> New CCS Project
// 2. Select Template:
//    - TI-RTOS for Tiva-C -> Driver Examples -> EK-TM4C123 LP -> Example Projects ->
//      Empty Project
//    - Empty Project contains full instrumentation (UIA, RTOS Analyzer) and
//      paths set up for the TI-RTOS version of MSP430Ware
// 3. Delete the following files:
//    - Board.h, empty.c, EK_TM4C123GXL.c/h, empty_readme.txt
// 4. Add main.c from TI-RTOS Workshop Solution file for this lab
// 5. Edit empty.cfg as needed (to add/subtract) BIOS services, delete given Task
// 6. Build, load, run...
//----------------------------------------------------------------------------------


//----------------------------------------
// BIOS header files
//----------------------------------------
#include <xdc/std.h>  						//mandatory - have to include first, for BIOS types
#include <ti/sysbios/BIOS.h> 				//mandatory - if you call APIs like BIOS_start()
#include <xdc/runtime/Log.h>				//needed for any Log_info() call
#include <xdc/cfg/global.h> 				//header file for statically defined objects/handles


//------------------------------------------
// TivaWare Header Files
//------------------------------------------
#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/adc.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "utils/uartstdio.h"
#include "utils/uartstdio.c"


//----------------------------------------
// Prototypes
//----------------------------------------
void hardware_init(void);
void ledToggle(void);
void Timer_ISR(void);
void initADC();
void getADC3(void);
void InitConsole(void);
void UARTdisplayADC(void);


//---------------------------------------
// Globals
//---------------------------------------
volatile int16_t i16ToggleCount = 0;
volatile int16_t i16InstanceCount = 0;

// This array is used for storing the data read from the ADC FIFO. It
// must be as large as the FIFO for the sequencer in use.  This example
// uses sequence 3 which has a FIFO depth of 1.  If another sequence
// was used with a deeper FIFO, then the array size must be changed.
//
uint32_t ADCValues[1];

//
// This variable is used to store the output of the ADC Channel 3
//
uint32_t ADC3out ;



//---------------------------------------------------------------------------
// main()
//---------------------------------------------------------------------------
void main(void)
{

   hardware_init();							// init hardware via Xware
   initADC();
   InitConsole();

   BIOS_start();

}


//---------------------------------------------------------------------------
// hardware_init()
//
// inits GPIO pins for toggling the LED
//---------------------------------------------------------------------------
void hardware_init(void)
{
	uint32_t ui32Period;

	//Set CPU Clock to 40MHz. 400MHz PLL/2 = 200 DIV 5 = 40MHz
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	// ADD Tiva-C GPIO setup - enables port, sets pins 1-3 (RGB) pins for output
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

	// Turn on the LED
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 4);

	// Timer 2 setup code
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);			// enable Timer 2 periph clks
	TimerConfigure(TIMER2_BASE, TIMER_CFG_PERIODIC);		// cfg Timer 2 mode - periodic

	ui32Period = (SysCtlClockGet() / 20);						// period = CPU clk div 20 (50ms)
	TimerLoadSet(TIMER2_BASE, TIMER_A, ui32Period);			// set Timer 2 period

	TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);		// enables Timer 2 to interrupt CPU

	TimerEnable(TIMER2_BASE, TIMER_A);						// enable Timer 2

}


//---------------------------------------------------------------------------
// ledToggle()
//
// toggles LED on Tiva-C LaunchPad
//---------------------------------------------------------------------------
void ledToggle(void)
{
	while(1)
	{
	    Semaphore_pend(LEDSem, BIOS_WAIT_FOREVER);

	    // LED values - 2=RED, 4=BLUE, 8=GREEN
	        if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2))
	        {
	            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
	        }
	        else
	        {
	            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 4);
	        }

	        i16ToggleCount += 1;                                    // keep track of #toggles

	        Log_info1("LED TOGGLED [%u] TIMES",i16ToggleCount);     // send toggle count to UIA
	}

}


//---------------------------------------------------------------------------
// Timer ISR - called by BIOS Hwi (see app.cfg)
//
// Posts Swi (or later a Semaphore) to toggle the LED
//---------------------------------------------------------------------------
void Timer_ISR(void)
{
    TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);			// must clear timer flag FROM timer

    if(i16InstanceCount == 10) {
        Semaphore_post(ADC3Sem);
    }

    else if (i16InstanceCount == 20) {
        Semaphore_post(UARTSem);
    }

    else if(i16InstanceCount == 30) {
        Semaphore_post(LEDSem);                                     // post LEDSwi
        i16InstanceCount = 0;
    }
    i16InstanceCount++;
}

//
// Initializes ADC0 for use
//
void initADC() {
    // The ADC3 peripheral must be enabled for use.
                //
                SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
                SysCtlDelay(3);
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
                SysCtlDelay(3);

                GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_0);    //Configure ADC pin: PE0


                //
                // Enable sample sequence 3 with a processor signal trigger.  Sequence 3
                // will do a single sample when the processor sends a singal to start the
                // conversion.  Each ADC module has 4 programmable sequences, sequence 0
                // to sequence 3.  This example is arbitrarily using sequence 3.
                //
                ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);

                //
                // Configure step 0 on sequence 3.  Sample the ADC CHANNEL 3
                // (PE0) and configure the interrupt flag (ADC_CTL_IE) to be set
                // when the sample is done.  Tell the ADC logic that this is the last
                // conversion on sequence 3 (ADC_CTL_END).  Sequence 3 has only one
                // programmable step.  Sequence 1 and 2 have 4 steps, and sequence 0 has
                // 8 programmable steps.  Since we are only doing a single conversion using
                // sequence 3 we will only configure step 0.  For more information on the
                // ADC sequences and steps, reference the datasheet.
                //
                ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH3  | ADC_CTL_IE |
                                         ADC_CTL_END);

                //
                // Since sample sequence 3 is now configured, it must be enabled.
                //
                ADCSequenceEnable(ADC0_BASE, 3);

                //
                // Clear the interrupt status flag.  This is done to make sure the
                // interrupt flag is cleared before we sample.
                //
                ADCIntClear(ADC0_BASE, 3);

}

//
// Gets value of ADC0 CH 3
//
void getADC3(void) {

    while(1) {
        Semaphore_pend(ADC3Sem, BIOS_WAIT_FOREVER);
        //
        // Trigger the ADC conversion.
        //
        ADCProcessorTrigger(ADC0_BASE, 3);

        //
        // Wait for conversion to be completed.
        //
        while(!ADCIntStatus(ADC0_BASE, 3, false))
        {
        }

        //
        // Clear the ADC interrupt flag.
        //
        ADCIntClear(ADC0_BASE, 3);

        //
        // Read ADC Value.
        //
        ADCSequenceDataGet(ADC0_BASE, 3, ADCValues);
        ADC3out = ADCValues[0];
    }

}

void InitConsole(void)
{
    //
    // Enable GPIO port A which is used for UART0 pins.
    // TODO: change this to whichever GPIO port you are using.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //
    // Configure the pin muxing for UART0 functions on port A0 and A1.
    // This step is not necessary if your part does not support pin muxing.
    // TODO: change this to select the port/pin you are using.
    //
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    //
    // Enable UART0 so that we can configure the clock.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    //
    // Use the internal 16MHz oscillator as the UART clock source.
    //
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    //
    // Select the alternate (UART) function for these pins.
    // TODO: change this to select the port/pin you are using.
    //
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    //
    // Initialize the UART for console I/O.
    //
    UARTStdioConfig(0, 115200, 16000000);
}

//
// Displays ADC values
//
void UARTdisplayADC(void) {
    while(1) {
        Semaphore_pend(UARTSem, BIOS_WAIT_FOREVER);
        UARTprintf("ADC CH3 Value: %d\n\n", ADC3out);
    }
}
