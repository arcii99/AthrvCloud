//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_COMMAND_LENGTH 100 // Define the maximum length of command
#define MAX_NUM_COMMANDS 10 // Define the maximum number of commands

int main(){

    char *commands[MAX_NUM_COMMANDS]; // Array to store commands
    char command[MAX_COMMAND_LENGTH]; // Buffer to take user input

    while(1){
        printf(">> "); // Print shell prompt
        fgets(command, MAX_COMMAND_LENGTH, stdin); // Read user input from stdin and store in buffer

        int num_commands = 0;
        char *token;
        token = strtok(command, " "); // Tokenize user input by space character

        while(token != NULL){
            commands[num_commands++] = token; // Store each token as separate command
            token = strtok(NULL, " "); // Move to next token
        }

        if(num_commands == 0){
            continue; // If no command was entered, skip to next iteration
        }

        commands[num_commands] = NULL; // Set the last entry of commands array to NULL, as required by execvp()

        if(strcmp(commands[0], "exit") == 0){
            return 0; // If user entered "exit", exit the program
        }

        pid_t pid = fork(); // Fork a child process to run the command

        if(pid == 0){ // If this is the child process
            int error = execvp(commands[0], commands); // Execute the command

            if(error == -1){ // If execvp() fails
                printf("Error executing command.\n");
                exit(1); // Exit with error status
            }
        }

        else if(pid > 0){ // If this is the parent process
            int status;
            waitpid(pid, &status, 0); // Wait for the child process to finish before continuing
        }

        else{ // If fork() fails
            printf("Error forking child process.\n");
            exit(1); // Exit with error status
        }
    }

    return 0;
}