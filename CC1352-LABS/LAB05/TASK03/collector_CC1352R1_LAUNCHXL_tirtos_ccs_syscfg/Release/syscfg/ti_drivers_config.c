/*
 *  ======== ti_drivers_config.c ========
 *  Configured TI-Drivers module definitions
 *
 *  DO NOT EDIT - This file is generated for the CC1352R1_LAUNCHXL
 *  by the SysConfig tool.
 */

#include <stddef.h>

#ifndef DeviceFamily_CC13X2
#define DeviceFamily_CC13X2
#endif

#include <ti/devices/DeviceFamily.h>

#include "ti_drivers_config.h"

/*
 *  ============================= Display =============================
 */

#include <ti/display/Display.h>
#include <ti/display/DisplayUart.h>

#define Display_UARTBUFFERSIZE 1024
static char displayUARTBuffer[Display_UARTBUFFERSIZE];

DisplayUart_Object displayUartObject;

const DisplayUart_HWAttrs displayUartHWAttrs = {
    .uartIdx      = CONFIG_DISPLAY_UART,
    .baudRate     = 115200,
    .mutexTimeout = (unsigned int)(-1),
    .strBuf       = displayUARTBuffer,
    .strBufLen    = Display_UARTBUFFERSIZE
};

const Display_Config Display_config[] = {
    /* CONFIG_DISPLAY */
    /* XDS110 UART */
    {
        .fxnTablePtr = &DisplayUartMin_fxnTable,
        .object      = &displayUartObject,
        .hwAttrs     = &displayUartHWAttrs
    },
};

const uint_least8_t Display_count = 1;


/*
 *  =============================== AESCCM ===============================
 */

#include <ti/drivers/AESCCM.h>
#include <ti/drivers/aesccm/AESCCMCC26XX.h>

#define CONFIG_AESCCM_COUNT 1

AESCCMCC26XX_Object aesccmCC26XXObjects[CONFIG_AESCCM_COUNT];

/*
 *  ======== aesccmCC26XXHWAttrs ========
 */
const AESCCMCC26XX_HWAttrs aesccmCC26XXHWAttrs[CONFIG_AESCCM_COUNT] = {
    {
        .intPriority = (~0),
    },
};

const AESCCM_Config AESCCM_config[CONFIG_AESCCM_COUNT] = {
    {   /* CONFIG_AESCCM_0 */
        .object  = &aesccmCC26XXObjects[CONFIG_AESCCM_0],
        .hwAttrs = &aesccmCC26XXHWAttrs[CONFIG_AESCCM_0]
    },
};

const uint_least8_t AESCCM_count = CONFIG_AESCCM_COUNT;



/*
 *  =============================== DMA ===============================
 */

#include <ti/drivers/dma/UDMACC26XX.h>
#include <ti/devices/cc13x2_cc26x2/driverlib/udma.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_memmap.h>

UDMACC26XX_Object udmaCC26XXObject;

const UDMACC26XX_HWAttrs udmaCC26XXHWAttrs = {
    .baseAddr        = UDMA0_BASE,
    .powerMngrId     = PowerCC26XX_PERIPH_UDMA,
    .intNum          = INT_DMA_ERR,
    .intPriority     = (~0)
};

const UDMACC26XX_Config UDMACC26XX_config[1] = {
    {
        .object         = &udmaCC26XXObject,
        .hwAttrs        = &udmaCC26XXHWAttrs,
    },
};


/*
 *  =============================== GPIO ===============================
 */

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOCC26XX.h>

/*
 *  ======== gpioPinConfigs ========
 *  Array of Pin configurations
 */
GPIO_PinConfig gpioPinConfigs[] = {
    /* CONFIG_GPIO_RLED : LaunchPad LED Red */
    GPIOCC26XX_DIO_06 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* CONFIG_GPIO_GLED : LaunchPad LED Green */
    GPIOCC26XX_DIO_07 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* CONFIG_GPIO_BTN1 : LaunchPad Button BTN-1 (Left) */
    GPIOCC26XX_DIO_15 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING,
    /* CONFIG_GPIO_BTN2 : LaunchPad Button BTN-2 (Right) */
    GPIOCC26XX_DIO_14 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING,
};

/*
 *  ======== gpioCallbackFunctions ========
 *  Array of callback function pointers
 *
 *  NOTE: Unused callback entries can be omitted from the callbacks array to
 *  reduce memory usage by enabling callback table optimization
 *  (GPIO.optimizeCallbackTableSize = true)
 */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    /* CONFIG_GPIO_RLED : LaunchPad LED Red */
    NULL,
    /* CONFIG_GPIO_GLED : LaunchPad LED Green */
    NULL,
    /* CONFIG_GPIO_BTN1 : LaunchPad Button BTN-1 (Left) */
    NULL,
    /* CONFIG_GPIO_BTN2 : LaunchPad Button BTN-2 (Right) */
    NULL,
};

