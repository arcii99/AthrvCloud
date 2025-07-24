//FormAI DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BUF 1024

int main()
{
    int fd1, fd2;
    char *fifo1 = "/tmp/fifo1";
    char *fifo2 = "/tmp/fifo2";

    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    char buf[MAX_BUF];
    char *msg1 = "Hello from process 1!";
    char *msg2 = "Hello from process 2!";

    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process
        fd1 = open(fifo1, O_WRONLY);
        write(fd1, msg1, strlen(msg1) + 1);
        printf("Process 1 sent a message!\n");
        close(fd1);

        fd2 = open(fifo2, O_RDONLY);
        read(fd2, buf, MAX_BUF);
        printf("Process 1 received message: %s\n", buf);
        close(fd2);

        exit(0);
    }
    else
    {
        // Parent process
        fd2 = open(fifo2, O_WRONLY);
        write(fd2, msg2, strlen(msg2) + 1);
        printf("Process 2 sent a message!\n");
        close(fd2);

        fd1 = open(fifo1, O_RDONLY);
        read(fd1, buf, MAX_BUF);
        printf("Process 2 received message: %s\n", buf);
        close(fd1);
    }

    unlink(fifo1);
    unlink(fifo2);

    return 0;
}