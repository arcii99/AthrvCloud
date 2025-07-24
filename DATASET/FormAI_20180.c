//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
  
#define MAX_LIMIT 1024 
  
void linux_shell() 
{ 
    char cwd[MAX_LIMIT]; 
    char input[MAX_LIMIT]; 
    char *args[MAX_LIMIT / 2]; // maximum arguments allowed
    int should_run = 1; 
    
    while (should_run) { 
        printf("myshell:%s$ ", getcwd(cwd, MAX_LIMIT)); //Print current working directory
        fflush(stdout); 
        fgets(input, MAX_LIMIT, stdin); // Read the input from the user
        input[strcspn(input, "\n")] = '\0'; // to remove the trailing '\n'
        if (strcmp(input, "exit") == 0)  // If user enters exit, then exit the shell
            exit(0); 
  
        int count = 0; 
        char *temp = strtok(input, " "); // Tokenize the input
        while (temp != NULL) { 
            args[count++] = temp; 
            temp = strtok(NULL, " "); 
        } 
        args[count] = NULL; // Set the last argument to NULL
        pid_t pid = fork(); // Create a child process
        if (pid == 0) { // Child process
            if (execvp(args[0], args) == -1) { // Execute the command
                printf("Invalid command\n"); // If the execute command returns -1, then it's an invalid command
            }
            exit(0); // Exit the child process
        } 
        else if (pid < 0) { // Fork error 
            printf("Fork failed\n"); 
            exit(1); 
        } 
        else { // Parent process
            wait(NULL);  // Wait for the child process to finish
        } 
    } 
} 
  
int main() 
{ 
    printf("*********************** Welcome to Linux Shell ***********************\n"); 
    printf("Type 'exit' to exit the shell\n"); 
    linux_shell(); 
    return 0; 
}