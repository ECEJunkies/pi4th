ASFLAGS += -mcpu=arm1176jzf-s
SRCS     = entry.o
LD       = ${CC} # We can just use the gnu C compiler for this.. usually.
LDFLAGS  = -ffreestanding -O2 -nostdlib

all: ${SRCS} link

# apply make TARGET=qemu to build for qemu :)
link:
	$(CC) -T ../scripts/${TARGET}.ld -o ../build/kernel.elf ${LDFLAGS} ${SRCS}
