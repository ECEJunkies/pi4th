#ifndef SDCOMM_SPI_H
#define SDCOMM_SPI_H
#include "types.h"
typedef struct{
	unsigned long int timeout_write;
	unsigned long int timeout_read;
	char busyflag;
} sd_context_t;
#define R1 1
#define	R1B 2
#define R2 3
#define R3 4
#define MSK_IDLE			0x01
#define MSK_ERASE_RST		0x02
#define MSK_ILL_CMD			0x04
#define MSK_CRC_ERR			0x08
#define MSK_ERASE_SEQ_ERR	0x10
#define MSK_ADDR_ERR		0x20
#define MSK_PARAM_ERR		0x40
#define SD_TOK_READ_STARTBLOCK		0xFE
#define SD_TOK_WRITE_STARTBLOCK		0xFE
#define SD_TOK_READ_STARTBLOCK_M	0xFE
#define SD_TOK_WRITE_STARTBLOCK_M	0xFC
#define SD_TOK_STOP_MULTI			0xFD
											/* Error token is 111XXXXX */
#define MSK_TOK_DATAERROR		0xE0
											/* Bit fields */
#define MSK_TOK_ERROR			0x01
#define MSK_TOK_CC_ERROR		0x02
#define MSK_TOK_ECC_FAILED		0x04
#define MSK_TOK_CC_OUTOFRANGE	0x08
#define MSK_TOK_CC_LOCKED		0x10
#define MSK_OCR_33		0xC0	/* Mask off the bits in the OCR corresponding to voltage range 3.2V to 3.4V, OCR bits 20 and 21 */
#define SD_INIT_TRY		50		/* Number of times to retry the probe cycle during initialization */
#define SD_IDLE_WAIT_MAX	100		/* Number of tries to wait for the card to go idle during initialization */
#define SD_CMD_TIMEOUT		100		/* Hardcoded timeout for commands. 8 words, or 64 clocks. Do 10 words instead */
/******************************** Basic command set **************************/
#define CMD0 0			/* Reset cards to idle state */
#define CMD0_R R1
#define CMD1 1			/* Read the OCR (MMC mode, do not use for SD cards) */
#define CMD1_R R1
#define CMD9 9			/* Card sends the CSD */
#define CMD9_R R1
#define CMD10 10		/* Card sends CID */
#define CMD10_R R1
#define CMD12 12		/* Stop a multiple block (stream) read/write operation */
#define CMD12_R R1B
#define CMD13 13		/* Get the addressed card’s status register */
#define CMD13_R R2
/***************************** Block read commands **************************/
#define CMD16 16		/* Set the block length */
#define CMD16_R R1
#define CMD17 17		/* Read a single block */
#define CMD17_R R1
#define CMD18 18		/* Read multiple blocks until a CMD12 */
#define CMD18_R R1
/***************************** Block write commands *************************/
#define CMD24 24		/* Write a block of the size selected with CMD16 */
#define CMD24_R R1
#define CMD25 25		/* Multiple block write until a CMD12 */
#define CMD25_R R1
#define CMD27 27		/* Program the programmable bits of the CSD */
#define CMD27_R R1
/***************************** Write protection *****************************/
#define CMD28 28		/* Set the write protection bit of the addressed group */
#define CMD28_R R1B
#define CMD29 29		/* Clear the write protection bit of the addressed group */
#define CMD29_R R1B
#define CMD30 30		/* Ask the card for the status of the write protection bits */
#define CMD30_R R1
/***************************** Erase commands *******************************/
#define CMD32 32		/* Set the address of the first write block to be erased */
#define CMD32_R R1
#define CMD33 33		/* Set the address of the last write block to be erased */
#define CMD33_R R1
#define CMD38 38		/* Erase the selected write blocks */
#define CMD38_R R1B
/***************************** Lock Card commands ***************************/
/* Commands from 42 to 54, not defined here */
/***************************** Application-specific commands ****************/
#define CMD55 55		/* Flag that the next command is application-specific */
#define CMD55_R R1
#define CMD56 56		/* General purpose I/O for application-specific commands */
#define CMD56_R R1
#define CMD58 58		/* Read the OCR (SPI mode only) */
#define CMD58_R R3
#define CMD59 59		/* Turn CRC on or off */
#define CMD59_R R1
/***************************** Application-specific commands ***************/
#define ACMD13 13		/* Get the SD card’s status */
#define ACMD13_R R2		
#define ACMD22 22		/* Get the number of written write blocks (Minus errors ) */
#define ACMD22_R R1
#define ACMD23 23		/* Set the number of write blocks to be pre-erased before writing */
#define ACMD23_R R1
#define ACMD41 41		/* Get the card’s OCR (SD mode) */
#define ACMD41_R R1
#define ACMD42 42		/* Connect or disconnect the 50kOhm internal pull-up on CD/DAT[3] */
#define ACMD42_R R1
#define ACMD51 42		/* Get the SD configuration register */
#define ACMD51_R R1
#endif
