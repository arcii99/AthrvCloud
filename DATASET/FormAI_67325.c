//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h> 

#define MAX_LENGTH 1000 // Maximum length of command string 
#define MAX_NUM_ARGS 100 // Maximum number of arguments that can be passed in a command 

// Function to parse the command string into individual arguments 
int parseArguments(char* command, char** args) 
{ 
    int num_args = 0; 

    // Splitting the command string into individual arguments 
    while (*command != '\0') { 
        while (*command == ' ' || *command == '\t' || *command == '\n') 
            *command++ = '\0'; 

        *args++ = command; 

        while (*command != '\0' && *command != ' ' && 
                *command != '\t' && *command != '\n') 
            command++; 

        num_args++; 
    } 

    *args = NULL; // Setting the last argument to NULL 

    return num_args; 
} 

int main() 
{ 
    char command[MAX_LENGTH]; // Input command string 
    char* args[MAX_NUM_ARGS]; // Array to hold individual arguments 

    while (1) { 
        printf(">> "); // Print prompt for user input 
        fgets(command, MAX_LENGTH, stdin); // Get command from user 

        command[strcspn(command, "\n")] = '\0'; // Removing trailing newline 

        if (strcmp(command, "exit") == 0) // Exit the shell if command is "exit" 
            break; 

        pid_t pid = fork(); 

        if (pid == 0) { 
            // Child process 
            int num_args = parseArguments(command, args); 

            // Executing the command with arguments 
            execvp(args[0], args); 

            // If execvp() fails, print error message and exit child process 
            printf("Error executing the command\n"); 
            exit(0); 
        } 
        else { 
            // Parent process waits for child process to complete 
            wait(NULL); 
        } 
    } 

    return 0; 
}