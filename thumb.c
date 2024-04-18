#include "xc.h"
#include <stdio.h>    // for sprintf
#include "lcd.h"

#define BUFSIZE 128



int adc_thumbBuffer[BUFSIZE];
int buffindxThumb=0;
long int thumb_avg;


//init sensor buffer to buffsize
void initThumbBuffer() {
    for(int i=0; i<BUFSIZE; i++) {
        adc_thumbBuffer[i]=0;
    }
}

//place ADC value into sensor buffer 
void putThumbVal(int ADCvalue) {
    adc_thumbBuffer[buffindxThumb++]=ADCvalue;
    if(buffindxThumb>=BUFSIZE) {
        buffindxThumb=0;
    }
}

//gets average of values in buffer and returns the value 
long int getThumbAvg() {
    thumb_avg=0;
    for(int j=0; j<BUFSIZE; j++) {
        thumb_avg += adc_thumbBuffer[j];
    }
    thumb_avg /= BUFSIZE;
    return thumb_avg;
}





