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

/* 
 * File:   my_app_device_gamepad.h
 * Author: takusan
 */

#ifndef MY_APP_DEVICE_GAMEPAD_H
#define	MY_APP_DEVICE_GAMEPAD_H


#include "app_device_joystick.h"

void App_DeviceGamepadInit(void);
void App_DeviceGamepadAct(INPUT_CONTROLS* gamepad_input);
void ChangeSWMode_Button_Start(void);
void ChangeSWMode_Button_Select(void);

#endif	/* MY_APP_DEVICE_GAMEPAD_H */

