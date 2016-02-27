#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdint.h>


// Delay a specified ammount of cpu cycles:
extern void cycle(uint32_t cycles);

// Write 32 bit data to a 32 bit location:
extern void io_write32(uint32_t reg, uint32_t data);
extern uint32_t io_read32(uint32_t reg); // reading too

#endif // __UTIL_H__
