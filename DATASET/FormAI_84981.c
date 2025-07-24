//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MSG_SIZE 256

int main() {

    int pipe_fd[2];
    pid_t pid;
    char send_msg[MSG_SIZE];
    char recv_msg[MSG_SIZE];

    if (pipe(pipe_fd) < 0) {
        fprintf(stderr, "Pipe creation failed!\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed!\n");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {  // parent process

        printf("Enter a message to send to the child process: ");
        fgets(send_msg, sizeof(send_msg), stdin);

        close(pipe_fd[0]);  // close read end of pipe

        write(pipe_fd[1], send_msg, strlen(send_msg) + 1);  // write data to pipe

        wait(NULL);  // wait for child process to finish

    } else {  // child process

        close(pipe_fd[1]);  // close write end of pipe

        read(pipe_fd[0], recv_msg, sizeof(recv_msg));  // read data from pipe

        printf("Received message from parent process: %s", recv_msg);

        exit(EXIT_SUCCESS);  // exit child process

    }

    return 0;
}