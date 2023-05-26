#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "message_slot_koren.h"


typedef enum errors {
  LEN,
  OPEN,
  ID,
  CLOSE,
} e;

void checker(int val1, int val2, e op);

// general function for validations
void checker(int val1, int val2, e op){
    if (op == LEN && val1 != val2){
        perror("Error - Invalid number of command line arguments");
        exit(1);
    }
    if (op == OPEN && val1 == val2){
        perror("Error - failed to open file");
        exit(1);
    }
    if (op == ID && val1 != val2){
        perror("Error - failed to set channel id");
        exit(1);
    }
    if (op == CLOSE && val1 == val2){
        perror("Error - failed closing file");
        exit(1);
    }
}

int main(int argc, char* argv[]){
    int fd = 0;
    unsigned long channel_id = 0;
    // validate num of args
    checker(argc, 4, LEN);
    fd = open(argv[1], O_WRONLY);
    // check file open success 
    checker(fd, -1, OPEN);
    channel_id = (unsigned long) atoi(argv[2]);
    // check ioctl sucsses
    checker(ioctl(fd, MSG_SLOT_CHANNEL, channel_id), 0, ID);
    // check printing sucsses
    if (write(fd, argv[3], strlen(argv[3])) != strlen(argv[3])){
        perror("Error - failed closing file");
        exit(1);
    }
    // check closing sucsses
    close(fd);
    
    exit(0);
}

