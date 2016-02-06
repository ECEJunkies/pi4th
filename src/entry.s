.section ".text.boot"
.globl _start

_start:
  

halt:
  wfe
  b halt

