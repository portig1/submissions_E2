/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 /*
   *  ======== empty.c ========
   */

  /* For usleep() */
  #include <unistd.h>
  #include <stdint.h>
  #include <stddef.h>

  /* Driver Header files */
  #include <ti/drivers/GPIO.h>
  #include <ti/drivers/ADC.h>
  // #include <ti/drivers/I2C.h>
  // #include <ti/drivers/SPI.h>
  // #include <ti/drivers/UART.h>
  // #include <ti/drivers/Watchdog.h>

  /* Driver configuration */
  #include "ti_drivers_config.h"

  /* global variableS FOR GUI COMPOSER */
  uint16_t adcValue = 0;
  uint16_t threshold = 100;
  uint16_t alert = 0;

  /*
   *  ======== mainThread ========
   */

  void *mainThread(void *arg0)
  {
      /* ~10 loops/second */
      uint32_t time = 100000;  // update ~10/second

      /* Call driver init functions */
      GPIO_init();
      ADC_init();
      // I2C_init();
      // SPI_init();
      // UART_init();
      // Watchdog_init();

      /* Open ADC Driver */
      ADC_Handle adc;
      ADC_Params params;
      ADC_Params_init(&params);
      adc = ADC_open(CONFIG_ADC_0, &params);
      if (adc == NULL) {
          // Error initializing ADC channel 0
          while (1);
      }

      while (1) {
          int_fast16_t res;

          res = ADC_convert(adc, &adcValue);
          if (res == ADC_STATUS_SUCCESS) {
              if(adcValue >= threshold) {
                  GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
                  alert = 1;
              } else{
                  GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
                  alert = 0;
              }
          }

          usleep(time);
      }
  }
