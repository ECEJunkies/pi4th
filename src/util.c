// util.c

#include <stdint.h>
#include "util.h"


// Some more stuff I pulled from http://wiki.osdev.org/Raspberry_Pi_Bare_Bones:
inline void
cycle (uint32_t cycles)
{

  asm volatile
    ("__delay_%=: subs %[cycles], %[cycles], #1; bne __delay_%=\n"
     : : [cycles]"r"(cycles) : "cc");
}

// This is the version from osdev.. it could be modified...
inline void
io_write32 (uint32_t reg, uint32_t data)
{

  *( volatile uint32_t * ) reg = data;
}

inline uint32_t
io_read32 (uint32_t reg)
{

  return *( volatile uint32_t * ) reg;
}
