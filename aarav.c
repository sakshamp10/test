#include <linux/init.h>
#include <linux/module.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A module printing pid,uid, pgid and comman path");
MODULE_AUTHOR("Aarav");

int pid = 0;
module_param(pid, int, 0);

static int __init Mod_init(void)
{
    struct task_struct *t;
    t = pid_task(find_vpid(pid), PIDTYPE_PID);
    printk("The pid is:");
    printk(KERN_INFO "%d\n", t->pid);
    printk("The pid is:");
    printk(KERN_INFO "%d\n", t->cred->uid.val);
    printk("The common path is:");
    printk(KERN_INFO "%s\n", t->comm);
    printk("The pgid is:");
    printk(KERN_INFO "%d\n", t->group_leader->pid);
   
    return 0;
}
static void __exit Mod_exit(void)
{
    printk(KERN_INFO "Module Exit\n");
}
module_init(Mod_init);
module_exit(Mod_exit);
