//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define READ_END 0
#define WRITE_END 1

int main(void) 
{
    char write_msg[100] = "Hello, from the parent process!";
    char read_msg[100];
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) 
    {
        fprintf(stderr,"Pipe failed");
        return 1;
    }

    pid = fork();

    if(pid < 0) 
    {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if(pid > 0) 
    {
        // Parent process
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
        close(fd[WRITE_END]);
    } 
    else 
    {
        // Child process
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, sizeof(read_msg));
        printf("Child received: %s\n",read_msg);
        close(fd[READ_END]);
    }

    return 0;
}