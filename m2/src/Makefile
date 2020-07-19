#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# General flags for both platforms
FLAGS = -Wall -Werror -g -O0 -std=c99

TARGET = c1m2

ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = -T msp432p401r.lds
	LINKER_PATH = -L ../
        CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.space
	ARCH_FLAGS = -mthmb \
		     -mfloat-abi-hard \
		     -mfpu=fpv4-sp-d16

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl, -Map=$(TARGET).map $(LINKER_PATH) $(LINKER_FILE)
	CFLAGS = $(FLAGS) $(ARCH_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	CPPFLAGs = -DMSP432 $(INCLUDES)

	# Architecture specific source files
	SRCS = main.c \
	       memory.c \
	       interrupts_msp432p401_gcc.c \
	       startup_msp432p401r_gcc.c \
	       system_msp432p401r.c

	SIZE = arm-none-eabi-size

else
	# Compiler Flags and Defines
	CC = gcc
	LDFLAGS = -Wl, -Map=$(TARGET).map
	CFLAGS = $(FLAGS)
	CPPFLAGs = -DHOST $(INCLUDES)
	SIZE = size

	# Source files for the host
	SRCS = main.c \
	       memory.c \

endif

#using a list of source files to generate other variables
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
ASMS := $(SRCS:.c=.asm)
PREP := $(SRCS:.c=.i)

#stop after assembler generates a .o file
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

#stop after assembler generates a .asm file
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# -E and -M flags to generate the dependancies
%.d: %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

# compile all and generate obhect files from source files (do not link)
.PHONY: compile all 
compile-all: $(OBJS)

#compile linking everything and create dependancies for the sources
.PHONY: build 
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

#clean everything except for the source files
.PHONY: clean
clean:

	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map
