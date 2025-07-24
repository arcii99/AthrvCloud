//FormAI DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// function to print the status of child process
void print_child_status(pid_t pid, int status) {
    if (WIFEXITED(status)) {
        printf("Child with PID %d exited with status %d\n", pid, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Child with PID %d terminated due to signal %d\n", pid, WTERMSIG(status));
    } else if (WIFSTOPPED(status)) {
        printf("Child with PID %d stopped due to signal %d\n", pid, WSTOPSIG(status));
    }
}

int main() {
    pid_t pid;
    int status;
    
    printf("Welcome to the system administration program!\n");
    printf("Enter the name of a command to execute, or 'quit' to exit.\n");
    
    char input[100];
    while (1) {
        printf("$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        // remove newline character from input
        char *newline = strchr(input, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        
        // exit loop if user enters 'quit'
        if (strcmp(input, "quit") == 0) {
            break;
        }
        
        pid = fork();
        if (pid == -1) {
            perror("Error creating child process.");
            exit(1);
        } else if (pid == 0) {
            // child process executes command
            execlp(input, input, NULL);
            
            // if command failed to execute, exit child process with code 1
            perror("Error executing command");
            exit(1);
        } else {
            // parent process waits for child process to complete
            waitpid(pid, &status, 0);
            
            // print status of child process
            print_child_status(pid, status);
        }
    }
    
    printf("Exiting system administration program.\n");
    return 0;
}