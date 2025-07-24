//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
// An Interprocess communication example program using pipes
// Created by Chatbot

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    int fd[2]; // fd[0] is for reading, fd[1] is for writing
    pid_t pid;
    char buffer[50];
    
    if(pipe(fd)==-1){ // Error checking for pipe creation
        perror("Pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork(); // Creating child process
    if(pid == -1){ // Error checking for fork call
        perror("Fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){ // Child process
        // Closing the read end of the pipe since this process won't use it
        close(fd[0]);
        // Writing some data to the pipe
        write(fd[1], "Hello from the child process!", 30);
        // Closing the write end of the pipe
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
    else{ // Parent process
        // Waiting for the child process to exit
        wait(NULL);
        // Closing the write end of the pipe since this process won't use it
        close(fd[1]);
        // Reading data from the pipe
        read(fd[0], buffer, 50);
        // Printing the data read from the pipe
        printf("Data read from pipe: %s\n", buffer);
        // Closing the read end of the pipe
        close(fd[0]);
    }
    return 0;
}