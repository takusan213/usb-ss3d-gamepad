/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
*******************************************************************************/
/*********************************************************************
 * This file is modified by Geeky Fab.
 * 
 * Changes from the original source:
 *     - added device settings
 ********************************************************************/

/** INCLUDES *******************************************************/
#include "system.h"

#include "usb.h"
#include "usb_device_hid.h"

#include "app_device_joystick.h"



MAIN_RETURN main(void)
{
    SYSTEM_Initialize(SYSTEM_STATE_USB_START);

    USBDeviceInit();
    USBDeviceAttach();

    /* set RA4 to input*/
    TRISA = 0x10;
    
    /* set all B ports input*/
    TRISB = 0xf0;
    
    /* set RC2~7 to output*/
    TRISC = 0x03;
    
    /* enabling internal pull up*/
    OPTION_REGbits.nWPUEN = 0;
    WPUA = 0x30;
    WPUB = 0x70;
    
    /* all ports used as degital ports.*/
    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELC = 0x00;
    
    /* initializing timer0 and interruption*/
    
    OPTION_REGbits.PS = 0b111;        // clock divided by 256
    OPTION_REGbits.PSA = 0;         // enabling prescaler
    OPTION_REGbits.TMR0SE = 0;      // edge select (rise)
    OPTION_REGbits.TMR0CS = 0;      // clock source select (internal)
    OPTION_REGbits.INTEDG = 1;      // interrupt edge select (rise)
//    INTCONbits.TMR0IF = 0;          // reset timer0 interrupt flag
//    INTCONbits.TMR0IE = 1;          // enabling peripheral interrupts
    INTCONbits.GIE = 1;             // enabling interrupts
    
    // setting initial value of timer 0.
    // 1 clock = 256/16MHz = 16us 
    // the timer interrupt happens every 16us x 0xff(255) = 4080us .
    // 
    // set the timer0 value so that timer interruption happens every 4000us.
    // 80us / 16us = 5 clocks
    TMR0bits.TMR0 = (uint8_t)5;
    
    
    while(1)
    {
        SYSTEM_Tasks();

        #if defined(USB_POLLING)
            // Interrupt or polling method.  If using polling, must call
            // this function periodically.  This function will take care
            // of processing and responding to SETUP transactions
            // (such as during the enumeration process when you first
            // plug in).  USB hosts require that USB devices should accept
            // and process SETUP packets in a timely fashion.  Therefore,
            // when using polling, this function should be called
            // regularly (such as once every 1.8ms or faster** [see
            // inline code comments in usb_device.c for explanation when
            // "or faster" applies])  In most cases, the USBDeviceTasks()
            // function does not take very long to execute (ex: <100
            // instruction cycles) before it returns.
            USBDeviceTasks();
        #endif

        /* If the USB device isn't configured yet, we can't really do anything
         * else since we don't have a host to talk to.  So jump back to the
         * top of the while loop. */
        if( USBGetDeviceState() < CONFIGURED_STATE )
        {
            /* Jump back to the top of the while loop. */
            continue;
        }

        /* If we are currently suspended, then we need to see if we need to
         * issue a remote wakeup.  In either case, we shouldn't process any
         * keyboard commands since we aren't currently communicating to the host
         * thus just continue back to the start of the while loop. */
        if( USBIsDeviceSuspended() == true )
        {
            /* Jump back to the top of the while loop. */
            continue;
        }

        //Application specific tasks
        APP_DeviceJoystickTasks();

    }//end while
}//end main

/*******************************************************************************
 End of File
*/

