#include <linux/init.h>
#include <linux/module.h>
#include <linux/kern_levels.h>
#include <linux/kernel.h>
#include <linux/ktime.h>
#include <linux/time.h>
#include <linux/rtc.h>
#include "hello_intf.h"

static void GetKtTime(void)
{
    // ktime_t kt = ktime_get();
    ktime_t kt_real = ktime_get_real();

    struct timespec64 ts;
    ts = ktime_to_timespec64(kt_real);

    struct tm tm_time;
    time64_to_tm(ts.tv_sec, 0, &tm_time);
    printk(KERN_INFO "======Start Time======");
    printk(KERN_INFO "%04d-%02d-%02d %02d:%02d:%02d.\n",
           tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday, tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);
}

static int __init hello_init(void)
{
    GetKtTime();
    printk(KERN_INFO HELLO_INIT);
    return 0;
}

static void __exit hello_exit(void)
{
    GetKtTime();
    printk(KERN_INFO HELLO_EXIT);
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL v2");