.section ".text.boot"
.globl _start

_start:
bl uart_init
bl test
	
halt:
  wfe
  b halt

