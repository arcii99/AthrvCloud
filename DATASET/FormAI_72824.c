//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

// Function signatures
void read_command(char*);
void parse_command(char*, char**);
int execute_command(char**);

int main() {
  char command[BUFFER_SIZE];
  char* tokens[BUFFER_SIZE / 2 + 1];
  int status;

  while (1) {
    // Print the prompt
    printf("$ ");
    fflush(stdout);

    // Read the input command
    read_command(command);

    // Parse the input command
    parse_command(command, tokens);

    // Execute the command
    status = execute_command(tokens);

    // Wait for the child process to finish
    wait(NULL);
  }

  return 0;
}

// Function to read the user input command
void read_command(char* command) {
  fgets(command, BUFFER_SIZE, stdin);
}

// Function to parse the user input command
void parse_command(char* command, char** tokens) {
  char* token;
  int i;

  token = strtok(command, TOKEN_DELIMITERS);

  i = 0;
  while (token != NULL) {
    tokens[i] = token;
    i++;

    token = strtok(NULL, TOKEN_DELIMITERS);
  }
  tokens[i] = NULL;
}

// Function to execute the user input command
int execute_command(char** tokens) {
  pid_t pid;
  int status;

  // Execute the command in a child process
  pid = fork();

  if (pid == 0) {
    // Child process executes the command
    if (execvp(tokens[0], tokens) == -1) {
      perror("Error");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Fork failed
    perror("Error forking");
  } else {
    // Parent process waits for the child to finish
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}