
#include "xc.h"
#include <stdio.h>    // for sprintf
#include "lcd.h"

#define BUFSIZE 128



int adc_ringBuffer[BUFSIZE];
int buffindxRing=0;
long int ring_avg;


void initRingBuffer() {
    for(int i=0; i<BUFSIZE; i++) {
        adc_ringBuffer[i]=0;
    }
}
void putRingVal(int ADCvalue) {
    adc_ringBuffer[buffindxRing++]=ADCvalue;
    if(buffindxRing>=BUFSIZE) {
        buffindxRing=0;
    }
}

long int getRingAvg() {
    ring_avg=0;
    for(int j=0; j<BUFSIZE; j++) {
        ring_avg += adc_ringBuffer[j];
    }
    ring_avg /= BUFSIZE;
    return ring_avg;
}




