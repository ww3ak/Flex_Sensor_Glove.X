
#include "xc.h"
#include <stdio.h>    // for sprintf
#include "lcd.h"

#define BUFSIZE 128



int adc_ringBuffer[BUFSIZE];
int buffindxRing=0;
long int ring_avg;

//init sensor buffer to buffsize
void initRingBuffer() {
    for(int i=0; i<BUFSIZE; i++) {
        adc_ringBuffer[i]=0;
    }
}
//place ADC value into sensor buffer 
void putRingVal(int ADCvalue) {
    adc_ringBuffer[buffindxRing++]=ADCvalue;
    if(buffindxRing>=BUFSIZE) {
        buffindxRing=0;
    }
}
//gets average of values in buffer and returns the value 
long int getRingAvg() {
    ring_avg=0;
    for(int j=0; j<BUFSIZE; j++) {
        ring_avg += adc_ringBuffer[j];
    }
    ring_avg /= BUFSIZE;
    return ring_avg;
}




