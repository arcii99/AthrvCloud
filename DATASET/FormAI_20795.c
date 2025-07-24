//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUF 1024

int main()
{
    int fd1, fd2;
    char *myfifo1 = "/tmp/myfifo1";
    char *myfifo2 = "/tmp/myfifo2";
    char buf[MAX_BUF];

    /* create the named pipes (FIFOs) */
    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);

    printf("Sherlock Holmes: Waiting for messages from Watson...\n");

    /* open the first named pipe */
    fd1 = open(myfifo1, O_RDONLY);

    while(1) {
    
        /* read message from Watson */
        read(fd1, buf, MAX_BUF);
        
        if(strlen(buf) == 0) {
            /* close the first named pipe */
            close(fd1);
            printf("Sherlock Holmes: Exiting program\n");
            exit(EXIT_SUCCESS);
        }

        printf("Sherlock Holmes: Received message: %s\n", buf);

        /* open the second named pipe */
        fd2 = open(myfifo2, O_WRONLY);

        /* process the message and send a response */
        if(strstr(buf, "murder") != NULL) {
            char *response = "The murderer is a left-handed person with a limp";
            write(fd2, response, strlen(response)+1);
        } else if(strstr(buf, "weapon") != NULL) {
            char *response = "The weapon was a knife with a distinctive handle";
            write(fd2, response, strlen(response)+1);
        } else if(strstr(buf, "motive") != NULL) {
            char *response = "The motive was revenge for a past injustice";
            write(fd2, response, strlen(response)+1);
        } else {
            char *response = "Could not deduce any information from your message";
            write(fd2, response, strlen(response)+1);
        }

        /* close the second named pipe */
        close(fd2);
    }

    return 0;
}