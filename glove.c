void initFlex (void) {
    // Set RA0 to RA4 as digital
    AD1PCFGbits.PCFG0 = 1; // Set RA0 as digital
    AD1PCFGbits.PCFG1 = 1; // Set RA1 as digital
    AD1PCFGbits.PCFG2 = 1; // Set RA2 as digital
    AD1PCFGbits.PCFG3 = 1; // Set RA3 as digital
    AD1PCFGbits.PCFG4 = 1; // Set RA4 as digital

    //Configure RA0 to RA4 as inputs
    TRISAbits.TRISA0 = 1; // Set RA0 as input
    TRISAbits.TRISA1 = 1; // Set RA1 as input
    TRISAbits.TRISA2 = 1; // Set RA2 as input
    TRISAbits.TRISA3 = 1; // Set RA3 as input
    TRISAbits.TRISA4 = 1; // Set RA4 as input
    
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
