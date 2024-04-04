/* 
 * File:   display.h
 * Author: sabri
 *
 * Created on March 19, 2024, 12:54 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif
void init7seg (void);
void showChar7seg(char myChar);
delay_ms(unsigned int ms);




#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

