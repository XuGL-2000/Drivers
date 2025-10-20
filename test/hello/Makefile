PWD := $(shell pwd)
# CFLAGS += -Iinc
obj-m := hello.o

hello-objs += src/hello_intf.o

ccflags-y := -I$(src)/inc \
			 -I/usr/xgl/WSL2-Linux-Kernel-linux-msft-wsl-6.6.87.2/tools/include
KDIR :=/usr/xgl/WSL2-Linux-Kernel-linux-msft-wsl-6.6.87.2

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean