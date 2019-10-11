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
    enum states {ON, OFF} state;
    DDRA = 0x00; PORTA = 0xFF; //input
    DDRB = 0xFF; PORTB = 0x00; //output
    state = START;
    
    /* Insert your solution below */
    while (1) {
        state = START;
        
        switch(state) { //transitions
            case START:
                state = ON;
                break;
                
            case ON:
                if ((PINA & 0x01) == 1) {
                    state = OFF;
                }
                else {
                    state = ON;
                }
                break;
        
        case OFF:
                if(((PINA & 0x01) == 1) {
                    state = ON;
                }
                else {
                    state = OFF;
                }
                break;
                   
        switch(state) { //actions
            case START:
            break;
            
            case ON:
            PORTB = 0x01;
            break;
            
            case ON:
            PORTB = 0x02;
            break;
    }
    return 1;
}
