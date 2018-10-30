# Toolchain

CC=gcc
LD=ld
AS=gcc
AR=ar





#Libpip dir



LIBPIP=/home/mahckr/Documents/these/CodingAnnee2/workshop/libpip/

# Directories



SRCDIR=src 
INCDIR=include 

# Generate source and object list
SOURCES=$(foreach dir, ${SRCDIR}, $(wildcard $(dir)/*.c))
OBJ=$(SOURCES:.c=.o)
ASOURCES=$(foreach dir, ${SRCDIR}, $(wildcard $(dir)/*.S))
AOBJ=$(ASOURCES:.S=.o)

# Lib directory and output file
LIBDIR=lib
LIB=$(LIBDIR)/libpip.a


# Add define for variant and architecture
vARCHDEF=$(shell echo $(ARCH) | tr a-z A-Z)
VARIANTDEF=$(shell echo $(VARIANT) | tr a-z A-Z)




# C flags
CFLAGS=-c -ffreestanding -nostdlib -Wall -Werror -Wextra -fno-builtin -Wno-unused-parameter -Wno-unused-variable -m32 -g3 -fno-caller-saves -fno-pic -no-pie -fno-stack-protector 
CFLAGS+=$(foreach dir, $(INCDIR), -I$(dir))

# Assembler flags
ASFLAGS=-m32 -c -I. -I./include -fomit-frame-pointer --freestanding -nostdlib -fno-stack-protector

# Archiver flags
ARFLAGS=rcs





CFLAGS+=-I$(LIBPIP)/include -I$(LIBPIP)/arch/x86/include/ -fno-pic -no-pie -fno-stack-protector 


.PHONY: info all

all: info $(LIBDIR) $(LIB)

info:
	@echo Building Libfreertos .

clean: 
	rm -rf $(LIBDIR) $(OBJ) $(AOBJ)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(LIB): $(OBJ) $(AOBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

