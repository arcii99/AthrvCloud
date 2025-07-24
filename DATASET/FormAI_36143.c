//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_LENGTH 100 // Maximum length of the command
#define MAX_ARGS 10 // Maximum arguments for the command

void parse_command(char* command, int* argc, char* argv[]) {
  char buffer[MAX_LENGTH]; // Buffer for the command
  strcpy(buffer, command); // Copy the command into the buffer
  
  char* token = strtok(buffer, " "); // Tokenize the command by " "
  *argc = 0; // Reset argument counter
  
  while(token != NULL) {
    argv[*argc] = token; // Save argument
    (*argc)++; // Increase argument counter
    token = strtok(NULL, " "); // Continue tokenization
  }
  
  // Terminate argument list with NULL
  argv[*argc] = NULL;
}

int main() {
  while(1) { // Forever loop
    char command[MAX_LENGTH]; // Buffer for the command
    printf(">>> "); // Print shell prompt
    fgets(command, MAX_LENGTH, stdin); // Read input from command line
    
    // Remove trailing newline character
    command[strcspn(command, "\n")] = 0;
    
    if(strcmp(command, "exit") == 0) { // Check for exit command
      printf("Exiting shell...\n");
      break; // Break out of loop
    }
    
    int argc = 0; // Argument counter
    char* argv[MAX_ARGS]; // Argument list
    
    parse_command(command, &argc, argv); // Parse the command
    
    pid_t pid = fork(); // Create child process
    
    if(pid == 0) { // Child process
      int status = execvp(argv[0], argv); // Execute command
      
      if(status == -1) { // Error occurred
        printf("Command not found.\n");
        exit(1);
      }
    }
    else { // Parent process
      wait(NULL); // Wait for child to complete
    }
  }
  
  return 0;
}