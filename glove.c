#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

void initFlex (void) {
   // Configure ADC module
    AD1PCFG = 0xffff; // Set all pins digital
 
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    TRISAbits.TRISA4 = 1;

    AD1PCFGbits.PCFG0 = 0; // AN0 as analog
    AD1PCFGbits.PCFG1 = 0; // AN1 as analog
    AD1PCFGbits.PCFG2 = 0; // AN2 as analog
    AD1PCFGbits.PCFG3 = 0; // AN3 as analog
    AD1PCFGbits.PCFG4 = 0; // AN4 as analog

    AD1CON2bits.VCFG = 0b000;
    AD1CON3bits.ADCS = 0b00000001;
    AD1CON1bits.SSRC = 0b010;
    AD1CON3bits.SAMC = 0b0001;
    AD1CON1bits.FORM = 0b00;
    
    
    AD1CON1bits.ASAM = 0b01;
    AD1CON2bits.SMPI = 0b0000;
    AD1CON1bits.ADON = 1;
    
    _AD1IF = 0;
    _AD1IE = 1;

    //Finger Integers
    int F1 = 0 //thumb
    int F2 = 0 //pointer
    int F3 = 0 //middle
    int F4 = 0 //ring
    int F5 = 0 //pinky
}

void readFingerRAW(void) {
    //Thumb Reading
    if (PORTAbits.RA0 <= BV) {//BV = bent voltage, place holder
        F1 = 1;
    } else {
        F1 = 0;
    }
    //Pointer Reading
    if (PORTAbits.RA1 <= BV) {//BV = bent voltage, place holder
        F2 = 1;
    } else {
        F2 = 0;
    }
    //Middle Reading
    if (PORTAbits.RA2 <= BV) {//BV = bent voltage, place holder
        F3 = 1;
    } else {
        F3 = 0;
    }
    //Ring Reading
    if (PORTAbits.RA3 <= BV) {//BV = bent voltage, place holder
        F4 = 1;
    } else {
        F4 = 0;
    }
    //Pinky Reading
    if (PORTAbits.RA4 <= BV) {//BV = bent voltage, place holder
        F5 = 1;
    } else {
        F5 = 0;
    }
}

int readInt() {

    readFingerRAW();
   
    int hand;

    if (F1 == 1 && F2 == 1 && F3 == 1 && F4 == 1 && F5 == 1) {
        hand = 0;
    } else if (F1 == 1 && F2 == 0 && F3 == 1 && F4 == 1 && F5 == 1) {
        hand = 1;
    } else if (F1 == 1 && F2 == 0 && F3 == 0 && F4 == 1 && F5 == 1) {
        hand = 2;
    } else if (F1 == 0 && F2 == 0 && F3 == 0 && F4 == 1 && F5 == 1) {
        hand = 3;
    } else if (F1 == 1 && F2 == 0 && F3 == 0 && F4 == 0 && F5 == 0) {
        hand = 4;
    } else if (F1 == 0 && F2 == 0 && F3 == 0 && F4 == 0 && F5 == 0) {
        hand = 5;
    } else if (F1 == 1 && F2 == 0 && F3 == 0 && F4 == 0 && F5 == 1) {
        hand = 6;
    } else if (F1 == 0 && F2 == 1 && F3 == 1 && F4 == 0 && F5 == 1) {
        hand = 7;
    } else if (F1 == 0 && F2 == 1 && F3 == 0 && F4 == 1 && F5 == 1) {
        hand = 8;
    } else if (F1 == 1 && F2 == 1 && F3 == 0 && F4 == 0 && F5 == 0) {
        hand = 9;
    }

    return hand;
}
