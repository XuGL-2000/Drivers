#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "init_cdev.h"
static int open(struct inode *inode, struct file *file)
{
    pr_info("charDev:open\n");
    return 0;
}

static ssize_t read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    ssize_t ret;

    if (*ppos>= device_buf_len) {
        return 0;
    }

    if (count > device_buf_len - *ppos){
        count = device_buf_len -*ppos;
    }

    if (copy_to_user(buf, device_buf + *ppos, count)) {
        return -EFAULT;
    }

    *ppos += count;
    ret = count;

    pr_info("charDev: read %zu bytes\n", ret);
    return ret;
}

static ssize_t write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    if (count > BUF_SIZE) {
        count = BUF_SIZE;
    }

    if (copy_from_user(device_buf, buf, count)) {
        return -EFAULT;
    }

    device_buf_len = count;
    *ppos = 0;
    pr_info("charDev: write %zu bytes\n", count);
    return count;
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = open,
    .read = read,
    .write = write,
};

static int __init charDev_init(void) {
    int ret;
    ret = alloc_chrdev_region(&devno, 0, 1, DEVICE_NAME);
    if (ret) {
        pr_err("alloc_chrdev_region failed\n");
        return ret;
    }

    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;
    ret = cdev_add(&my_cdev, devno, 1);
    if (ret) {
        pr_err("cdev_add failed\n");
        unregister_chrdev_region(devno, 1);
        return ret;
    }
    my_class = class_create(THIS_MODULE, "charDev");
    my_device = device_create(my_class, NULL, devno, NULL, "charDev");

    pr_info("charDev loaded: major=%d minor=%d\n",
            MAJOR(devno), MINOR(devno));
    return 0;
}

static void __exit charDev_exit(void)
{
    device_destroy(my_class, devno);
    class_destroy(my_class);
    cdev_del(&my_cdev);
    unregister_chrdev_region(devno, 1);
    pr_info("charDev unloaded\n");
}

module_init(charDev_init);
module_exit(charDev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("you");
MODULE_DESCRIPTION("Simple character device example");