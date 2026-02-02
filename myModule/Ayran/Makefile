PWD := $(shell pwd)
KDIR := /usr/src/linux-headers-5.15.0-106-generic/
# CFLAGS += -Iinc
obj-m := Ayran.o

AyranFiles := $(wildcard $(src)/src/hello/*.c)
Ayran-objs += $(patsubst $(src)/%.c,%.o,$(AyranFiles))
$(warning CFILES=$(CFILES))
$(warning OBJS=$(Ayran-objs))

# Ayran-objs += src/hello/hello_print.o \
# 			  src/hello/hello_time.o \
# 			  src/hello/hello_main.o

ccflags-y := -I$(src)/inc/hello \
			 -I$(src)/inc/cdev
# 			 -I/usr/xgl/WSL2-Linux-Kernel-linux-msft-wsl-6.6.87.2/tools/include
# KDIR :=/usr/xgl/WSL2-Linux-Kernel-linux-msft-wsl-6.6.87.2

obj-m:=cdev.o
cdevFiles := $(wildcard $(src)/src/cdev/*.c)
cdev-objs += $(patsubst $(src)/%.c,%.o,$(cdevFiles))

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
check:
	@echo "$(SRCS)"
	@echo "$(src)/src"