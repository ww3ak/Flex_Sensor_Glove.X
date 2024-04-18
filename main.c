#include "xc.h"
#include <stdio.h>
#include "lcd.h"
#include "thumb.h"
#include "pointer.h"
#include "middle.h"
#include "ring.h"
#include "pinkie.h"
#include "input_read.h"
#define NUMSAMPLES 256

// PIC24FJ64GA002 Configuration Bit Settings
// CW1: FLASH CONFIGURATION WORD 1 (see PIC24 Family Reference Manual 24.1)
#pragma config ICS = PGx1
#pragma config FWDTEN = OFF        // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config GWRP = OFF          // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF           // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF        // JTAG Port Enable (JTAG port is disabled)
// CW2: FLASH CONFIGURATION WORD 2 (see PIC24 Family Reference Manual 24.1)
#pragma config I2C1SEL = PRI       // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF       // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = ON       // Primary Oscillator I/O Function (CLKO/RC15 functions as I/O pin)
#pragma config FCKSM = CSECME      // Clock Switching and Monitor (Clock switching is enabled, 
                                       // Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = FRCPLL      // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))

/*
 This file acts as the main file for this project. It initializes all necessary peripherals like the
 * pic24 micro itself, the ADC portion of the pic, as well as the LCD screen. 
 * After its init funcions, it calls each sensor buffer init function as well and runs a while loop
 * which continuously updates the hand character which is displayed on the display. 
 */


void pic24_init() {
    _RCDIV=0; //set internal clock to 16MHz
    AD1PCFG=0xFFFF; //set all pins digital
}

void adc_init() {
   TRISAbits.TRISA0=1; //A0 THUMB
   TRISBbits.TRISB9=1; //A9 POINTER
   TRISBbits.TRISB10=1; //A10 MIDDLE
   TRISBbits.TRISB11=1; //A11 RING
   TRISBbits.TRISB12=1; //A12 PINKIE

          
//read the input as analog input for each pin 
   AD1PCFGbits.PCFG0=0; 
   AD1PCFGbits.PCFG9=0; 
   AD1PCFGbits.PCFG10=0; 
   AD1PCFGbits.PCFG11=0; 
   AD1PCFGbits.PCFG12=0; 

   AD1CON2bits.VCFG=0b000; //use 3.3V and 0V as power and ground
   AD1CON3bits.ADCS= 0b00000001; //TAD=Tcy*2, (Tcy = 62.5 ns), TAD>=75ns
   AD1CON1bits.SSRC= 0b010; //sample on TMR3 events
   AD1CON3bits.SAMC= 0b00001; //you want at least 1 auto sample time bit, this is 1 TAD
   AD1CON1bits.FORM= 0b00; //data output form, of form unsigned int
                          //unsigned: 0V=0b0000000000, 3.3V=0b1111111111
   AD1CON1bits.ASAM= 1; //begin sampling immediately after last conversion, samp bit set automatically 
   AD1CON2bits.SMPI= 0b0101; //interrupts after THE 5TH SAMPLING
    
    AD1CHS = 0x0000; // Initial channel selected to AN0
    
    
    AD1CON1bits.ADON=1; //turn on the ADC
    AD1CON2bits.ALTS = 0; //ALWAYS USES MUX A
    AD1CON2bits.CSCNA = 1;// USES CSSL CHANNELS FOR MUX A

    AD1CHSbits.CH0NA = 0;//Channel 0 negative input is AN1
   
    AD1CSSLbits.CSSL0 = 1;    // scan for A0
    AD1CSSLbits.CSSL9 = 1;   // scan for A9
    AD1CSSLbits.CSSL10 = 1;   //scan for A10
    AD1CSSLbits.CSSL11 = 1;   //scan for A11
    AD1CSSLbits.CSSL12 = 1;   //scan for A12
   
   _AD1IF=0; //clear interrupt flags
   _AD1IE=1; //enable interrupts
   
   TMR3=0; //start counting from 0
   T3CON=0; //clear TMR3 register
   T3CONbits.TCKPS=0b1000; //1:8 pre-scalar
   PR3=250000/NUMSAMPLES-1;
   T3CONbits.TON=1; //enable timer 3
}
void __attribute__((interrupt,auto_psv)) _ADC1Interrupt(void) {
    _AD1IF=0; //clear interrupt flags
    
    //store buffer register values in variables 
    int adThumbValue = ADC1BUF0;
    int adPointerValue = ADC1BUF1;
    int adMiddleValue = ADC1BUF2;
    int adRingValue = ADC1BUF3;
    int adPinkieValue = ADC1BUF4;

    //place the stored values into sensor buffers 
    putThumbVal(adThumbValue);
    putPointVal(adPointerValue);
    putMiddleVal(adMiddleValue);
    putRingVal(adRingValue);
    putPinkieVal(adPinkieValue);

}

int main(void) {
    pic24_init();
    lcd_init();
   
    //initialize individual buffer sensors 
    initThumbBuffer();
    initPointBuffer();
    initMiddleBuffer();
    initRingBuffer();
    initPinkieBuffer();
    
    adc_init();
    char myChar;
    
    char adStrPoint[20];

        while(1) {
        lcd_setCursor(0,0);
        myChar = readChar();
        lcd_printChar(myChar);
//        long int avgPoint = getPointAvg();
//
//        sprintf(adStrPoint, "%6.4ld",avgPoint);
//        lcd_printStr(adStrPoint);
//        lcd_setCursor(0,1);
//        lcd_printStr(adStrPoint);

//        lcd_printStr(adStr);
//        if (avgPoint >= 700) {
//            lcd_setCursor(0,1);
//            lcd_printStr("Bent  ");
//        }else{
//            lcd_setCursor(0,1);
//            lcd_printStr("Unbent");
//        }
        delay_ms(100);
    }
        
    return 0;
    
}
