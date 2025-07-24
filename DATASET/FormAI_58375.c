//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
//Header files for Interprocess Communication
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

//Function declarations
void parentProcess(int fd[2]);
void childProcess(int fd[2]);

//Main function
int main() {
    int fd[2];
    pid_t pid;

    //Creating Pipe
    if (pipe(fd) == -1) {
        printf("Pipe failed!\n");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    } else if (pid > 0) {
        //Parent process
        parentProcess(fd);
    } else {
        //Child process
        childProcess(fd);
    }

    return 0;
}

//Function definitions

//Parent process function
void parentProcess(int fd[2]) {
    close(fd[0]);

    //Sending message to child process
    char parentMsg[] = "This is a message from parent to child.";
    write(fd[1], parentMsg, strlen(parentMsg) + 1);

    printf("Parent Process Sent Message: %s\n", parentMsg);

    close(fd[1]);
    wait(NULL); //Wait for child process to finish
}

//Child process function
void childProcess(int fd[2]) {
    close(fd[1]);

    //Receiving message from parent process
    char childMsg[100];
    read(fd[0], childMsg, 100);

    printf("Child Process Received Message: %s\n", childMsg);

    close(fd[0]);
}