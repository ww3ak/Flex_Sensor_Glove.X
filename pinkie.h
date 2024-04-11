/* 
 * File:   pinkie.h
 * Author: sabri
 *
 * Created on April 11, 2024, 4:27 PM
 */

#ifndef PINKIE_H
#define	PINKIE_H

#ifdef	__cplusplus
extern "C" {
#endif
void initPinkieBuffer();
void putPinkieVal(int ADCvalue);
long int getPinkieAvg();



#ifdef	__cplusplus
}
#endif

#endif	/* PINKIE_H */

