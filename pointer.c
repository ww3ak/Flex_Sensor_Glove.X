#include "xc.h"
#include <stdio.h>    // for sprintf
#include "lcd.h"
#include "display.h"

#define BUFSIZE 128



int adc_pointerBuffer[BUFSIZE];
int buffindxPointer=0;
long int point_avg;


void initPointBuffer() {
    for(int i=0; i<BUFSIZE; i++) {
        adc_pointerBuffer[i]=0;
    }
}
void putPointVal(int ADCvalue) {
    adc_pointerBuffer[buffindxPointer++]=ADCvalue;
    if(buffindxPointer>=BUFSIZE) {
        buffindxPointer=0;
    }
}

long int getPointAvg() {
    point_avg=0;
    for(int j=0; j<BUFSIZE; j++) {
        point_avg += adc_pointerBuffer[j];
    }
    point_avg /= BUFSIZE;
    return point_avg;
}




