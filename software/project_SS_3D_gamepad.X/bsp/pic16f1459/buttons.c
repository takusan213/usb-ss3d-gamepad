/********************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC(R) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *******************************************************************/

/*********************************************************************
 * This file is modified by Geeky Fab.
 * 
 * Changes from the original source:
 *     - deleted unused definitions and functions
 *     - bool BUTTON_IsPressed(BUTTON button)
 ********************************************************************/

#include <xc.h>
#include <stdbool.h>
#include <buttons.h>

/*** Button Definitions *********************************************/
#define BUTTON_PRESSED      0
#define BUTTON_NOT_PRESSED  1


/*********************************************************************
* Function: bool BUTTON_IsPressed(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
********************************************************************/
bool BUTTON_IsPressed(BUTTON button)
{
    return ( (button == BUTTON_PRESSED) ? true : false);
}

