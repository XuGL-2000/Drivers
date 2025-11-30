#include <linux/printk.h>

// 打印
void show_general_hello_print(char * name)
{
    if (name == NULL){
        printk(KERN_INFO "Error input. Just hello~\n");
        return;
    }

    printk(KERN_INFO "Hello! %s~\n", name);
}

void show_general_goodbye_print(char * name)
{
    if (name == NULL){
        printk(KERN_INFO "Error input. Just bye bye~\n");
        return;
    }

    printk(KERN_INFO "GoodBye! %s~ See you in the next time!\n", name);
}
