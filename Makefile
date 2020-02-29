GCC = aarch64-elf-gcc
LD = aarch64-elf-ld
OBJCOPY = aarch64-elf-objcopy
CFLAGS = -std=c11 -g -Wall -ffreestanding -nostdlib -nostdinc -nostartfiles
LDFLAGS = -nostdlib -nostartfiles
INCLUDES = -I/opt/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-elf/lib/gcc/aarch64-elf/7.2.1/include -Iinclude/

all:
	mkdir -p build
	$(GCC) $(CFLAGS) $(INCLUDES) -c start.s -o build/start.o
	$(LD) $(LDFLAGS) -T linker.ld build/start.o -Map kernel.map -o build/kernel8.elf
	$(OBJCOPY) build/kernel8.elf -Obinary kernel8.img
run:
	qemu-system-aarch64 -M raspi3 -m 1G -kernel kernel8.img -serial null -serial mon:stdio -nographic

debug: all
	qemu-system-aarch64 -M raspi3 -m 1G -kernel kernel8.img -serial null -serial mon:stdio -nographic -S -s

clean:
	rm -rf build *.o *.elf *.img
