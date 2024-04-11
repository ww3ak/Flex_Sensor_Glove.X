//
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
//    TRISB = 0b0000000000000011;  //and port B to outputs
//    LATB = 0x0000;
    
    TRISA = 0b0000000000011111; //set port A to inputs, 
    TRISB = 0b0000000000000011; //and port B to outputs
    LATA = 0x0000; //Set all of port A to LOW
    LATB = 0x0000; //and all of port B to LOW
    
    
    // Set display segment pins as outputs
    SEG_A_LAT = 1;
    SEG_B_LAT = 1;
    SEG_C_LAT = 1;
    SEG_D_LAT = 1;
    SEG_E_LAT = 1;
    SEG_F_LAT = 1;
    SEG_G_LAT = 1;

}


void setSegment(char segments) {
    // Set each segment according to the segments bitfield
    SEG_A_LAT = (segments & 0x40) ? 1 : 0;
    SEG_B_LAT = (segments & 0x20) ? 1 : 0;
    SEG_C_LAT = (segments & 0x10) ? 1 : 0;
    SEG_D_LAT = (segments & 0x08) ? 1 : 0;
    SEG_E_LAT = (segments & 0x04) ? 1 : 0;
    SEG_F_LAT = (segments & 0x02) ? 1 : 0;
    SEG_G_LAT = (segments & 0x01) ? 1 : 0;
}

void showChar7seg(char myChar) {
    //where myChar is the character being displayed
    LATB&=0xF000;
    // Set segments based on character
    switch (myChar) {
        case '0': setSegment(0x7E); break; // ABCDEF
        case '1': setSegment(0x30); break; // BC
        case '2': setSegment(0x6D); break; // ABDEG
        case '3': setSegment(0x79); break; // ABCDG
        case '4': setSegment(0x33); break; // BCFG
        case '5': setSegment(0x5B); break; // ACDFG
        case '6': setSegment(0x5F); break; // ACDEFG
        case '7': setSegment(0x70); break; // ABC
        case '8': setSegment(0x7F); break; // ABCDEFG
        case '9': setSegment(0x7B); break; // ABCDFG
    }
//        case '0':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 1;
//            break;
//        case '1':
//            SEG_A_LAT = 1;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 1;
//            SEG_E_LAT = 1;
//            SEG_F_LAT = 1;
//            SEG_G_LAT = 1;
//            break;
//        case '2':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 1;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 1;
//            SEG_G_LAT = 0;
//            break;
//        case '3':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 1;
//            SEG_F_LAT = 1;
//            SEG_G_LAT = 0;
//            break;
//        case '4':
//            SEG_A_LAT = 1;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 1;
//            SEG_E_LAT = 1;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//        case '5':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 1;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 1;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//        case '6':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 1;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//        case '7':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 1;
//            SEG_E_LAT = 1;
//            SEG_F_LAT = 1;
//            SEG_G_LAT = 1;
//            break;
//        case '8':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//        case '9':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 1;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//        case 'A':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 1;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//        case 'B':
//            SEG_A_LAT = 1;
//            SEG_B_LAT = 1;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//        case 'C':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 1;
//            SEG_C_LAT = 1;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 1;
//            break;
//        case 'D':
//            SEG_A_LAT = 1;
//            SEG_B_LAT = 0;
//            SEG_C_LAT = 0;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 1;
//            SEG_G_LAT = 0;
//            break;
//        case 'E':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 1;
//            SEG_C_LAT = 1;
//            SEG_D_LAT = 0;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//        case 'F':
//            SEG_A_LAT = 0;
//            SEG_B_LAT = 1;
//            SEG_C_LAT = 1;
//            SEG_D_LAT = 1;
//            SEG_E_LAT = 0;
//            SEG_F_LAT = 0;
//            SEG_G_LAT = 0;
//            break;
//            
//        case 'N':
//            SEG_A_LAT = 1;
//            SEG_B_LAT = 1;
//            SEG_C_LAT = 1;
//            SEG_D_LAT = 1;
//            SEG_E_LAT = 1;
//            SEG_F_LAT = 1;
//            SEG_G_LAT = 1;
//            break;
//    }
}
//#include "xc.h"
//#include "display.h"
////Functions used for Display
//
//void init7seg(void) {
//    CLKDIVbits.RCDIV = 0; //Set RCDIV=1:1 (default 2:1) 32MHz or FCY/2=16M
//    AD1PCFG = 0x9fff; //sets all pins to digital I/O
//   // TRISA = 0b0000000000011111; //set port A to inputs, 
//    TRISB = 0b0000000000000011; //and port B to outputs
//    //LATA = 0x0000; //Set all of port A to LOW
//    LATB = 0x0000; //and all of port B to LOW
//}
//
//void showChar7seg(char myChar, int myDigit)
//{
//    //1,2,3,4,5,6,7,8,9,0,A,b,C,d,E, and F
//    LATB&=0xF000;
//    if (myDigit==1)
//    {
//        if (myChar=='1'){
//            LATB|=0x067F;
//        }
//        else if (myChar=='2'){
//            LATB|=0x0497;
//        }
//        else if (myChar=='3'){
//            LATB|=0x0437;
//        }
//        else if (myChar=='4'){
//            LATB|=0x0667;
//        }
//        else if (myChar=='5'){
//            LATB|=0x0527;
//        }
//        else if (myChar=='6'){
//            LATB|=0x0507;
//        }
//        else if (myChar=='7'){
//            LATB|=0x047F;
//        }
//        else if (myChar=='8'){
//            LATB|=0x0407;
//        }
//        else if (myChar=='9'){
//            LATB|=0x0427;
//        }
//        else if (myChar=='0'){
//            LATB|=0x040F;
//        }
//        else if (myChar=='A'){
//            LATB|=0x0447;
//        }
//        else if (myChar=='b'){
//            LATB|=0x0707;
//        }
//        else if (myChar=='C'){
//            LATB|=0x058F;
//        }
//        else if (myChar=='d'){
//            LATB|=0x0617;
//        }
//        else if (myChar=='E'){
//            LATB|=0x0587;
//        }
//        else if (myChar=='F'){
//            LATB|=0x05C7;
//        }
//    }
//    else if (myDigit==0)
//    {
//        if (myChar=='1'){
//            LATB|=0x0A7F;
//        }
//        else if (myChar=='2'){
//            LATB|=0x0897;
//        }
//        else if (myChar=='3'){
//            LATB|=0x0837;
//        }
//        else if (myChar=='4'){
//            LATB|=0x0A67;
//        }
//        else if (myChar=='5'){
//            LATB|=0x0927;
//        }
//        else if (myChar=='6'){
//            LATB|=0x0907;
//        }
//        else if (myChar=='7'){
//            LATB|=0x087F;
//        }
//        else if (myChar=='8'){
//            LATB|=0x0807;
//        }
//        else if (myChar=='9'){
//            LATB|=0x0827;
//        }
//        else if (myChar=='0'){
//            LATB|=0x080F;
//        }
//        else if (myChar=='A'){
//            LATB|=0x0847;
//        }
//        else if (myChar=='b'){
//            LATB|=0x0B07;
//        }
//        else if (myChar=='C'){
//            LATB|=0x098F;
//        }
//        else if (myChar=='d'){
//            LATB|=0x0A17;
//        }
//        else if (myChar=='E'){
//            LATB|=0x0987;
//        }
//        else if (myChar=='F'){
//            LATB|=0x09C7;
//        }
//    }
//    return;
//}
