/* 
 * File:   index.h
 * Author: sabri
 *
 * Created on April 11, 2024, 4:27 PM
 */

#ifndef INDEX_H
#define	INDEX_H

#ifdef	__cplusplus
extern "C" {
#endif
void initIndexBuffer();
void putIndexVal(int ADCvalue);
long int getIndexAvg();



#ifdef	__cplusplus
}
#endif

#endif	/* INDEX_H */

