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

enum STATES {START,INIT,INCR,RESET,DECR} state;
unsigned char begin = 0x00;

void tick() {
    switch(state) {
        case START:
            state = INIT;
            break;
        case INIT:
            if (PINA == 0) {
                state = RESET;
            } 
            else if (PINA == 1) {
                state = INCR;
            } 
            else if (PINA == 2) {
                state = DECR;
            } 
            else {
                state = INIT;
            }
            break;
        case INCR:
            state = INIT;
            break;
        case RESET:
            state = INIT;
            break;
        case DECR:
            state = INIT;
            break;
    }

    switch(state) {
        case START:
            break;
        case INIT:
            break;
        case INCR:
            if (begin < 9) {
                ++begin;
            }
            break;
        case RESET:
            begin = 0;
            break;
        case DECR:
            if (begin > 0) {
                --begin;
            }
            break;
    }
}

    int main(void) {
        /* Insert DDR and PORT initializations */
    DDRA = 0x00; DDRC = 0xFF; PORTA = 0xFF; PORTC = 0x00;
    state = START;
    begin = 7;
        while (1) {
            tick();
            PORTC = begin;
        }
        return 1;
    }
