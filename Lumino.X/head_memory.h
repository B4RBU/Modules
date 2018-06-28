/* 
 * File:   head_memory.h
 * Author: axell
 *
 * Created on 3 avril 2018, 20:54
 */

#ifndef HEAD_MEMORY_H
#define	HEAD_MEMORY_H

#ifdef	__cplusplus
extern "C" {
#endif

uint8_t getData(); 
uint8_t writeData(uint8_t value, uint8_t HA, uint8_t LA);
uint8_t readData (uint8_t HA, uint8_t LA);
void tempo(); 

#ifdef	__cplusplus
}
#endif

#endif	/* HEAD_MEMORY_H */

