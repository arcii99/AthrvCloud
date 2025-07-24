//FormAI DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fds[2];
    pid_t pid;
    char message[] = "Hello world!";
    char buffer[100];

    if (pipe(fds) == -1) {
        fprintf(stderr, "Pipe failed.\n");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }

    if (pid > 0) { // parent process
        close(fds[0]); // close read end of pipe
        write(fds[1], message, strlen(message) + 1); // write message to pipe
        close(fds[1]); // close write end of pipe
        wait(NULL); // wait for child process
    } else { // child process
        close(fds[1]); // close write end of pipe
        read(fds[0], buffer, sizeof(buffer)); // read from pipe
        printf("Received message: %s\n", buffer);
        close(fds[0]); // close read end of pipe
        exit(0);
    }

    return 0;
}