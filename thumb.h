/* 
 * File:   thumb.h
 * Author: sabri
 *
 * Created on April 11, 2024, 4:28 PM
 */

#ifndef THUMB_H
#define	THUMB_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void initThumbBuffer();
void putThumbVal(int ADCvalue);
long int getPointAvg();




#ifdef	__cplusplus
}
#endif

#endif	/* THUMB_H */

