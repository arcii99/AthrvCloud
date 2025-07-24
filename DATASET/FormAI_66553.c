//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 25

int main()
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) < 0) {
        printf("Error creating pipe\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("Error creating child process\n");
        return 1;
    }

    if (pid == 0) {
        close(fd[1]);  
        char buffer[BUFFER_SIZE];
        read(fd[0], buffer, BUFFER_SIZE);
        printf("Child process received message: %s\n", buffer);
        close(fd[0]);   
    } 
    else {
        close(fd[0]);  
        char message[BUFFER_SIZE] = "Hello from parent!";
        write(fd[1], message, strlen(message)+1);
        printf("Parent process sent message: %s\n", message);
        close(fd[1]);   
        wait(NULL);
    }

    return 0;
}