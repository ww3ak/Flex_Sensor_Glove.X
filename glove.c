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
}
