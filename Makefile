CC			:= aarch64-elf-gcc
AS			:= aarch64-elf-as
LD			:= aarch64-elf-ld
OBJCOPY		:= aarch64-elf-objcopy
QEMU		:= qemu-system-aarch64
INCLUDES	:= -I/opt/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-elf/lib/gcc/aarch64-elf/7.2.1/include -Iinclude/
LDFLAGS		:= -nostdlib -nostartfiles -T linker.ld -Map kernel.map
CFLAGS		:= -std=c11 -g ${INCLUDES} -Wall -Wpedantic -Werror -ffreestanding -nostdinc -nostartfiles

BUILD		:= build
SRC			:= src
TEST_DIR	:= test

SRCS		= $(wildcard ${SRC}/*/*.c)
TESTS		:= $(wildcard ${TEST_DIR}/*/*.c)
OBJS		= ${SRCS:.c=.o}
TESTOBJS	= $(TESTS:.c=.o)
LDOBJS		= $(foreach obj,${OBJS}, $(join ${BUILD}/, $(notdir ${obj})))

make_test:
ifeq ($(MAKECMDGOALS), kernel8.img)
ifdef TEST
ifneq ($(filter ${TEST_DIR}/$(TEST),$(basename $(TESTS))),)
$(info Building $(TEST) ...)
SRCS += ${TEST_DIR}/${TEST}.c
else
$(warning $(TEST) does not exist in tests.))
$(error available tests are ${TESTOBJS})
endif
else
$(error Please provide a test)
endif
endif

.PHONY: make_directory

start.o: start.s

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${BUILD}/$(notdir $@)

kernel8.img: make_test make_directory start.o ${OBJS}
	${LD} ${LDFLAGS} ${LDOBJS} start.o -o build/kernel.elf
	${OBJCOPY} build/kernel.elf -Obinary kernel8.img

run:
	${QEMU} -M raspi3 -m 1G -kernel kernel8.img -serial null -serial mon:stdio -nographic

debug:
	${QEMU} -M raspi3 -m 1G -kernel kernel8.img -serial null -serial mon:stdio -nographic -S -s

clean:
	rm -rf build kernel8.* kernel.*
	find . -name '*.o' -delete

make_directory:
	mkdir -p build