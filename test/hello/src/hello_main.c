#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include "hello_intf.h"
#include "hello_print.h"
#include "hello_time.h"

static int __init hello_init(void)
{
    GetKtTime();
    show_general_hello_print("Ayran");
    return 0;
}

static void __exit hello_exit(void)
{
    GetKtTime();
    show_general_goodbye_print("Ayran");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL v2");