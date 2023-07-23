/*******************************************************************************
Copyright 2021 Geeky Fab. (geekyfab.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#ifndef MY_APP_DEVICE_GAMEPAD_C
#define	MY_APP_DEVICE_GAMEPAD_C

#define READ_PIN() (uint8_t)((PIN_D3_RIGHT << 3) | (PIN_D2_LEFT << 2) | (PIN_D1_DOWN << 1) | PIN_D0_UP)
//#define SET_TL_FLAG(nibble) flags.tl_flag=(nibble&0x10)>>4
#define CONCAT_HIGH_LOW(high, low) ((high << 4) | low)
#define WAIT_FOR_TL_PIN(state) while(PIN_TL != state)

#include "app_device_joystick.h"
#include "system.h"
#include "buttons.h"
#include "usb.h"
#include "usb_device_hid.h"

typedef struct _Flags{
    uint8_t crosskey_flag :2 ;
    uint8_t sw_flag :1 ;
    uint8_t tr_flag :1 ;
    uint8_t tl_flag :1 ;
    uint8_t digital_flag :1 ;
    uint8_t :2 ;
} Flags;

Flags flags;

//typedef union _Nibbles{
//    struct{
//        uint8_t  high:4;
//        uint8_t  low:4;
//    }nibbles;
//    uint8_t byte_nibbles;
//}nibbles_t;

int8_t waitForTL(uint8_t state){
    uint8_t count=0;
    while(PIN_TL != state){
        count++;
        if(count>100){
            return -1;
        }
        __delay_us(1);
    }
    return 1;
}

void readControllerData(){
   
    uint8_t tmp_data;
    
    //1st data
    PIN_S0_TH = 1;
    PIN_S1_TR = 1;
    flags.tr_flag =1;    
    __delay_us(2);    //wait 2us
    tmp_data = READ_PIN()<<4;       // read pin value as high nibble data
//    flags.tl_flag = (high_nibble & 0x10)>>4;
    
    //2nd data
    PIN_S0_TH = 0;
    __delay_us(2);    //wait 2us 
    tmp_data = tmp_data | (0x0f & READ_PIN());   // read pin value as low nibble data
    
    controller_data.val[0] = tmp_data;
    
    //3rd data ~ 16th data
    for(int i=1; i <8 ; i++){
        tmp_data = 0;
        
        PIN_S1_TR = 0;
        flags.tr_flag = 0;
//        WAIT_FOR_TL_PIN(flags.tr_flag)    //wait until TL is low
        if(waitForTL(flags.tr_flag) != 1){
            controller_data.val[i] =0;
            break;
        }        
        __delay_us(2);        
        tmp_data = READ_PIN()<<4;      
        
        PIN_S1_TR = 1;
        flags.tr_flag = 1;
//        WAIT_FOR_TL_PIN(flags.tr_flag)    //wait until TL is high
        if(waitForTL(flags.tr_flag) != 1){
            controller_data.val[i] =0;
            break;
        }                    
        __delay_us(2);        
        tmp_data = tmp_data | (0x0f & READ_PIN());     
        
        controller_data.val[i] = tmp_data;
    }

    //wait 4us     
    __delay_us(4);
    
    //END Request
    PIN_S0_TH = 1;
    PIN_S1_TR = 1;   

    //wait 4us 
    __delay_us(4);
    
    return;
    
}



void App_DeviceGamepadInit(void){
    flags.crosskey_flag = 0;
    flags.sw_flag = false;    
    flags.digital_flag = false;
}

void App_DeviceGamepadAct(INPUT_CONTROLS* gamepad_input){

    readControllerData();
    
    // digital mode when data size = 2 
    if(controller_data.members.info.size == 2){
        flags.digital_flag = true;
    } else{
        flags.digital_flag = false;
    }
        
    //buttons
    gamepad_input->members.buttons.start = !controller_data.members.buttons.start;        
    gamepad_input->members.buttons.a = !controller_data.members.buttons.a;
    gamepad_input->members.buttons.b = !controller_data.members.buttons.b;
    gamepad_input->members.buttons.c = !controller_data.members.buttons.c;
    gamepad_input->members.buttons.x = !controller_data.members.buttons.x;
    gamepad_input->members.buttons.y = !controller_data.members.buttons.y;
    gamepad_input->members.buttons.z = !controller_data.members.buttons.z;



    gamepad_input->members.buttons.L2 = 0;
    gamepad_input->members.buttons.R2 = 0;
    gamepad_input->members.buttons.left_stick = 0;
    gamepad_input->members.buttons.right_stick = 0;
    gamepad_input->members.buttons.home = 0;
        

    //hat switch
    if(!controller_data.members.buttons.up){
        if(!controller_data.members.buttons.right){
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_NORTH_EAST;
        } else if(!controller_data.members.buttons.left){
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_NORTH_WEST;
        } else{
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_NORTH;
        }
    }  else if(!controller_data.members.buttons.down){
        if(!controller_data.members.buttons.right){
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_SOUTH_EAST;
        }else if(!controller_data.members.buttons.left){
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_SOUTH_WEST;
        }else{
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_SOUTH;
        }
    } else{
        if(!controller_data.members.buttons.right){
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_EAST;
        } else if(!controller_data.members.buttons.left){
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_WEST;
        } else{
            gamepad_input->members.hat_switch.hat_switch = HAT_SWITCH_NULL;
        }
    }
    



    if(flags.digital_flag){
        // L R button
        gamepad_input->members.buttons.L1 = !controller_data.members.buttons.l;
        gamepad_input->members.buttons.R1 = !controller_data.members.buttons.r;
        
        //xy axis
        gamepad_input->val[3] = 0x80;
        gamepad_input->val[4] = 0x80;
        
        //z axis and rz axis 
        gamepad_input->val[5] = 0x00;
        gamepad_input->val[6] = 0x00;          
    }else{
        // L R button
        gamepad_input->members.buttons.L1 = 0;
        gamepad_input->members.buttons.R1 = 0;   
     
        //xy axis
        gamepad_input->val[3] = controller_data.members.sticks.X;
        gamepad_input->val[4] = controller_data.members.sticks.Y;
   
        //z axis and rz axis 
        gamepad_input->val[5] = controller_data.members.trigers.LT;
        gamepad_input->val[6] = controller_data.members.trigers.RT;            
    }
    
    
    return;

}




#endif	/* MY_APP_DEVICE_GAMEPAD_C */