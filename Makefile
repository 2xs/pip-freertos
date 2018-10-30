#FreeRTOS Makefile
#It permit to generate the binary needed by Pip for booting FreeRTOS as the root partition



all: freertos



freertos:
	cp ../toolchain.mk Demo/pip-kernel/
	make -C Demo/pip-kernel/ all
	cp Demo/pip-kernel/Build/FreeRTOS.bin pip-freertos.bin

clean:
	make -C Demo/pip-kernel/ clean
	rm -rf pip-freertos.bin
