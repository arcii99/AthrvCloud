//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define BUF_SIZE 1024

char** parse_input(char* input_str);
void print_prompt();
void execute_command(char** args);

int main() {
  char input_buf[BUF_SIZE];

  while (1) {
    print_prompt();

    // Read the user input
    fgets(input_buf, BUF_SIZE, stdin);

    // Parse the input into individual arguments
    char** args = parse_input(input_buf);

    // Execute the command
    execute_command(args);

    // Free the memory allocated for the arguments
    free(args);
  }

  return 0;
}

void print_prompt() {
  // Print the prompt character
  printf("> ");
  fflush(stdout);
}

char** parse_input(char* input_str) {
  char** args = malloc(MAX_ARGS * sizeof(char*));
  char* arg;
  int i = 0;

  // Tokenize the input string and add each token to the arguments array
  arg = strtok(input_str, " \n");
  while (arg != NULL) {
    // Allocate memory for the argument and copy it
    args[i] = malloc(strlen(arg) + 1);
    strcpy(args[i], arg);
    i++;

    // Get the next token
    arg = strtok(NULL, " \n");

    // Check if we have exceeded the maximum number of arguments
    if (i >= MAX_ARGS) {
      printf("Error: too many arguments\n");
      break;
    }
  }

  // Set the last argument to NULL to signal the end of the argument list
  args[i] = NULL;

  return args;
}

void execute_command(char** args) {
  pid_t pid;
  int status;

  // Fork a new process
  pid = fork();
  if (pid < 0) {
    // Forking error
    printf("Error: failed to fork\n");
    return;
  } else if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      // Error occurred while executing the command
      printf("Error: failed to execute command\n");
    }
    exit(0);
  } else {
    // Parent process
    do {
      // Wait for the child process to exit
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}