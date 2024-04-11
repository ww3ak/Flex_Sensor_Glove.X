#include "xc.h"
#include <stdio.h>    // for sprintf
#include "lcd.h"
#include "display.h"

#define BUFSIZE 128


int adc_pinkieBuffer[BUFSIZE];
int buffindxPinkie=0;
long int pinkie_avg;


void initPinkieBuffer() {
    for(int i=0; i<BUFSIZE; i++) {
        adc_pinkieBuffer[i]=0;
    }
}
void putPinkieVal(int ADCvalue) {
    adc_pinkieBuffer[buffindxPinkie++]=ADCvalue;
    if(buffindxPinkie>=BUFSIZE) {
        buffindxPinkie=0;
    }
}

long int getPinkieAvg() {
    pinkie_avg=0;
    for(int j=0; j<BUFSIZE; j++) {
        pinkie_avg += adc_pinkieBuffer[j];
    }
    pinkie_avg /= BUFSIZE;
    return pinkie_avg;
}





