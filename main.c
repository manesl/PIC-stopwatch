/*
 * File:   main.c
 * Author: mane2
 *
 * Created on April 25, 2021, 4:05 PM
 */

/******************************************************************************
 * Software License Agreement
 *
 * Copyright © 2011 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED Ã¬AS ISÃ® WITHOUT WARRANTY OF ANY
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
#include <stdbool.h>

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
// Tactile Switch pin definitions
#define SW2 _RD7
#define SW1 _RD13
//	Function Prototypes
void timerInit(void);
bool switchPressed(void);

int dSec = 0;
int sec = 0;
int min = 0;
uint16_t pressed = 0;

int main(void) {
    //LED setup
    //init control registers
    TRISF = 0x0000;
    TRISD = 0x0000;
    //switch
    ANSELD = 0x00;//digital values
    _TRISD7 = 0x1;
    _TRISD13 = 0x1;//input
    SW1 = 1; //RD13
    SW2 = 1; //RD7
    while(!switchPressed());
    //timer1 setup
    timerInit();
    while (!switchPressed()){
        setLEDBar(sec);
    }
    return 0;
}

bool switchPressed(void){
    if(SW2==0 || SW1==0){
            pressed++;
        }
    if(pressed>37260){
        pressed=0;
        return true;
    }
    return false;
}

void timerInit(void){
    _T1IP = 4;
    TMR1 = 0;
    PR1 = 5760-1;
    T1CON = 0x8020; //enabled, prescaler 1:64, internal clock
    _T1IF = 0;
    _T1IE = 1;
}

void _ISR _T1Interrupt (void){
    dSec++;
    if(dSec > 9){
        dSec = 0;
        sec++;
        if(sec > 59){
            sec = 0;
            min++;
            if(min > 59){
                min = 0;
            }
        }
    }
    _T1IF = 0;
}


