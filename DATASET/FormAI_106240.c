//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Ken Thompson
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    int fd1, fd2;
    pid_t pid;
    char buffer[MAX_BUFFER_SIZE];
    char *msg1 = "Hello from Process 1!\n";
    char *msg2 = "Hello from Process 2!\n";

    fd1 = open("./named_pipe1", O_RDWR);
    if (fd1 == -1) {
        printf("Error: could not open named pipe.\n");
        exit(EXIT_FAILURE);
    }

    fd2 = open("./named_pipe2", O_RDWR);
    if (fd2 == -1) {
        printf("Error: could not open named pipe.\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        printf("Error: could not fork child process.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Process 1 is writing message to named pipe.\n");
        write(fd1, msg1, strlen(msg1) + 1);
        sleep(1);
        printf("Process 1 is reading message from named pipe.\n");
        read(fd2, buffer, MAX_BUFFER_SIZE);
        printf("Process 1 received message: %s\n", buffer);
    }
    else {
        printf("Process 2 is writing message to named pipe.\n");
        write(fd2, msg2, strlen(msg2) + 1);
        sleep(1);
        printf("Process 2 is reading message from named pipe.\n");
        read(fd1, buffer, MAX_BUFFER_SIZE);
        printf("Process 2 received message: %s\n", buffer);
        wait(0);
    }

    close(fd1);
    close(fd2);

    return 0;
}