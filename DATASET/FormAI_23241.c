//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {

    printf("Hello! I am a grateful program that uses Interprocess Communication (IPC)!\n\n");

    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        fprintf(stderr, "Failed to create pipe!\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to create child process!\n");
        return 1;
    }

    if (pid > 0) {
        close(fd[0]);

        char message[] = "Hello child process, thank you for being born!";

        printf("Parent sending message to child...\n\n");

        write(fd[1], message, strlen(message) + 1);

        printf("Parent sent message successfully!\n\n");
        
        close(fd[1]);

        wait(NULL);
    } else {
        close(fd[1]);

        char buffer[100];

        printf("Child process waiting for message from parent...\n\n");

        read(fd[0], buffer, sizeof(buffer));

        printf("Child received message from parent: \"%s\"\n\n", buffer);
        
        close(fd[0]);

        printf("Thank you parent for the message!\n\n");
    }

    printf("Program completed successfully!\n");

    return 0;
}