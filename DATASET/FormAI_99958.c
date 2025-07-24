//FormAI DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int fd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    if (pipe(fd) < 0) { // create pipe
        perror("pipe error");
        exit(1);
    }

    if ((pid = fork()) < 0) { // create child process
        perror("fork error");
        exit(1);
    } 

    if (pid > 0) { // parent process (writer)
        close(fd[0]); // close unused read end of the pipe
        char *message = "Hello, I am your parent process!";
        write(fd[1], message, strlen(message));
        printf("Parent has written: %s\n", message);
        close(fd[1]); // close write end of the pipe

        wait(NULL); // wait for child process to complete
        exit(0);
    } else { // child process (reader)
        close(fd[1]); // close unused write end of the pipe
        int nbytes = read(fd[0], buffer, BUFFER_SIZE);
        printf("Child has read: %s\n", buffer);
        close(fd[0]); // close read end of the pipe
        exit(0);
    }
}