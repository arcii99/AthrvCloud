//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void) {
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    pid_t pid;
    int fd[2];

    //create the pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    //fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0) {  //parent process
        //close the unused end of the pipe
        close(fd[READ_END]);

        //write to the pipe
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);

        //close the write end of the pipe
        close(fd[WRITE_END]);

        printf("Parent process sending message: %s\n", write_msg);
    }
    else {  //child process
        //close the unused end of the pipe
        close(fd[WRITE_END]);

        //read from the pipe
        read(fd[READ_END], read_msg, BUFFER_SIZE);

        //close the read end of the pipe
        close(fd[READ_END]);

        printf("Child process received message: %s\n", read_msg);
    }

    return 0;
}