/*
 *  ======== GPIOCC26XX_config ========
 */
const GPIOCC26XX_Config GPIOCC26XX_config = {
    .pinConfigs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .numberOfPinConfigs = 4,
    .numberOfCallbacks = 4,
    .intPriority = (~0)
};


/*
 *  =============================== NVS ===============================
 */

#include <ti/drivers/NVS.h>
#include <ti/drivers/nvs/NVSCC26XX.h>

/*
 *  NVSCC26XX Internal NVS flash region definitions
 *
 * Place uninitialized char arrays at addresses
 * corresponding to the 'regionBase' addresses defined in
 * the configured NVS regions. These arrays are used as
 * place holders so that the linker will not place other
 * content there.
 *
 * For GCC targets, the char arrays are each placed into
 * the shared ".nvs" section. The user must add content to
 * their GCC linker command file to place the .nvs section
 * at the lowest 'regionBase' address specified in their NVS
 * regions.
 */

#if defined(__TI_COMPILER_VERSION__)

#pragma LOCATION(flashBuf0, 0x4e000);
#pragma NOINIT(flashBuf0);
static char flashBuf0[0x8000];

#elif defined(__IAR_SYSTEMS_ICC__)

__no_init static char flashBuf0[0x8000] @ 0x4e000;

#elif defined(__GNUC__)

__attribute__ ((section (".nvs")))
static char flashBuf0[0x8000];

#endif

NVSCC26XX_Object nvsCC26XXObjects[1];

static const NVSCC26XX_HWAttrs nvsCC26XXHWAttrs[1] = {
    /* CONFIG_NVSINTERNAL */
    {
        .regionBase = (void *) flashBuf0,
        .regionSize = 0x8000
    },
};

#define CONFIG_NVS_COUNT 1

const NVS_Config NVS_config[CONFIG_NVS_COUNT] = {
    /* CONFIG_NVSINTERNAL */
    {
        .fxnTablePtr = &NVSCC26XX_fxnTable,
        .object = &nvsCC26XXObjects[0],
        .hwAttrs = &nvsCC26XXHWAttrs[0],
    },
};

const uint_least8_t NVS_count = CONFIG_NVS_COUNT;


/*
 *  =============================== PIN ===============================
 */

#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>

const PIN_Config BoardGpioInitTable[] = {
    /* XDS110 UART, Parent Signal: CONFIG_DISPLAY_UART TX, (DIO13) */
    CONFIG_PIN_UART_TX | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* XDS110 UART, Parent Signal: CONFIG_DISPLAY_UART RX, (DIO12) */
    CONFIG_PIN_UART_RX | PIN_INPUT_EN | PIN_PULLDOWN | PIN_IRQ_DIS,
    /* LaunchPad LED Red, Parent Signal: CONFIG_GPIO_RLED GPIO Pin, (DIO6) */
    CONFIG_PIN_RLED | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* LaunchPad LED Green, Parent Signal: CONFIG_GPIO_GLED GPIO Pin, (DIO7) */
    CONFIG_PIN_GLED | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MED,
    /* LaunchPad Button BTN-1 (Left), Parent Signal: CONFIG_GPIO_BTN1 GPIO Pin, (DIO15) */
    CONFIG_PIN_BTN1 | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_DIS,
    /* LaunchPad Button BTN-2 (Right), Parent Signal: CONFIG_GPIO_BTN2 GPIO Pin, (DIO14) */
    CONFIG_PIN_BTN2 | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_DIS,

    PIN_TERMINATE
};

const PINCC26XX_HWAttrs PINCC26XX_hwAttrs = {
    .intPriority = (~0),
    .swiPriority = 0
};


/*
 *  =============================== Power ===============================
 */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26X2.h>
#include "ti_drivers_config.h"

extern void PowerCC26XX_standbyPolicy(void);
extern bool PowerCC26XX_calibrate(unsigned int);

const PowerCC26X2_Config PowerCC26X2_config = {
    .enablePolicy             = true,
    .policyInitFxn            = NULL,
    .policyFxn                = PowerCC26XX_standbyPolicy,
    .calibrateFxn             = PowerCC26XX_calibrate,
    .calibrateRCOSC_LF        = true,
    .calibrateRCOSC_HF        = true,
    .enableTCXOFxn            = NULL
};



/*
 *  =============================== RF Driver ===============================
 */

#include <ti/drivers/rf/RF.h>

const RFCC26XX_HWAttrsV2 RFCC26XX_hwAttrs = {
    .hwiPriority        = (~0),
    .swiPriority        = (uint8_t)0,
    .xoscHfAlwaysNeeded = true,
    .globalCallback     = NULL,
    .globalEventMask    = 0
};



/*
 *  =============================== UART ===============================
 */

