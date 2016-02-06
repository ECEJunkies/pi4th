CC      = arm-none-eabi-gcc
AS      = arm-none-eabi-as
MAKE    = make
TARGET ?= rpi

# Some variables we want to be exposed to all of our makefiles:
export CC
export AS
export MAKE
export TARGET

all:
	mkdir -p build # Prevents a weird error
	$(MAKE) -C src

	###################
	# MAKE COMPLETED! #
	###################

# TODO: Replace this rule with something safer:
clean:
	rm -v src/*.o
	rm -v build/*
