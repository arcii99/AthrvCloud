//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_NUM_ARGS 100

void executeCommand(char **args) {
    pid_t pid;
    int status;
    
    // Fork a new process
    pid = fork();
    
    if (pid < 0) {
        printf("Error: Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            printf("Error: Command not recognized.\n");
            exit(1);
        }
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parseCommand(char *cmd, char **args, int *numArgs) {
    int i = 0;
    *numArgs = 0;
    char *token = strtok(cmd, " \t\n");
    
    while (token != NULL && *numArgs < MAX_NUM_ARGS-1) {
        args[i++] = token;
        *numArgs = *numArgs + 1;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
}

int main() {
    char cmd[MAX_CMD_LEN];
    char *args[MAX_NUM_ARGS];
    int numArgs;
    
    while (1) {
        printf("$ ");
        fflush(stdout);
        
        // Read input from user
        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
            break;
        }
        
        // Remove trailing newline character
        cmd[strcspn(cmd, "\n")] = '\0';
        
        // Parse command
        parseCommand(cmd, args, &numArgs);
        
        // Ignore empty command
        if (numArgs == 0) {
            continue;
        }
        
        // Check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (numArgs == 1) {
                chdir(getenv("HOME"));
            } else {
                chdir(args[1]);
            }
            continue;
        }
        
        // Execute command
        executeCommand(args);
    }
    return 0;
}