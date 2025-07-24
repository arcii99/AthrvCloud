//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_CMD_LENGTH 100

// Function to get command from input
void getCommand(char *cmd) {
    printf("> ");
    fgets(cmd, MAX_CMD_LENGTH, stdin);  // Read input from command line
    cmd[strcspn(cmd, "\n")] = '\0';  // Remove newline character from input
}

int main() {
    char cmd[MAX_CMD_LENGTH];  // Stores input from command line
    
    while(1) {
        getCommand(cmd);  // Get command from user
        if(strcmp(cmd, "exit") == 0) {
            printf("Exiting shell...\n");
            break;  // Exit shell
        }
        
        int argc = 0;
        char *argv[MAX_ARGS];
        char *token; 
        token = strtok(cmd, " ");  // Parse command into tokens
        while(token != NULL && argc < MAX_ARGS) {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;  // Last argument must be NULL for execvp
        
        pid_t pid = fork();  // Create new process
        if(pid < 0) {
            perror("Error: fork() failed");  // Handle error
            exit(1);
        } else if(pid == 0) {
            // Code for child process
            execvp(argv[0], argv);  // Execute command
            perror("Error: execvp() failed");  // Handle error
            exit(1);
        } else {
            // Code for parent process
            int status;
            waitpid(pid, &status, 0);  // Wait for child to finish
            if(WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                printf("Error: Command returned with status %d\n", WEXITSTATUS(status));
            }
        }
    }
    return 0;
}