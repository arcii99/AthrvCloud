//FormAI DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    printf("Welcome to the Interprocess Communication Example program!\n");

    pid_t pid;
    int pipefd[2];
    char buf[20];

    if (pipe(pipefd) == -1) {
        printf("Failed to create pipe!\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        printf("Failed to fork process!\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { /* child process */
        close(pipefd[1]); /* close unused write end */

        int len = read(pipefd[0], buf, 20);

        printf("Child process received message: %.*s\n", len, buf);

        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
    } else { /* parent process */
        close(pipefd[0]); /* close unused read end */

        char message[] = "Hello, child process!";

        if (write(pipefd[1], message, strlen(message)) == -1) {
            printf("Failed to write to pipe!\n");
            exit(EXIT_FAILURE);
        }

        printf("Parent process sent message: %s\n", message);

        close(pipefd[1]);
        wait(NULL); /* wait for child to exit */

        printf("Interprocess communication successful!\n");
        printf("Exiting program...\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}