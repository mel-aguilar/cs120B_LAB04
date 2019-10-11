/*	Author: magui051
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    enum states {INIT, PRESSED, BUTTON1, BUTTON2,WAIT} state;
    DDRA = 0x00; PORTA = 0xFF; //input
    DDRB = 0xFF; PORTB = 0x00; //output
    state = INIT;
    
    /* Insert your solution below */
    while (1) {
        //state = INIT;
        
        switch(state) { //transitions
            case INIT:
                state = PRESSED;
                break;
                
            case PRESSED:
                if ((PINA & 0x01) == 1) {
                    state = BUTTON1;
                }
                else {
                    state = PRESSED;
                }
                break;
        
            case BUTTON1:
                if((PINA & 0x01) == 0) {
                    state = WAIT;
                }
                else {
                    state = BUTTON1;
                }
                break;
                
            case WAIT:
                if((PINA & 0x01) == 1) {
                    state = BUTTON2;
                }
                else {
                    state = WAIT;
                }
                break;
                
            case BUTTON2:
                if((PINA & 0x01) == 0) {
                    state = PRESSED;
                }
                else {
                    state = BUTTON2;
                }
                break;
        }     
        switch(state) { //actions
            case INIT:
                PORTB = 0x01;
                break;
            
            case PRESSED:
                break;
            
            case BUTTON1:
                PORTB = 0x02;
                break;
                
            case WAIT:
                //PORTB = 0x01;
                break;
                
            case BUTTON2:
                PORTB = 0x01;
                break;
        }
    }
    return 1;
}
