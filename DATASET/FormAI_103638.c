//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int main(){

    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];

    while(1){
        printf("Enter Command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        
        // Remove the newline character at the end of the string
        command[strcspn(command, "\n")] = 0;

        if(strcmp(command, "exit") == 0){
            exit(0);
        }

        // Tokenize the command
        char *token = strtok(command, " ");
        int i = 0;
        while(token != NULL && i < MAX_ARGS){
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Fork a child process to execute the command
        pid_t pid = fork();

        if(pid == 0){
            // This is the child process
            execvp(args[0], args);
            printf("Command not found.\n");
            exit(-1);
        }
        else if(pid > 0){
            // This is the parent process
            int status;
            wait(&status);    
        }
        else{
            printf("Fork failed\n");
            exit(-1);
        }
    }
    return 0;
}