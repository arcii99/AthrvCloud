//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024 // Max command length
#define MAX_TOKENS 100 // Max tokens (arguments) in a command
#define MAX_PATH_LEN 1024 // Max path length

char path[MAX_PATH_LEN]; // Store PATH environment variable

void init_shell() {
    // Initialize shell
    if(getcwd(path, MAX_PATH_LEN) == NULL)
        printf("Error in getting current working directory!\n");
}

void print_prompt() {
    // Print shell prompt
    char *user = getenv("USER");
    if(user == NULL)
        printf("Error in getting username!\n");
    else
        printf("%s@%s:$ ", user, path);
}

int tokenize(char *cmd, char **tokens) {
    // Tokenize command into arguments
    int i = 0;
    tokens[i] = strtok(cmd, " \t\n\r"); // First token
    while(tokens[i] != NULL && i < MAX_TOKENS - 1) {
        tokens[++i] = strtok(NULL, " \t\n\r"); // Next token
    }
    return i; // Number of arguments
}

void execute(char **tokens, int n) {
    // Execute command
    pid_t pid = fork(); // Create child process
    if(pid < 0) {
        printf("Error in fork!\n");
        exit(EXIT_FAILURE);
    } else if(pid == 0) {
        // Child process
        if(execvp(tokens[0], tokens) == -1) {
            printf("Error in executing command!\n");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char cmd[MAX_CMD_LEN]; // User input
    char *tokens[MAX_TOKENS]; // Command arguments (tokens)
    init_shell(); // Initialize shell
    while(1) {
        print_prompt(); // Print shell prompt
        if(fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
            printf("\n");
            break;
        }
        int n = tokenize(cmd, tokens); // Get arguments
        if(n > 0) {
            if(strcmp(tokens[0], "cd") == 0) {
                if(n > 1) {
                    if(chdir(tokens[1]) == -1) {
                        printf("Error in changing directory!\n");
                    } else {
                        getcwd(path, MAX_PATH_LEN); // Update path
                    }
                }
            } else if(strcmp(tokens[0], "exit") == 0) {
                break;
            } else {
                execute(tokens, n); // Execute command
            }
        }
    }
    return 0;
}