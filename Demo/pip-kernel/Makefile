# Toolchain
include ./toolchain.mk

# Target
IMAGE=FreeRTOS.bin
LINKER=elf_ia32_efi.lds
MAPFILE=RTOSDemo.map





#FreeRTOS library

LIB_FREERTOS=../../libfreertos/include/
# LibPepin directory
LIBPIP_ROOT=$(LIBPIP)

LIBPIP_INC=$(LIBPIP_ROOT)/include/
LIBPIP_LIB=$(LIBPIP_ROOT)/lib/

# FreeRTOS directories
ROOTDIR=../..
RTOS_SRCDIR=$(ROOTDIR)/Source
RTOS_IA32DIR=$(RTOS_SRCDIR)/portable/GCC/pip-kernel
RTOS_MEMDIR=$(RTOS_SRCDIR)/portable/MemMang/

RTOS_SRC=$(wildcard $(RTOS_SRCDIR)/*.c)
RTOS_IA32SRC=$(wildcard $(RTOS_IA32DIR)/*.c)
RTOS_IA32ASRC+=$(wildcard $(RTOS_IA32DIR)/*.S)
RTOS_MEMSRC=$(RTOS_MEMDIR)/heap_4.c

# RTOS Object files
RTOS_OBJ=$(RTOS_SRC:.c=.o)
RTOS_IA32OBJ=$(RTOS_IA32SRC:.c=.o)
RTOS_IA32OBJ+=$(RTOS_IA32ASRC:.S=.o)
RTOS_MEMOBJ=$(RTOS_MEMSRC:.c=.o)

# IA32 RTOS directories
IA32DIR=$(shell pwd)
SUPPORT_DIR=$(IA32DIR)/Support_Files
BLINKY_DIR=$(IA32DIR)/Blinky_Demo
FULL_DIR=$(IA32DIR)/Full_Demo
FULL_DIR_TASK=$(ROOTDIR)/Demo/Common/Minimal/

# ODSI directories
OSDI_DIR=$(IA32DIR)/ODSI
INC_CLIENT_SIMPLE_DIR=$(OSDI_DIR)/Client_Simple/include
INC_COMMUNICATE_SIMPLE_DIR=$(OSDI_DIR)/Communicate_Simple/include
INC_CONFIG_SIMPLE_DIR=$(OSDI_DIR)/Config_Simple/include
INC_DOMAINS_SIMPLE_DIR=$(OSDI_DIR)/Domains/include
INC_ESP8266_DIR=$(OSDI_DIR)/ESP8266/include
INC_KEYVAULT_SIMPLE_DIR=$(OSDI_DIR)/KeyVault_Simple/include
INC_NWMANAGER_DIR=$(OSDI_DIR)/NWManager/include
INC_SRC_DIR=$(OSDI_DIR)/src/include
INC_SUPPORT_FILES_DIR=$(OSDI_DIR)/Support_Files/include
INC_TOKEN_SIMPLE_DIR=$(OSDI_DIR)/Token_Simple/include
INC_UTILS_DIR=$(OSDI_DIR)/utils/include

# IA32 RTOS files
SUPPORT_SRC=$(wildcard $(SUPPORT_DIR)/*.c)
SUPPORT_ASRC=$(wildcard $(SUPPORT_DIR)/*.S)
BLINKY_SRC=$(wildcard $(BLINKY_DIR)/*.c)
FULL_SRC=$(wildcard $(FULL_DIR)/*.c)
FULL_ASRC=$(wildcard $(FULL_DIR)/*.S)
FULL_TASK_SRC=$(wildcard $(FULL_DIR_TASK)/*.c)
DEMO_SRC=$(wildcard $(IA32DIR)/*.c)

# ODSI files
CLIENT_SIMPLE_SRC=$(wildcard $(OSDI_DIR)/Client_Simple/*.c)
COMMUNICATE_SIMPLE_SRC=$(wildcard $(OSDI_DIR)/Communicate_Simple/*.c)
CONFIG_SIMPLE_SRC=$(wildcard $(OSDI_DIR)/Config_Simple/*.c)
DOMAINS_SIMPLE_SRC=$(wildcard $(OSDI_DIR)/Domains/*.c)
ESP8266_SRC=$(wildcard $(OSDI_DIR)/ESP8266/*.c)
KEYVAULT_SIMPLE_SRC=$(wildcard $(OSDI_DIR)/KeyVault_Simple/*.c)
NWMANAGER_SRC=$(wildcard $(OSDI_DIR)/NWManager/*.c)
NWMANAGER_PORTABLE_SRC=$(wildcard $(OSDI_DIR)/NWManager/portable/NW_Simple/*.c)
SRC_CORE_SRC=$(wildcard $(OSDI_DIR)/src/core/*.c)
SRC_ADAPTOR_SRC=$(wildcard $(OSDI_DIR)/src/adaptor/Simple/*.c)
SUPPORT_FILES_FIFO_SRC=$(wildcard $(OSDI_DIR)/Support_Files/FIFO/*.c)
SUPPORT_FILES_GALILEO_SRC=$(wildcard $(OSDI_DIR)/Support_Files/Galileo_Gen2_Board/*.c)
SUPPORT_FILES_QUARK_SRC=$(wildcard $(OSDI_DIR)/Support_Files/Intel_Quark_x1000/*.c)
TOKEN_SIMPLE_SRC=$(wildcard $(OSDI_DIR)/TokenSimple/*.c)
UTILS_SRC=$(wildcard $(OSDI_DIR)/utils/*.c)
UTILS_ADAPTOR_SRC=$(wildcard $(OSDI_DIR)/utils/adaptor/*.c)

# IA32 Object files
SUPPORT_OBJ=$(SUPPORT_SRC:.c=.o)
SUPPORT_OBJ+=$(SUPPORT_ASRC:.S=.o)
BLINKY_OBJ=$(BLINKY_SRC:.c=.o)
FULL_OBJ=$(FULL_SRC:.c=.o)
FULL_OBJ+=$(FULL_ASRC:.S=.o)
FULL_TASK_OBJ=$(FULL_TASK_SRC:.c=.o)
DEMO_OBJ=$(DEMO_SRC:.c=.o)

# ODSI Object files
CLIENT_SIMPLE_OBJ=$(CLIENT_SIMPLE_SRC:.c=.o)
COMMUNICATE_SIMPLE_OBJ=$(COMMUNICATE_SIMPLE_SRC:.c=.o)
CONFIG_SIMPLE_OBJ=$(CONFIG_SIMPLE_SRC:.c=.o)
DOMAINS_SIMPLE_OBJ=$(DOMAINS_SIMPLE_SRC:.c=.o)
ESP8266_OBJ=$(ESP8266_SRC:.c=.o)
KEYVAULT_SIMPLE_OBJ=$(KEYVAULT_SIMPLE_SRC:.c=.o)
NWMANAGER_OBJ=$(NWMANAGER_SRC:.c=.o)
NWMANAGER_PORTABLE_OBJ=$(NWMANAGER_PORTABLE_SRC:.c=.o)
SRC_CORE_OBJ=$(SRC_CORE_SRC:.c=.o)
SRC_ADAPTOR_OBJ=$(SRC_ADAPTOR_SRC:.c=.o)
SUPPORT_FILES_FIFO_OBJ=$(SUPPORT_FILES_FIFO_SRC:.c=.o)
SUPPORT_FILES_GALILEO_OBJ=$(SUPPORT_FILES_GALILEO_SRC:.c=.o)
SUPPORT_FILES_QUARK_OBJ=$(SUPPORT_FILES_QUARK_SRC:.c=.o)
TOKEN_SIMPLE_OBJ=$(TOKEN_SIMPLE_SRC:.c=.o)
UTILS_OBJ=$(UTILS_SRC:.c=.o)
UTILS_ADAPTOR_OBJ=$(UTILS_ADAPTOR_SRC:.c=.o)

# Skip some unnecessary files
SKIPOBJ=$(FULL_DIR_TASK)/sp_flop.o $(FULL_DIR_TASK)/comtest.o $(FULL_DIR_TASK)/comtest_strings.o $(FULL_DIR_TASK)/crhook.o $(FULL_DIR_TASK)/AltBlock.o $(FULL_DIR_TASK)/AltQTest.o $(FULL_DIR_TASK)/AltBlckQ.o $(FULL_DIR_TASK)/AltPollQ.o $(FULL_DIR_TASK)/crflash.o $(FULL_DIR_TASK)/flash.o $(FULL_DIR_TASK)/flash_timer.o

# Include arguments for gcc
CFLAGS=-I$(FULL_DIR)
CFLAGS+=-I$(SUPPORT_DIR)
CFLAGS+=-I$(BLINKY_DIR)
CFLAGS+=-I$(RTOS_SRCDIR)/include
CFLAGS+=-I$(ROOTDIR)/Demo/Common/include
CFLAGS+=-I$(IA32DIR)
CFLAGS+=-I$(RTOS_SRCDIR)/portable/GCC/pip-kernel
CFLAGS+=-I$(LIBPIP_INC)
CFLAGS+=-I$(LIBPIP)/arch/x86/include/
CFLAGS+=-I../../Source/include

# ODSI
CFLAGS+=-I$(INC_CLIENT_SIMPLE_DIR)
CFLAGS+=-I$(INC_COMMUNICATE_SIMPLE_DIR)
CFLAGS+=-I$(INC_CONFIG_SIMPLE_DIR)
CFLAGS+=-I$(INC_DOMAINS_SIMPLE_DIR)
CFLAGS+=-I$(INC_ESP8266_DIR)
CFLAGS+=-I$(INC_KEYVAULT_SIMPLE_DIR)
CFLAGS+=-I$(INC_NWMANAGER_DIR)
CFLAGS+=-I$(INC_SRC_DIR)
CFLAGS+=-I$(INC_SUPPORT_FILES_DIR)
CFLAGS+=-I$(INC_TOKEN_SIMPLE_DIR)
CFLAGS+=-I$(INC_UTILS_DIR)

CFLAGS+=$(MKARGS)

# Compilation flags
CFLAGS+= -m32 -g3 -Wall -Wextra -c -fmessage-length=0 -march=pentium -Wno-ignored-qualifiers -mno-ms-bitfields -ffunction-sections -ffreestanding -fomit-frame-pointer -fno-stack-protector -g -fno-pic -no-pie

# Assembler flags
ASFLAGS=-I$(IA32DIR)
ASFLAGS+=-I$(RTOS_SRCDIR)/portable/GCC/pip-kernel
ASFLAGS+=-I$(LIBPIP_INC)
ASFLAGS+=-I$(LIBPIP)/arch/x86/include/
ASFLAGS+=-I../../Source/include
ASFLAGS+= -m32 -Wa,--gdwarf2 -Wa,-march=pentium -c


LIBGCC=$(shell dirname $(shell gcc -print-libgcc-file-name -m32))
# Linker flags
LDFLAGS=-T$(LINKER) -Map=$(BUILD_DIR)/$(MAPFILE) --gc-sections -L$(LIBGCC) -L$(LIBPIP_LIB) -L$(LIBGCC) -melf_i386
LDFLAGS2=-Telf.ld -Map=$(BUILD_DIR)/$(MAPFILE) --gc-sections -L$(LIBGCC) -L$(LIBPIP_LIB) -L$(LIBGCC) -melf_i386


BUILD_DIR=Build/


all: $(IMAGE)
	echo "All done."


clean:
	rm -rf $(RTOS_OBJ) $(RTOS_IA32OBJ) $(SUPPORT_OBJ) $(BLINKY_OBJ) $(FULL_OBJ) $(FULL_TASK_OBJ) $(DEMO_OBJ) \
	$(CLIENT_SIMPLE_OBJ) $(COMMUNICATE_SIMPLE_OBJ) $(CONFIG_SIMPLE_OBJ) $(DOMAINS_SIMPLE_OBJ) \
	$(ESP8266_OBJ) $(KEYVAULT_SIMPLE_OBJ) $(NWMANAGER_OBJ) $(NWMANAGER_PORTABLE_OBJ) \
	$(SRC_CORE_OBJ) $(SRC_ADAPTOR_OBJ) $(SUPPORT_FILES_FIFO_OBJ) $(SUPPORT_FILES_GALILEO_OBJ) \
	$(SUPPORT_FILES_QUARK_OBJ) $(TOKEN_SIMPLE_OBJ) $(UTILS_OBJ) $(UTILS_ADAPTOR_OBJ)
	
	rm -rf $(BUILD_DIR) $(IMAGE)
	rm -rf function_addr.fun
$(IMAGE): $(RTOS_OBJ) $(RTOS_IA32OBJ) $(SUPPORT_OBJ) $(BLINKY_OBJ) $(FULL_OBJ) $(FULL_TASK_OBJ) $(DEMO_OBJ) $(SKIPOBJ) $(RTOS_MEMOBJ) \
	$(CLIENT_SIMPLE_OBJ) $(COMMUNICATE_SIMPLE_OBJ) $(CONFIG_SIMPLE_OBJ) $(DOMAINS_SIMPLE_OBJ) \
	$(ESP8266_OBJ) $(KEYVAULT_SIMPLE_OBJ) $(NWMANAGER_OBJ) $(NWMANAGER_PORTABLE_OBJ) \
	$(SRC_CORE_OBJ) $(SRC_ADAPTOR_OBJ) $(SUPPORT_FILES_FIFO_OBJ) $(SUPPORT_FILES_GALILEO_OBJ) \
	$(SUPPORT_FILES_QUARK_OBJ) $(TOKEN_SIMPLE_OBJ) $(UTILS_OBJ) $(UTILS_ADAPTOR_OBJ)
	
	mkdir -pv $(BUILD_DIR)
	$(LD) $(LDFLAGS) $^ -o $@ -lgcc -lpip
	$(LD) $(LDFLAGS) $^ -o $(BUILD_DIR)/$@ -lgcc -lpip
	$(LD) $(LDFLAGS2) $^ -o $(BUILD_DIR)/FreeRTOS.elf -lgcc -lpip
	nm -g -C $(BUILD_DIR)/FreeRTOS.elf > function_addr.fun
	./generate_fun_header.sh > $(LIB_FREERTOS)/FreeRTOS_partition.h


$(BUILD_DIR):
	mkdir -pv $(BUILD_DIR)/Full_Demo/Standard_Demo_Tasks/Minimal/
	mkdir -pv $(BUILD_DIR)/Support_Files
	mkdir -pv $(BUILD_DIR)/FreeRTOS_Source/portable/GCC/IA32_flat/
	mkdir -pv $(BUILD_DIR)/Blinky_Demo
	mkdir -pv $(BUILD_DIR)/FreeRTOS_Source/portable/MemMang/

$(SKIPOBJ):
	echo "" > /tmp/dummy.c
	$(CC) $(CFLAGS) /tmp/dummy.c -o $@

%.o: %.S
	$(CC) $(ASFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
