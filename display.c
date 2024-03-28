#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define SEG_A_LAT   LATBbits.LATB8
#define SEG_B_LAT   LATBbits.LATB7
#define SEG_C_LAT   LATBbits.LATB6
#define SEG_D_LAT   LATBbits.LATB5
#define SEG_E_LAT   LATBbits.LATB4
#define SEG_F_LAT   LATBbits.LATB3
#define SEG_G_LAT   LATBbits.LATB2

#define DIGIT1_LAT  LATBbits.LATB9

void init7seg (void) {
//    RB<8:2> will drive the cathodes of the seven-segment display. 
//    RB<9> will drive the right and left anodes respectively
    
    TRISB = 0b0000000000000011;  //and port B to outputs

    // Set display segment pins as outputs
    SEG_A_LAT = 1;
    SEG_B_LAT = 1;
    SEG_C_LAT = 1;
    SEG_D_LAT = 1;
    SEG_E_LAT = 1;
    SEG_F_LAT = 1;
    SEG_G_LAT = 1;
    
    // Set display digit pins as outputs
    DIGIT1_LAT = 0;
}

void showChar7seg(char myChar) {
    //where myChar is the character being displayed

        DIGIT1_LAT = 1; // Enable left digit

    // Set segments based on character
    switch (myChar) {
        case '0':
            SEG_A_LAT = 0;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 1;
            break;
        case '1':
            SEG_A_LAT = 1;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 1;
            SEG_E_LAT = 1;
            SEG_F_LAT = 1;
            SEG_G_LAT = 1;
            break;
        case '2':
            SEG_A_LAT = 0;
            SEG_B_LAT = 0;
            SEG_C_LAT = 1;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 1;
            SEG_G_LAT = 0;
            break;
        case '3':
            SEG_A_LAT = 0;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 1;
            SEG_F_LAT = 1;
            SEG_G_LAT = 0;
            break;
        case '4':
            SEG_A_LAT = 1;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 1;
            SEG_E_LAT = 1;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
        case '5':
            SEG_A_LAT = 0;
            SEG_B_LAT = 1;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 1;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
        case '6':
            SEG_A_LAT = 0;
            SEG_B_LAT = 1;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
        case '7':
            SEG_A_LAT = 0;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 1;
            SEG_E_LAT = 1;
            SEG_F_LAT = 1;
            SEG_G_LAT = 1;
            break;
        case '8':
            SEG_A_LAT = 0;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
        case '9':
            SEG_A_LAT = 0;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 1;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
        case 'U': //Undefined
            SEG_A_LAT = 1;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 1;
            break;
    }
}
