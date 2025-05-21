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
 *     - moved DECLARATIONS, TYPE DEFINITIONS and VARIABLES to this file from app_device_joystick.c.
 ********************************************************************/

#include "stdint.h"
#include "system.h"


/** DECLARATIONS ***************************************************/
//http://www.microsoft.com/whdc/archive/hidgame.mspx
#define HAT_SWITCH_NORTH            0x0
#define HAT_SWITCH_NORTH_EAST       0x1
#define HAT_SWITCH_EAST             0x2
#define HAT_SWITCH_SOUTH_EAST       0x3
#define HAT_SWITCH_SOUTH            0x4
#define HAT_SWITCH_SOUTH_WEST       0x5
#define HAT_SWITCH_WEST             0x6
#define HAT_SWITCH_NORTH_WEST       0x7
#define HAT_SWITCH_NULL             0x8

/** TYPE DEFINITIONS ************************************************/
typedef union _INTPUT_CONTROLS_TYPEDEF
{
    struct
    {
        struct
        {
            uint8_t a:1;
            uint8_t b:1;
            uint8_t c:1;
            uint8_t x:1;
            uint8_t y:1;
            uint8_t z:1;
            uint8_t L1:1;
            uint8_t R1:1;
            uint8_t start:1;
            uint8_t L2:1;
            uint8_t R2:1;
            uint8_t home:1;
            uint8_t right_stick:1;
            uint8_t left_stick:1;
            uint8_t :2;    //filler            
        } buttons;
        struct
        {
            uint8_t hat_switch:4;
            uint8_t :4;//filler
        } hat_switch;        
        struct
        {
            uint8_t X;
            uint8_t Y;
            uint8_t Z;
            uint8_t Rz;            
            uint8_t Rx;
            uint8_t Ry;                        
        } analog_stick;
    } members;
    uint8_t val[9];
} INPUT_CONTROLS;

typedef union _CONTROLLER_DATA_TYPEDEF
{
    struct
    {
        struct
        {
            uint8_t id;         //controller ID
            uint8_t size:4;     // data size
            uint8_t type:4;     // controller type
        } info;
        struct
        {
            uint8_t b:1;
            uint8_t c:1;
            uint8_t a:1;
            uint8_t start:1;
            uint8_t up:1;
            uint8_t down:1;
            uint8_t left:1;
            uint8_t right:1;
            uint8_t alpha3:1;
            uint8_t alpha2:1;
            uint8_t alpha1:1;
            uint8_t l:1;
            uint8_t z:1;
            uint8_t y:1;
            uint8_t x:1;
            uint8_t r:1;
        } buttons;
        struct
        {
            uint8_t X;
            uint8_t Y;
        }sticks;
        struct
        {
            uint8_t RT;
            uint8_t LT;
        }trigers;
        struct
        {
            uint8_t Rx;
            uint8_t Ry;
        }ex_sticks;
    } members;
    uint8_t val[10];
}CONTROLLER_DATA;

/** VARIABLES ******************************************************/
/* Some processors have a limited range of RAM addresses where the USB module
 * is able to access.  The following section is for those devices.  This section
 * assigns the buffers that need to be used by the USB module into those
 * specific areas.
 */
#if defined(FIXED_ADDRESS_MEMORY)
    #if defined(COMPILER_MPLAB_C18)
        #pragma udata JOYSTICK_DATA=JOYSTICK_DATA_ADDRESS
            INPUT_CONTROLS joystick_input;
        #pragma udata
    #elif defined(__XC8)
        INPUT_CONTROLS joystick_input JOYSTICK_DATA_ADDRESS;
    #endif
#else
    INPUT_CONTROLS joystick_input;
#endif
    
CONTROLLER_DATA controller_data;    

/*********************************************************************
* Function: void APP_DeviceJoystickInitialize(void);
*
* Overview: Initializes the demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceJoystickInitialize(void);

/*********************************************************************
* Function: void APP_DeviceJoystickStart(void);
*
* Overview: Starts running the demo.
*
* PreCondition: The device should be configured into the configuration
*   that contains the custome HID interface.  The APP_DeviceJoystickInitialize()
*   function should also have been called before calling this function.
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceJoystickStart(void);

/*********************************************************************
* Function: void APP_DeviceJoystickTasks(void);
*
* Overview: Keeps the demo running.
*
* PreCondition: The demo should have been initialized and started via
*   the APP_DeviceJoystickInitialize() and APP_DeviceJoystickStart() demos
*   respectively.
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceJoystickTasks(void);
