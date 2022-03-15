/*
 * File:   main.c
 * Author: Fabian Sohrmann
 * Email:  mfsohr@utu.fi
 *
 * This code is used to turn on a LED while a button is being pressed.
 * 
 * Created on 28. lokakuuta 2021, 20:23
 */


#include <avr/io.h>

int main(void) {
    PORTF.DIR |= PIN5_bm; // set as output
    PORTF.DIR &= ~PIN6_bm; // set as input
    while (1) {
        if(PORTF.IN & PIN6_bm){ // checks if button pressed
            PORTF.OUT |= PIN5_bm; // button not pressed -> LED off
        }else{
            PORTF.OUT &= ~PIN5_bm;  // button pressed -> LED on
        }
    }
}
