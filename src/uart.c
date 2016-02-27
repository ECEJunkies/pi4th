// uart.c

#include "uart.h"
#include "gpio.h"
#include "util.h"   // io_write32(), cycles()
#include "config.h" // UART0_BR_DV, etc

void
uart_init(void)
{

  io_write32( UART0_CR,  0x0 );

  // Pull up / pull down operations:
  io_write32( GPPUD,     0x0 );
  cycle(150); // 150 cycle delay
  io_write32( GPPUDCLK0, (( 1 << 14 ) | ( 1 << 15 )) );
  cycle(150);
  io_write32( GPPUDCLK0, 0x0 );

  io_write32( UART0_ICR, 0x7FF ); // Disable pending IRQs

  // Baud rate stuff:
  io_write32( UART0_IBRD, UART0_BR_DV );
  io_write32( UART0_FBRD, UART0_BR_FR );

  // Mask IRQs:
  io_write32( UART0_LCRH,  (1 << 4) | (1 << 5) | (1 << 6));
  io_write32( UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
	      (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

  // Enable UART0 tx/rx:
  io_write32( UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
}

void
uart0_putc(unsigned char c)
{
  while ( io_read32(UART0_FR) & (1 << 5) ); // Wait until tx ready
  io_write32( UART0_DR, c );
}

// Test function to see if serial will print:
void test(void)
{

  uart0_putc('A');
}
