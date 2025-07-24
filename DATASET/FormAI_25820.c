//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of command
#define BUFFER_SIZE 10 // Buffer size for reading input

// Function declarations
void get_input(char* args[], int* should_run);
void execute_command(char* args[]);

int main(void) {
  char* args[MAX_LINE/2 + 1]; // Command line arguments
  int should_run = 1; // Flag to determine when to exit program

  while (should_run) {
    printf("osh> ");
    fflush(stdout);

    get_input(args, &should_run);
    execute_command(args);
  }

  return 0;
}

// Read input from command line
void get_input(char* args[], int* should_run) {
  char input_buffer[MAX_LINE];
  char* token;
  int position;

  // Read input
  fgets(input_buffer, MAX_LINE, stdin);

  // Parse input into tokens
  token = strtok(input_buffer, " \n");
  position = 0;

  while (token != NULL) {
    args[position] = token;
    position++;

    token = strtok(NULL, " \n");
  }

  args[position] = NULL;

  // Check for exit command
  if (strcmp(args[0], "exit") == 0) {
    *should_run = 0;
  }
}

// Execute command
void execute_command(char* args[]) {
  pid_t pid;
  int status;

  pid = fork();

  if (pid < 0) {
    printf("Fork failed\n");
    exit(1);
  } else if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      printf("Command not found\n");
      exit(1);
    }
  } else {
    // Parent process
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}