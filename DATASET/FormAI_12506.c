//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS_LENGTH 10

void execute_command(char* command, char** args){
    pid_t pid = fork();
    if(pid == -1){
        printf("Error forking process\n");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){
        execvp(command, args);
        printf("Command not found\n");
        exit(EXIT_FAILURE);
    }
    else{
        int status;
        waitpid(pid, &status, WUNTRACED);
    }
}

int main(){
    char command[MAX_COMMAND_LENGTH]; // Buffer for command input
    char* args[MAX_ARGS_LENGTH]; // Array to store arguments
    
    while(1){
        printf("$ "); // Print prompt
        fflush(stdout);
        
        fgets(command, MAX_COMMAND_LENGTH, stdin); // Read user input
        
        command[strcspn(command, "\n")] = '\0'; // Remove trailing newline
        
        if(strcmp(command, "exit") == 0){ // Exit shell
            printf("Goodbye!\n");
            break;
        }
        
        char* token = strtok(command, " "); // Get first space-separated token
        
        int i = 0;
        
        while(token != NULL){
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        
        args[i] = NULL; // Set last argument as null for execvp
        
        execute_command(args[0], args); // Execute command
    }
    
    return 0;
}