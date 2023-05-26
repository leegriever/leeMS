#ifndef MSG_SLOT_H
#define MSG_SLOT_H

#include <linux/kernel.h>   /* We're doing kernel work */
#include <linux/module.h>   /* Specifically, a module */
#include <linux/fs.h>       /* for register_chrdev */
#include <linux/string.h>   /* for memset. NOTE - not string.h!*/
// The major device number
#define MAJOR_NUM 235
#define MAX_MSG_LEN 128
#define MAX_SLOTS 256
#define SUCCESS 0
#define FAIL -1
// Set the message of the device driver
#define MSG_SLOT_CHANNEL _IOW(MAJOR_NUM, 0, unsigned long)

#define DEVICE_RANGE_NAME "message_slot"
#define DEVICE_FILE_NAME "message_slot"





#endif
