obj-m := hello.o
KDIR :=/usr/xgl/WSL2-Linux-Kernel-linux-msft-wsl-6.6.87.2
PWD := $(shell pwd)
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean