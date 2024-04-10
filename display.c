
#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "lcd.h"

// Define the pins for your dual seven segment display
#define SEG_A_LAT   LATBbits.LATB15
#define SEG_B_LAT   LATBbits.LATB14
#define SEG_C_LAT   LATBbits.LATB13
#define SEG_D_LAT   LATBbits.LATB12
#define SEG_E_LAT   LATBbits.LATB11
#define SEG_F_LAT   LATBbits.LATB10
#define SEG_G_LAT   LATBbits.LATB9


// 7 Segment Display initialization
void init7seg (void) {
//    RB<15:9>
//    RB<9:2> will drive the cathodes of the seven-segment display. 
//    RB<11:10> will drive the right and left anodes respectively
    
    AD1PCFG = 0x9fff;                 //Set all pins to digital mode      
    TRISB = 0b0000000000000011;  //and port B to outputs
    
    // Set display segment pins as outputs
    SEG_A_LAT = 1;
    SEG_B_LAT = 1;
    SEG_C_LAT = 1;
    SEG_D_LAT = 1;
    SEG_E_LAT = 1;
    SEG_F_LAT = 1;
    SEG_G_LAT = 1;

}

void showChar7seg(char myChar) {
    //where myChar is the character being displayed
    
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
        case 'A':
            SEG_A_LAT = 0;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 1;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
        case 'B':
            SEG_A_LAT = 1;
            SEG_B_LAT = 1;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
        case 'C':
            SEG_A_LAT = 0;
            SEG_B_LAT = 1;
            SEG_C_LAT = 1;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 1;
            break;
        case 'D':
            SEG_A_LAT = 1;
            SEG_B_LAT = 0;
            SEG_C_LAT = 0;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 1;
            SEG_G_LAT = 0;
            break;
        case 'E':
            SEG_A_LAT = 0;
            SEG_B_LAT = 1;
            SEG_C_LAT = 1;
            SEG_D_LAT = 0;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
        case 'F':
            SEG_A_LAT = 0;
            SEG_B_LAT = 1;
            SEG_C_LAT = 1;
            SEG_D_LAT = 1;
            SEG_E_LAT = 0;
            SEG_F_LAT = 0;
            SEG_G_LAT = 0;
            break;
            
        case 'N':
            SEG_A_LAT = 1;
            SEG_B_LAT = 1;
            SEG_C_LAT = 1;
            SEG_D_LAT = 1;
            SEG_E_LAT = 1;
            SEG_F_LAT = 1;
            SEG_G_LAT = 1;
            break;
    }
}
