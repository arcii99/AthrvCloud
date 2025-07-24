//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    while(1){
        char command[1024];
        int status;

        printf("Welcome to the Irregular Shell!\n>> ");
        fgets(command, 1024, stdin);

        // Remove newline character from the end of the command
        command[strcspn(command, "\n")] = 0;

        if(strcmp(command, "exit") == 0){
            break;
        }

        // Parse command into individual arguments
        char* args[1024];
        int arg_index = 0;

        char* token = strtok(command, " ");
        while(token != NULL){
            args[arg_index++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_index] = NULL;

        // Execute command using fork and execvp
        pid_t pid = fork();
        if(pid < 0){
            printf("Error: Fork Failed\n");
            exit(1);
        }else if(pid == 0){
            // Child process
            if(execvp(args[0], args) < 0){
                printf("Error: Command %s not found\n", args[0]);
                exit(1);
            }
        }else{
            // Parent process
            waitpid(pid, &status, 0);
            printf("Command executed with status %d\n", status);
        }
    }

    printf("Thank you for using the Irregular Shell!\n");

    return 0;
}