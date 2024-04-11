
#ifndef DISPLAY_H
#define	DISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif
void init7seg (void);
void showChar7seg(char myChar);
void delay_ms(unsigned int ms);




#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

//#ifndef DISPLAY_H
//#define    DISPLAY_H
//
//#include <xc.h> // include processor files - each processor file is guarded.
//
//#ifdef    cplusplus
//extern "C" {
//#endif /* cplusplus */
//
//    // Insert declarations
//
//    enum DIGIT {
//        MSB = (0b1 << 11),
//        LSB = (0b1 << 10)
//    };
//    void init7seg(void);
//    void showChar7seg(char myChar, int myDigit);
//    void delay(long num);
//
//#ifdef    __cplusplus
//}
//#endif
//#endif