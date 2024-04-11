/* 
 * File:   middle.h
 * Author: sabri
 *
 * Created on April 11, 2024, 12:25 PM
 */

#ifndef MIDDLE_H
#define	MIDDLE_H

#ifdef	__cplusplus
extern "C" {
#endif
void initMiddleBuffer();
void putMiddleVal(int ADCvalue);
long int getMiddleAvg();




#ifdef	__cplusplus
}
#endif

#endif	/* MIDDLE_H */

