//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 16

int main() {
    while(1) {
        // Print the prompt
        printf("myshell> ");
        
        // Read the input command
        char input[1024];
        fgets(input, 1024, stdin);
        
        // Replace newline character with null terminator
        input[strcspn(input, "\n")] = '\0';
        
        // Split the input command into arguments
        char* args[MAX_ARGS];
        char* token = strtok(input, " ");
        int arg_count = 0;
        
        while(token != NULL && arg_count < MAX_ARGS-1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;
        
        // Handle empty input
        if(arg_count == 0) {
            continue;
        }
        
        // Handle exit command
        if(strcmp(args[0], "exit") == 0) {
            exit(0);
        }
        
        // Fork process
        pid_t pid = fork();
        
        if(pid == 0) {
            // Child process, execute command
            execvp(args[0], args);
            printf("%s: command not found\n", args[0]);
            exit(1);
        } 
        else if(pid > 0) {
            // Parent process, wait for child to finish
            wait(NULL);
        } 
        else {
            printf("Fork failed\n");
            exit(1);
        }
    }
    return 0;
}