//FormAI DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    // Defining the commands to be executed
    char *cmd1[] = {"ls", "-l", NULL};
    char *cmd2[] = {"grep", "test", NULL};
    char *cmd3[] = {"wc", "-l", NULL};
    
    // Creating the pipes required for communication between processes
    int fd1[2], fd2[2];
    if (pipe(fd1) == -1) {
        perror("Pipe error");
        exit(EXIT_FAILURE);
    }
    if (pipe(fd2) == -1) {
        perror("Pipe error");
        exit(EXIT_FAILURE);
    }

    // Forking the first child process to execute the first command
    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {
        // Closing the unused pipe ends
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        // Redirecting the output of command 1 to the pipe
        dup2(fd1[1], STDOUT_FILENO);
        // Executing command 1
        execvp(cmd1[0], cmd1);
        // Terminate the child process if execvp fails
        perror("Execvp error");
        exit(EXIT_FAILURE);
    }

    // Forking the second child process to execute the second command
    pid_t pid2 = fork();
    if (pid1 == -1) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {
        // Closing the unused pipe ends
        close(fd1[1]);
        close(fd2[0]);
        // Redirecting the input from pipe to the command
        dup2(fd1[0], STDIN_FILENO);
        // Redirecting the output of command 2 to the pipe
        dup2(fd2[1], STDOUT_FILENO);
        // Executing command 2
        execvp(cmd2[0], cmd2);
        // Terminate the child process if execvp fails
        perror("Execvp error");
        exit(EXIT_FAILURE);
    }

    // Forking the third child process to execute the third command
    pid_t pid3 = fork();
    if (pid1 == -1) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if (pid3 == 0) {
        // Closing the unused pipe ends
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[1]);
        // Redirecting the input from pipe to the command
        dup2(fd2[0], STDIN_FILENO);
        // Executing command 3
        execvp(cmd3[0], cmd3);
        // Terminate the child process if execvp fails
        perror("Execvp error");
        exit(EXIT_FAILURE);
    }

    // Closing the unused pipe ends
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);

    // Waiting for all child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}