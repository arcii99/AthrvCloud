//FormAI DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUF 1024

int main()
{
    int fd1, fd2;
    char *fifo1 = "/tmp/fifo1";
    char *fifo2 = "/tmp/fifo2";
    char buf1[MAX_BUF];
    char buf2[MAX_BUF];

    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    fd1 = open(fifo1, O_WRONLY);
    fd2 = open(fifo2, O_RDONLY);

    printf("Chat application started!\n");

    while (1)
    {
        printf("You: ");
        fgets(buf1, MAX_BUF, stdin);
        write(fd1, buf1, strlen(buf1) + 1);
        printf("Waiting for response...\n");
        read(fd2, buf2, MAX_BUF);
        printf("Friend: %s\n", buf2);
    }

    close(fd1);
    close(fd2);
    unlink(fifo1);
    unlink(fifo2);

    return 0;
}