//FormAI DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char *myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    printf("Waiting for input...\n");

    fd = open(myfifo, O_RDONLY);

    read(fd, buf, MAX_BUF);
    printf("Received: %s\n", buf);

    close(fd);

    fd = open(myfifo, O_WRONLY);
    printf("Enter message to send: ");
    fgets(buf, sizeof(buf), stdin);

    write(fd, buf, strlen(buf)+1);

    close(fd);

    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}