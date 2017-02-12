// A barebones kernel module, a la www.tldp.org (highly recommended).

// Tegan Lamoureux, 2017
// code_contact@teux.me

#include <linux/module.h> // Basic header, required for all modules.
#include <linux/kernel.h> // For KERN_INFO, which sets log level for printk().
#include <linux/init.h>   // Needed for module init and exit macros.


// Define initialization function.
//   __init macro added so that kernel will discard the function and free used
//   memory once completed. This only applies to compiled-in modules, not
//   loadable modules, which keep memory allocated until unloading. 
static int __init hello_init(void)
{
    // Let's log a message when our module loads, at level KERN_INFO.
    //    Note: Other log levels (that you should use appropriately) are
    //    defined in linux/kernel.h.
    printk(KERN_INFO "Hello! Module loaded successfully.");
  
    return 0; // Return success re: module loading.
}


// Define exit function.
//   __exit macro added so that kernel will discard the function entirely for
//   compiled-in modules, as cleanup is done on shutdown. Does not apply for
//   loadable modules, which need to handle their own cleanup here. 
static void __exit hello_exit(void)
{
    // Let's log an exit message when our module is unloaded.
    printk(KERN_INFO "Module unloaded. Goodbye.\n");
}

// Call our defined init and exit functions with the module_init() and
// module_exit() macros, defined in linux/init.h.
module_init(hello_init);
module_exit(hello_exit);

// License and documentation information.
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tegan Lamoureux <code_contact@teux.me>");
MODULE_DESCRIPTION("A simple hello world module.");
MODULE_SUPPORTED_DEVICE("testdevice");
// Note: MODULE_SUPPORTED_DEVICE just documents that the module is supported
//       for /dev/testdevice. (It has no impact on module performance, it's used
//       for documentation purposes only.)
