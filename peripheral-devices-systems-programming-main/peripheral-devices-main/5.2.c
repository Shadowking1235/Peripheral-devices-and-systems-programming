#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
// set to existing device ids. check with $ lsusb
#define USB_SKEL_VENDOR_ID 0x0000
#define USB_SKEL_PRODUCT_ID 0x0000


static struct usb_device_id skel_table [] = {
        { USB_DEVICE(USB_SKEL_VENDOR_ID, USB_SKEL_PRODUCT_ID) },
        { }
};
MODULE_DEVICE_TABLE (usb, skel_table);

static int skel_probe(struct usb_interface *interface, const struct usb_device_id *id) {
    printk(KERN_INFO "[*] My custom driver: Device (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
    return 0;
}

static void skel_disconnect(struct usb_interface *interface) {
    printk(KERN_INFO "[*] My custom driver: Device was removed\n");
}

static int __init usb_skel_init(void)
{
        printk(KERN_INFO "[*] My custom driver is being registered\n");
        int result;
        result = usb_register(&skel_driver);
        if (result < 0) {
                err("usb_register failed for the "__FILE__ "driver."
                    "Error number %d", result);
                return -1;
        }
        
        printk(KERN_INFO "[*] My custom driver is registered\n");

        return 0;
}
module_init(usb_skel_init);

static void __exit usb_skel_exit(void)
{
        printk(KERN_INFO "[*] My custom driver is deregistered\n");
        usb_deregister(&skel_driver);
}
module_exit(usb_skel_exit);

static struct usb_driver skel_driver = {
        .name        = "My custom USB driver",
        .probe       = skel_probe,
        .disconnect  = skel_disconnect,
        .fops        = &skel_fops,
        .minor       = USB_SKEL_MINOR_BASE,
        .id_table    = skel_table,
};

/* 
$ sudo insmod my-custom-driver.ko 
$ dme
*/
