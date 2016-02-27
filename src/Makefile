ASFLAGS += -mcpu=arm1176jzf-s
CFLAGS  += -mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -Wall -Wextra -pedantic -Werror
SRCS     = entry.o uart.o util.o
LD       = ${CC} # We can just use the gnu C compiler for this.. usually.
LDFLAGS  = -ffreestanding -O2 -nostdlib

all: ${SRCS} link

# apply make TARGET=qemu to build for qemu :)
link:
	$(LD) -T ../scripts/${TARGET}.ld -o ../build/kernel.elf ${LDFLAGS} ${SRCS}
