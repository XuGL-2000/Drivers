PWD := $(shell pwd)
# CFLAGS += -Iinc
obj-m := Ayran.o

# SRC_DIR := src
# SRCS := $(wildcard $(SRC_DIR)/*.c)
# Ayran-objs += $(SRCS:.c=.o)

Ayran-objs += src/hello_print.o \
			  src/hello_time.o \
			  src/hello_main.o



ccflags-y := -I$(src)/inc \
			 -I/usr/xgl/WSL2-Linux-Kernel-linux-msft-wsl-6.6.87.2/tools/include
KDIR :=/usr/xgl/WSL2-Linux-Kernel-linux-msft-wsl-6.6.87.2

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
check:
	@echo "$(SRCS)"
	@echo "$(src)/src"