#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTCC26XX.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26X2.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_memmap.h>
#include <ti/devices/cc13x2_cc26x2/inc/hw_ints.h>

#define CONFIG_UART_COUNT 1

UARTCC26XX_Object uartCC26XXObjects[CONFIG_UART_COUNT];

static unsigned char uartCC26XXRingBuffer0[32];

static const UARTCC26XX_HWAttrsV2 uartCC26XXHWAttrs[CONFIG_UART_COUNT] = {
  {
    .baseAddr           = UART1_BASE,
    .intNum             = INT_UART1_COMB,
    .intPriority        = (~0),
    .swiPriority        = 0,
    .powerMngrId        = PowerCC26X2_PERIPH_UART1,
    .ringBufPtr         = uartCC26XXRingBuffer0,
    .ringBufSize        = sizeof(uartCC26XXRingBuffer0),
    .rxPin              = IOID_12,
    .txPin              = IOID_13,
    .ctsPin             = PIN_UNASSIGNED,
    .rtsPin             = PIN_UNASSIGNED,
    .txIntFifoThr       = UARTCC26XX_FIFO_THRESHOLD_1_8,
    .rxIntFifoThr       = UARTCC26XX_FIFO_THRESHOLD_4_8,
    .errorFxn           = NULL
  },
};

const UART_Config UART_config[CONFIG_UART_COUNT] = {
    {   /* CONFIG_DISPLAY_UART */
        .fxnTablePtr = &UARTCC26XX_fxnTable,
        .object      = &uartCC26XXObjects[0],
        .hwAttrs     = &uartCC26XXHWAttrs[0]
    },
};

const uint_least8_t UART_count = CONFIG_UART_COUNT;


/*
 *  =============================== Button ===============================
 */
#include <ti/drivers/apps/Button.h>

Button_Object ButtonObjects[2];

static const Button_HWAttrs ButtonHWAttrs[2] = {
    /* CONFIG_BTN_LEFT */
    /* LaunchPad Button BTN-1 (Left) */
    {
        .gpioIndex = CONFIG_GPIO_BTN1
    },
    /* CONFIG_BTN_RIGHT */
    /* LaunchPad Button BTN-2 (Right) */
    {
        .gpioIndex = CONFIG_GPIO_BTN2
    },
};

const Button_Config Button_config[2] = {
    /* CONFIG_BTN_LEFT */
    /* LaunchPad Button BTN-1 (Left) */
    {
        .object = &ButtonObjects[CONFIG_BTN_LEFT],
        .hwAttrs = &ButtonHWAttrs[CONFIG_BTN_LEFT]
    },
    /* CONFIG_BTN_RIGHT */
    /* LaunchPad Button BTN-2 (Right) */
    {
        .object = &ButtonObjects[CONFIG_BTN_RIGHT],
        .hwAttrs = &ButtonHWAttrs[CONFIG_BTN_RIGHT]
    },
};

const uint_least8_t Button_count = 2;


/*
 *  =============================== LED ===============================
 */
#include <ti/drivers/apps/LED.h>

LED_Object LEDObjects[2];

static const LED_HWAttrs LEDHWAttrs[2] = {
    /* CONFIG_LED_RED */
    /* LaunchPad LED Red */
    {
        .type = LED_GPIO_CONTROLLED,
        .index = CONFIG_GPIO_RLED,
    },
    /* CONFIG_LED_GREEN */
    /* LaunchPad LED Green */
    {
        .type = LED_GPIO_CONTROLLED,
        .index = CONFIG_GPIO_GLED,
    },
};

const LED_Config LED_config[2] = {
    /* CONFIG_LED_RED */
    /* LaunchPad LED Red */
    {
        .object = &LEDObjects[CONFIG_LED_RED],
        .hwAttrs = &LEDHWAttrs[CONFIG_LED_RED]
    },
    /* CONFIG_LED_GREEN */
    /* LaunchPad LED Green */
    {
        .object = &LEDObjects[CONFIG_LED_GREEN],
        .hwAttrs = &LEDHWAttrs[CONFIG_LED_GREEN]
    },
};

const uint_least8_t LED_count = 2;


#include <ti/drivers/Board.h>

/*
 *  ======== Board_initHook ========
 *  Perform any board-specific initialization needed at startup.  This
 *  function is declared weak to allow applications to override it if needed.
 */
void __attribute__((weak)) Board_initHook(void)
{
}

/*
 *  ======== Board_init ========
 *  Perform any initialization needed before using any board APIs
 */
void Board_init(void)
{
    /* ==== /ti/drivers/Power initialization ==== */
    Power_init();

    /* ==== /ti/drivers/PIN initialization ==== */
    if (PIN_init(BoardGpioInitTable) != PIN_SUCCESS) {
        /* Error with PIN_init */
        while (1);
    }
    Board_initHook();
}
