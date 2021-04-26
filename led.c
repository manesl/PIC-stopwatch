/*
 * File:   led.c
 * Author: mane2
 *
 * Created on April 23, 2021, 5:55 PM
 */

/******************************************************************************
 * Software License Agreement
 *
 * Copyright � 2011 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED ìAS ISî WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *****************************************************************************/


#if defined(__PIC24E__) 
#include <p24Exxxx.h>
#include "led.h"
#elif defined (__PIC24F__) 
#include <p24Fxxxx.h>

#elif defined(__PIC24H__)
#include <p24Hxxxx.h>

#elif defined(__dsPIC30F__)
#include <p30Fxxxx.h>

#elif defined (__dsPIC33E__) 
#include <p33Exxxx.h>

#elif defined(__dsPIC33F__) 
#include <p33Fxxxx.h>

#endif


void setLEDBar(int16_t pattern){
    LED0 = (pattern & 0x001)==0x001 ? 1 : 0;
    LED1 = (pattern & 0x002)==0x002 ? 1 : 0;
    LED2 = (pattern & 0x004)==0x004 ? 1 : 0;
    LED3 = (pattern & 0x008)==0x008 ? 1 : 0;
    LED4 = (pattern & 0x010)==0x010 ? 1 : 0;
    LED5 = (pattern & 0x020)==0x020 ? 1 : 0;
    LED6 = (pattern & 0x040)==0x040 ? 1 : 0;
    LED7 = (pattern & 0x080)==0x080 ? 1 : 0;
    LED8 = (pattern & 0x100)==0x100 ? 1 : 0;
    LED9 = (pattern & 0x200)==0x200 ? 1 : 0;  
}




