//FormAI DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>    
#include <unistd.h>   
#include <string.h>   
#include <sys/wait.h> 
#include <sys/types.h>
#include <fcntl.h>   

#define MAX_LINE 80 // max length of command
#define BUF_SIZE 256 // buffer size

int main(int argc, char *argv[]) {
    int fd[2]; // file descriptor array for pipe
    pid_t pid;
    char buf[BUF_SIZE];
    char inbuf[BUF_SIZE];

    if (pipe(fd) < 0) { // creating the pipe
        fprintf(stderr, "Pipe failed");
        return EXIT_FAILURE;
    }

    char cmd[MAX_LINE + 1]; // buffer to hold the command

    while (1) {
        printf("osh> ");
        fflush(stdout);
        fgets(cmd, MAX_LINE, stdin);

        if (strcmp(cmd, "exit\n") == 0) {
            break;
        }

        pid = fork();
        if (pid < 0) { // error occurred
            fprintf(stderr, "Fork failed");
            return EXIT_FAILURE;
        } else if (pid == 0) { // child process
            close(fd[0]); // close reading end of pipe

            if (write(fd[1], cmd, strlen(cmd) + 1) < 0) {
                fprintf(stderr, "Write failed");
                return EXIT_FAILURE;
            }

            close(fd[1]); // close writing end of pipe

            exit(EXIT_SUCCESS);
        } else { // parent process
            close(fd[1]); // close writing end of pipe

            if (read(fd[0], buf, BUF_SIZE) < 0) { // read from pipe
                fprintf(stderr, "Read failed");
                return EXIT_FAILURE;
            }

            close(fd[0]); // close reading end of pipe

            system(buf); // execute the command
        }
    }

    return EXIT_SUCCESS;
}