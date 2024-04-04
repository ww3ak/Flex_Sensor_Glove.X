/*
 * File:   main.c
 * Author: sabri
 *
 * Created on March 19, 2024, 12:54 PM
 */


#include "xc.h"
#include "display.h"



void setup(void)
{
    CLKDIVbits.RCDIV = 0;
    init7seg();

}

int main(void) {
    setup ();
    char key='N';
    while (1){
        showChar7seg("1");
        delay_ms(5);
        showChar7seg("2");
        delay_ms(5);
    }
    return 0;
}