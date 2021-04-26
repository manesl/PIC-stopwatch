/* 
 * File:   led.h
 * Author: mane2
 *
 * Created on April 23, 2021, 5:55 PM
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif


#define LED0 _LATF0
#define LED1 _LATF1
#define LED2 _LATF2
#define LED3 _LATF4
#define LED4 _LATF5

#define LED5 _LATD8
#define LED6 _LATD9
#define LED7 _LATD10
#define LED8 _LATD11
#define LED9 _LATD12
    
void setLEDBar(int16_t pattern);


#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

