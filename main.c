/*
 * File:   main.c
 * Author: mane2
 *
 * Created on April 25, 2021, 4:05 PM
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

//	Function Prototypes
//int main(void);
//void systemClockInit(void);
void timerInit(void);
//int a = 0; //to verify that ISR is entered

//_FOSCSEL(FNOSC_FRC & IESO_OFF); //internal FRC 7.37Mhz, and startup oscillator is selected by user
//_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE); //clock switching is enabled, OSC2 pin is clock output, primary osc is disabled
//global variables
int dSec = 0;
int sec = 0;
int min = 0;

int main(void) {
    //clock FRC with PLL Fcy=60Mhz and Fosc=120Mhz
    //systemClockInit();
    //LED setup
    //init control registers
    TRISF = 0x0000;
    TRISD = 0x0000;
    //timer1 setup
    timerInit();
    while (1){
        setLEDBar(sec);
    }
    return 0;
}

/*void systemClockInit(){
    PLLFBD = 63; //M=65 PLLDIV=M-2=65-2
    CLKDIVbits.PLLPRE = 0;//N1=2 PLLPRE=N1-2=2-2=0 //or input is divided by 2
    CLKDIVbits.PLLPOST = 0;//input is divided by 2; N2=2
    
    //initiate the clock switch to FRC osc with PLL
    __builtin_write_OSCCONH(0x01);//selecting FRC with PLL
    __builtin_write_OSCCONL(OSCCON | 0x01);//Requesting for switch
    
    while(OSCCONbits.COSC!=0b001);//wait for clock switch to occur
    while(OSCCONbits.LOCK!=1);//wait for PLL to lock
    
}*/
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




