//FormAI DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MSG_SIZE 1024

int main(void) {
    int pid = fork();

    if (pid == 0) {
        // child process
        char message[MSG_SIZE] = "Knock, knock!";

        // create pipe
        int pipefd[2];
        if (pipe(pipefd) == -1) {
            fprintf(stderr, "Pipe failed!\n");
            exit(EXIT_FAILURE);
        }

        // write to pipe
        if (write(pipefd[1], message, strlen(message)) == -1) {
            fprintf(stderr, "Write failed!\n");
            exit(EXIT_FAILURE);
        }

        // close write end of pipe
        close(pipefd[1]);

        exit(EXIT_SUCCESS);
    } else if (pid > 0) {
        // parent process
        char message[MSG_SIZE];

        // create pipe
        int pipefd[2];
        if (pipe(pipefd) == -1) {
            fprintf(stderr, "Pipe failed!\n");
            exit(EXIT_FAILURE);
        }

        // read from pipe
        if (read(pipefd[0], message, MSG_SIZE) == -1) {
            fprintf(stderr, "Read failed!\n");
            exit(EXIT_FAILURE);
        }

        // close read end of pipe
        close(pipefd[0]);

        // output message
        printf("%s\n", message);

        // wait for child process to finish
        int status;
        waitpid(pid, &status, 0);

        exit(EXIT_SUCCESS);
    } else {
        // fork failed
        fprintf(stderr, "Fork failed!\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}