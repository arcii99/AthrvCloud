//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Ada Lovelace
// Ada Lovelace-style C program demonstrating interprocess communication using pipes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char *message1 = "Hello, ";
    char *message2 = "world!";
    char buffer[BUFSIZ];
    int fd[2];

    if (pipe(fd) < 0) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return EXIT_FAILURE;
    } else if (pid > 0) { // parent process
        close(fd[0]); // close reading end of pipe
        write(fd[1], message1, strlen(message1) + 1); // write message to pipe
        write(fd[1], message2, strlen(message2) + 1); // write message to pipe
        close(fd[1]); // close writing end of pipe
        printf("Parent process is waiting for child process\n");
        wait(NULL); // wait for child process to complete
        printf("Parent process is exiting\n");
        exit(EXIT_SUCCESS);
    } else { // child process
        close(fd[1]); // close writing end of pipe
        read(fd[0], buffer, BUFSIZ); // read message from pipe
        printf("%s", buffer);
        memset(buffer, 0, BUFSIZ); // clear buffer
        read(fd[0], buffer, BUFSIZ); // read message from pipe
        printf("%s\n", buffer);
        close(fd[0]); // close reading end of pipe
        printf("Child process is exiting\n");
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}