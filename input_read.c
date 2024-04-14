#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

int F1 = 0; //thumb
int F2 = 0; //pointer
int F3 = 0; //middle
int F4 = 0; //ring
int F5 = 0; //pinky

long int avgThumb = 0;
long int avgPoint = 0;
long int avgMiddle = 0;
long int avgRing = 0;
long int avgPinkie = 0;

void readFingerRAW(void) {
    // Get AVG values from ADC Buffers
    avgThumb = getThumbAvg();
    avgPoint = getPointAvg();
    avgMiddle = getMiddleAvg();
    avgRing = getRingAvg();
    avgPinkie = getPinkieAvg();
    

    //Thumb Reading
    if (avgThumb >= 480) {//FS 27
        F1 = 1;
    } else {
        F1 = 0;
    }
    //Pointer Reading
    if (avgPoint >= 550) {//FS 53
        F2 = 1;
    } else {
        F2 = 0;
    }
    //Middle Reading
    if (avgMiddle >= 820) {//FS 42
        F3 = 1;
    } else {
        F3 = 0;
    }
    //Ring Reading
    if (avgRing >= 700) {//FS 33
        F4 = 1;
    } else {
        F4 = 0;
    }
    //Pinky Reading
    if (avgPinkie >= 750) {//FS 4
        F5 = 1;
    } else {
        F5 = 0;
    }
}

char readChar() {
    
    readFingerRAW();
    
    char hand;

    if (F1 == 1 && F2 == 1 && F3 == 1 && F4 == 1 && F5 == 1) {
        hand = '0';
    } else if (F1 == 1 && F2 == 0 && F3 == 1 && F4 == 1 && F5 == 1) {
        hand = '1';
    } else if (F1 == 1 && F2 == 0 && F3 == 0 && F4 == 1 && F5 == 1) {
        hand = '2';
    } else if (F1 == 0 && F2 == 0 && F3 == 0 && F4 == 1 && F5 == 1) {
        hand = '3';
    } else if (F1 == 1 && F2 == 0 && F3 == 0 && F4 == 0 && F5 == 0) {
        hand = '4';
    } else if (F1 == 0 && F2 == 0 && F3 == 0 && F4 == 0 && F5 == 0) {
        hand = '5';
    } else if (F1 == 1 && F2 == 0 && F3 == 0 && F4 == 0 && F5 == 1) {
        hand = '6';
    } else if (F1 == 0 && F2 == 1 && F3 == 1 && F4 == 0 && F5 == 1) {
        hand = '7';
    } else if (F1 == 0 && F2 == 1 && F3 == 0 && F4 == 1 && F5 == 1) {
        hand = '8';
    } else if (F1 == 1 && F2 == 1 && F3 == 0 && F4 == 0 && F5 == 0) {
        hand = '9';
    }

    return hand;
}