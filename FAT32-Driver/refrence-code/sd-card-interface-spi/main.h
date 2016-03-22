#ifndef MAIN_H

#define MAIN_H
#define PERIPH_CLOCKRATE 8000000	//Peripheral clock rate, in Hz, used for timing.

#include "sdcomm_spi.h"

int do_sd_initialize (sd_context_t *sdc);

#endif
