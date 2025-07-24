//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    int fd1, fd2;
    char buffer[MAX_BUFFER_SIZE];
    pid_t pid;

    mkfifo("pipe1", 0666);
    mkfifo("pipe2", 0666);
    printf("Initializing interprocess communication...\n");

    pid = fork();

    if (pid < 0) {
        printf("Error: Fork failed.\n");
        exit(1);
    }
    else if (pid > 0) {
        fd1 = open("pipe1", O_WRONLY);
        printf("\n\nParent process is initializing...\n");
        printf("Enter a message for the child process: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        write(fd1, buffer, MAX_BUFFER_SIZE);
        printf("Sent message to child process.\n");
        close(fd1);

        fd2 = open("pipe2", O_RDONLY);
        printf("\n\nWaiting for response from child process...\n");
        read(fd2, buffer, MAX_BUFFER_SIZE);
        printf("Received response: %s\n", buffer);
        close(fd2);

        printf("\n\nInterprocess communication complete.\n\n");
        exit(0);   
    }
    else {
        fd1 = open("pipe1", O_RDONLY);
        printf("\n\nChild process is initializing...\n");
        read(fd1, buffer, MAX_BUFFER_SIZE);
        printf("Received message: %s\n", buffer);
        close(fd1);

        fd2 = open("pipe2", O_WRONLY);
        printf("\n\nSending response to parent process...\n");
        write(fd2, "Message received.", MAX_BUFFER_SIZE);
        printf("Response sent.\n");
        close(fd2);

        printf("\n\nInterprocess communication complete.\n\n");
        exit(0);
    }

    return 0;
}