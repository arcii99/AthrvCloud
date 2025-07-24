//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 80 // Maximum characters allowed in command

// Function to parse arguments from user input
void parse_args(char* input, char** args){
    int i = 0;
    char* token = strtok(input, " \n");  
    while (token != NULL){
        args[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    args[i] = NULL;
}

int main(){
    char input[MAX_LENGTH]; // Buffer to hold user input commands
    char* args[MAX_LENGTH/2 + 1]; // Array to hold parsed arguments
    int status; // Variable to hold child process status
    
    while(1) {
        printf("user@shell$ "); // Shell prompt
        fflush(stdout); // Flush any remaining output in buffer
        
        // Get user input
        fgets(input, MAX_LENGTH, stdin);
        
        // Parse user input
        parse_args(input, args);
        
        // Exit shell if user enters "exit" command
        if(strcmp(args[0], "exit") == 0){
            exit(0);
        }
        
        // Fork a new process to run user command
        pid_t pid = fork();
        if (pid < 0){
            printf("Fork failed.\n");
            exit(1);
        }
        else if (pid == 0){
            // Child process - execute user command
            execvp(args[0], args);
        }
        else{
            // Parent process - wait for child process to finish
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}