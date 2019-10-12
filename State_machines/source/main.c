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

 enum STATES {START,INIT,FIRST,SECOND,THIRD,OPEN} state;

    void tick(){
        
    switch(state) {
    case START:
    state = INIT;
    break;
            
        case INIT:
            if( PINA == 1){
                state = FIRST;
            }
            else{
                state = INIT;
            }
           break;
            
        case FIRST:
          if(PINA == 1){
              state= FIRST;
          }
            else if(PINA == 0){
                state = SECOND;
            }
            else{
                state = INIT;
            }
            break;
            
        case SECOND:
            if (PINA == 0){
                state = SECOND;
            }
            else if(PINA == 2){
                state = THIRD;
            }
            else {
                state = INIT;
            }
            break;
            
        case THIRD:
            if (PINA == 2){
                state = THIRD;
            }
            else if (PINA == 0){
                state = OPEN;
            }
            else{
                state = INIT;
            }
            break;
            
        case OPEN:
            if (PINA == 0x80){
                state= INIT;
            }
            else{
                state = OPEN;
            }
            break;
    }
        
    switch(state) {
        case START:
            break;
            
        case INIT:
            PORTB = 0x00;
            break;
    
        case FIRST:
            break;
            
        case SECOND:
            break;
            
        case THIRD:
            break;
            
        case OPEN:
            PORTB = 0x01;
            break; 
    }
}    
int main(void) {
    /* Insert DDR and PORT initializations */
DDRA= 0xFF; PORTA=0x00;
DDRB= 0x00; PORTB = 0xFF;
    
    /* Insert your solution below */    
    while (1) {
            tick();
    }
    return 1;
}
