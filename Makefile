CC      = arm-none-eabi-gcc
AS      = arm-none-eabi-as
MAKE    = make
TARGET ?= rpi
QEMU    = qemu-system-arm
SERIAL  = /tmp/qemu.io
PERL   ?= /usr/bin/env perl

# Some variables we want to be exposed to all of our makefiles:
export CC
export AS
export MAKE
export TARGET

all: config
	mkdir -p build # Prevents a weird error
	$(MAKE) -C src

	###################
	# MAKE COMPLETED! #
	###################

# TODO: Replace this rule with something safer:
clean:
	rm -v src/*.o
	rm -v build/*

make run:
	rm $(SERIAL)
	mkfifo $(SERIAL)
	$(QEMU) -kernel build/kernel.elf -cpu arm1176 -m 256 -M raspi -serial pipe:$(SERIAL) -nographic

config:
	rm src/config.h
	$(PERL) scripts/config.pl pi4th.conf > src/config.h
