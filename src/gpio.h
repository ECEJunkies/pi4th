#ifndef __GPIO_H__
#define __GPIO_H__

enum
  {
    GPIO_BASE = 0x20200000,

    GPPUD = (GPIO_BASE + 0x94),
    GPPUDCLK0 = (GPIO_BASE + 0x98),

    // We can always add more later (or even convert segments into structs)
  };

#endif // __GPIO_H__
