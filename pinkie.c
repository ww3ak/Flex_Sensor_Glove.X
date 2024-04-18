#include "xc.h"
#include <stdio.h>    // for sprintf
#include "lcd.h"

#define BUFSIZE 128


int adc_pinkieBuffer[BUFSIZE];
int buffindxPinkie=0;
long int pinkie_avg;

//init sensor buffer to buffsize
void initPinkieBuffer() {
    for(int i=0; i<BUFSIZE; i++) {
        adc_pinkieBuffer[i]=0;
    }
}
//place ADC value into sensor buffer 
void putPinkieVal(int ADCvalue) {
    adc_pinkieBuffer[buffindxPinkie++]=ADCvalue;
    if(buffindxPinkie>=BUFSIZE) {
        buffindxPinkie=0;
    }
}
//gets average of values in buffer and returns the value 
long int getPinkieAvg() {
    pinkie_avg=0;
    for(int j=0; j<BUFSIZE; j++) {
        pinkie_avg += adc_pinkieBuffer[j];
    }
    pinkie_avg /= BUFSIZE;
    return pinkie_avg;
}





