#include "xc.h"
#include <stdio.h>    // for sprintf
#include "lcd.h"
#include "display.h"

#define BUFSIZE 128



int adc_middleBuffer[BUFSIZE];
int buffindxMiddle=0;
long int middle_avg;


void initMiddleBuffer() {
    for(int i=0; i<BUFSIZE; i++) {
        adc_middleBuffer[i]=0;
    }
}
void putMiddleVal(int ADCvalue) {
    adc_middleBuffer[buffindxMiddle++]=ADCvalue;
    if(buffindxMiddle>=BUFSIZE) {
        buffindxMiddle=0;
    }
}

long int getMiddleAvg() {
    middle_avg=0;
    for(int j=0; j<BUFSIZE; j++) {
        middle_avg += adc_middleBuffer[j];
    }
    middle_avg /= BUFSIZE;
    return middle_avg;
}




