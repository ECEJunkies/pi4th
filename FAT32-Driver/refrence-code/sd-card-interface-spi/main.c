#include <msp430x16x.h>
#include "main.h"
#include "sd.h"
#include "spi.h"

static unsigned char sd_buffer[512];
static sd_context_t sdc;

void main(void){
	int j, ok;
	ok = 0;
	WDTCTL = WDTPW | WDTHOLD;						// Stop the watchdog timer.
	for (j=0;(j<SD_INIT_TRY) && (ok != 1);j++){
		ok = do_sd_initialize(&sdc); 				//Set some reasonable values for the timeouts. sdc.timeout_write = PERIPH_CLOCKRATE/8;
	}												//sdc.timeout_read = PERIPH_CLOCKRATE/20; sdc.busyflag = 0; 
//------------------Read in the first block on the SD Card-----------------------------
	if (ok == 1){
	sd_read_block(&sdc, 0, sd_buffer);
	sd_wait_notbusy(&sdc);
	}
	while (1){;} 	//Wait forever
}

int do_sd_initialize(sd_context_t *sdc){
	spi_initialize();							//Initialize the SPI controller.
	spi_set_divisor(PERIPH_CLOCKRATE/400000);	//Start out with a slow SPI clock, 400kHz, as required
												//for MMC compatibility. 
//-------------------------------Initialization OK?-------------------------------------
	if(sd_initialize(sdc) != 1){
	return 0;
	}
	spi_set_divisor(2);		//Set the maximum SPI clock rate possible
	return 1;
}

