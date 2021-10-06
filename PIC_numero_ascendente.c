/*
 * File:   PIC_Parpadeo.c
 * Author: Foxy
 *
 * Created on 30 de septiembre de 2021, 14:26
 */

#include <xc.h>
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HSPLL_HS
#pragma config LVP = OFF
#define _XTAL_FREQ 48000000

//Libreria para el display placa MKBot Trial 3.1
void display(int num){
    LATB = 0b0000000;
    
    if(num == 0){
        LATB = 0b0111111;
    }
    if(num == 1){
        LATB = 0b0000110;
    }
    if(num == 2){
        LATB = 0b1011011;
    }
    if(num == 3){
        LATB = 0b1001111;
    }
    if(num == 4){
        LATB = 0b1100110;
    }
    if(num == 5){
        LATB = 0b1101101;
    }
    if(num == 6){
        LATB = 0b1111101;
    }
    if(num == 7){
        LATB = 0b0000111;
    }
    if(num == 8){
        LATB = 0b1111111;
    }
    if(num == 9){
        LATB = 0b1100111;
    }
    if(num > 9){
        LATB = 0b1110001;
    }
}

void main(void) {
    
    int resultado = 0;
    ADCON1 = 0x0F; //Utilizamos esto para desabilitar los puertos analogicos
    TRISB=0b00000000; //Asignamos salida los puertos B
    TRISAbits.TRISA2 = 1; //Asignamos los puertos A como entrada
    TRISAbits.TRISA3 = 1;
    TRISAbits.TRISA4 = 1;
    TRISAbits.TRISA5 = 1;
    
    while(1){
        
        /* Esto hace un incremento de 0 al 9 cada 600 milisegundos
        for(int num = 0; num <= 9; num++){
            display(num);
            __delay_ms(600);
        }
        */
        
        //Dependiendo de si esta pulsado, sumamos su valor.
        if(PORTAbits.RA5 == 0){
            resultado = resultado + 1;
        }
        if(PORTAbits.RA4 == 0){
            resultado = resultado + 2;
        }
        if(PORTAbits.RA3 == 0){
            resultado = resultado + 4;
        }
        if(PORTAbits.RA2 == 0){
            resultado = resultado + 8;        
        }
        
        //Lo ingresamos en la libreria display y reseteamos el resultado
        display(resultado);
        resultado = 0;
    }
    
}
