
#ifndef INIT_CDEV_H
#define INIT_CDEV_H

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "charDev"
#define BUF_SIZE 1024

static dev_t devno;
static struct cdev my_cdev;

static struct class *my_class;
static struct device *my_device;

static char device_buf[BUF_SIZE];
static size_t device_buf_len;

#endif