//FormAI DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define PIPE_READ_END 0
#define PIPE_WRITE_END 1

// Function prototypes
void parent(char *string_to_send, int write_pipe[]);
void child(int read_pipe[]);

int main(){
    int pipefd[2];
    char str[256] = "Hello, World!";

    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if(fork() == 0){
        close(pipefd[PIPE_WRITE_END]);
        child(pipefd);
    }else{
        close(pipefd[PIPE_READ_END]);
        parent(str, pipefd);
    }

    return 0;
}

// Parent function
void parent(char *string_to_send, int write_pipe[]){
    char str[256];
    strcpy(str, string_to_send);
    printf("Parent process sending message to child process: %s\n", str);
    write(write_pipe[PIPE_WRITE_END], str, strlen(str));
    wait(NULL);
}

// Child function
void child(int read_pipe[]){
    char str[256];
    read(read_pipe[PIPE_READ_END], str, 256);
    printf("Child process received message from parent process: %s\n", str);
    exit(EXIT_SUCCESS);
}