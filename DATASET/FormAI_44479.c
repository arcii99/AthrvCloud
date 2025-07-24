//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_COMMANDS 10

void execute_command(char *args[]);

int main() {
    char buffer[1000];
    const char delimiter[2] = " ";
    char *token;
    char *commands[MAX_COMMANDS][MAX_ARGS];
    int n_commands = 0;
    pid_t pid;
    int status;
    
    while(1) {
        printf("myshell$ ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // Split buffer into commands
        token = strtok(buffer, "|");
        while(token != NULL) {
            char *args[MAX_ARGS];
            int n_args = 0;
            
            // Split command into arguments
            char *arg_token = strtok(token, delimiter);
            while(arg_token != NULL) {
                args[n_args] = arg_token;
                arg_token = strtok(NULL, delimiter);
                n_args++;
            }
            args[n_args] = NULL;
            
            // Add command to commands array
            for(int i = 0; i < n_args; i++) {
                commands[n_commands][i] = args[i];
            }
            commands[n_commands][n_args] = NULL;
            n_commands++;
            
            token = strtok(NULL, "|");
        }
        
        // Execute commands
        int fd[2];
        int prev_fd[2];
        for(int i = 0; i < n_commands; i++) {
            pipe(fd);
            pid = fork();
            if(pid == 0) {
                // Child process
                if(i != 0) {
                    // Connect stdin to previous command's pipe
                    dup2(prev_fd[0], STDIN_FILENO);
                    close(prev_fd[0]);
                    close(prev_fd[1]);
                }
                if(i != n_commands - 1) {
                    // Connect stdout to current command's pipe
                    dup2(fd[1], STDOUT_FILENO);
                    close(fd[0]);
                    close(fd[1]);
                }
                execute_command(commands[i]);
                exit(0);
            } else {
                // Parent process
                if(i != 0) {
                    close(prev_fd[0]);
                    close(prev_fd[1]);
                }
                prev_fd[0] = fd[0];
                prev_fd[1] = fd[1];
            }
        }
        
        // Wait for all child processes to finish
        for(int i = 0; i < n_commands; i++) {
            wait(&status);
        }
        
        // Reset commands array
        n_commands = 0;
        memset(commands, 0, sizeof(commands));
    }
}

void execute_command(char *args[]) {
    int result = execvp(args[0], args);
    if(result == -1) {
        printf("Command not found: %s\n", args[0]);
        exit(1);
    }
}