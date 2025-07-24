//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[30];

    /* Create a pipe */
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    /* Create a child process */
    pid = fork();

    if (pid < 0) { /* Failed to create child */
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { /* Child process */
        close(pipefd[0]); /* Close unused read end */

        char* message = "This is the message from child process\n";
        write(pipefd[1], message, strlen(message)); /* Send message to parent */

        close(pipefd[1]); /* Close write end */
        exit(EXIT_SUCCESS);
    }
    else { /* Parent process */
        close(pipefd[1]); /* Close unused write end */

        read(pipefd[0], buffer, sizeof(buffer)); /* Read message from child */
        printf("Message Received by Parent: %s", buffer);

        close(pipefd[0]); /* Close read end */
        wait(NULL); /* Wait for child to exit */
        exit(EXIT_SUCCESS);
    }

    return 0;
}