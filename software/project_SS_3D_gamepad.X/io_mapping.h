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

#include "system.h"


#define PIN_DET         PORTAbits.RA3
#define PIN_TL          PORTAbits.RA4
#define TACTSW          PORTAbits.RA5
#define PIN_D0_UP       PORTBbits.RB6
#define PIN_D1_DOWN     PORTBbits.RB7
#define PIN_D2_LEFT     PORTBbits.RB5
#define PIN_D3_RIGHT    PORTBbits.RB4

#define PIN_S0_TH       LATCbits.LATC3
#define PIN_S1_TR       LATCbits.LATC4