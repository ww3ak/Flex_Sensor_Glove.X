#include "xc.h"
#include <stdio.h>    // for sprintf
#include "lcd.h"

#define BUFSIZE 128



int adc_middleBuffer[BUFSIZE];
int buffindxMiddle=0;
long int middle_avg;

//init sensor buffer to buffsize
void initMiddleBuffer() {
    for(int i=0; i<BUFSIZE; i++) {
        adc_middleBuffer[i]=0;
    }
}
//place ADC value into sensor buffer 
void putMiddleVal(int ADCvalue) {
    adc_middleBuffer[buffindxMiddle++]=ADCvalue;
    if(buffindxMiddle>=BUFSIZE) {
        buffindxMiddle=0;
    }
}
//gets average of values in buffer and returns the value 
long int getMiddleAvg() {
    middle_avg=0;
    for(int j=0; j<BUFSIZE; j++) {
        middle_avg += adc_middleBuffer[j];
    }
    middle_avg /= BUFSIZE;
    return middle_avg;
}




