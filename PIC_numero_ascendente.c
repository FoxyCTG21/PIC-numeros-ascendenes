/*
 * File:   PIC_Parpadeo.c
 * Author: Usuario
 *
 * Created on 30 de septiembre de 2021, 14:26
 */
#include <xc.h>
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HSPLL_HS
#pragma config LVP = OFF
#define _XTAL_FREQ 48000000

void display(int num){
    LATB = 0b0000000;
    
    if(num == 0){
        LATB = 0b0111111;
    }
}

void main(void) {
    
    TRISB=0b00000000;
    
    display(0);
    
}
