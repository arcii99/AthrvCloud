//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */
#define MAX_HISTORY 10 /* The maximum number of recent commands */

void printHistory(char **history, int historyIndex);
int parseCommand(char *command, char **args);
int executeCommand(char **args, char **history, int *historyIndex);

int main(void) {
  char *args[MAX_LINE/2 + 1]; /* Command line arguments */
  char *history[MAX_HISTORY]; /* Array to store recent commands */
  int running = 1; /* Flag for running the shell */
  int historyIndex = 0; /* Index for storing recent commands */
  char command[MAX_LINE]; /* Command entered by user */
  int shouldRun = 1; /* Flag for if the shell should continue running */

  // Initialize recent commands array to null
  for (int i = 0; i < MAX_HISTORY; i++) {
    history[i] = NULL;
  }

  while (shouldRun) {
    printf("osh>");
    fflush(stdout);

    // Read and parse command from user
    fgets(command, MAX_LINE, stdin);
    int length = strlen(command);
    if (command[length - 1] == '\n') {
      command[length - 1] = '\0';
    }
    int numArgs = parseCommand(command, args);

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0) {
      shouldRun = 0;
    } else if (strcmp(args[0], "history") == 0) {
      printHistory(history, historyIndex);
    } else {
      // Execute command
      int status = executeCommand(args, history, &historyIndex);
      if (status == 0) {
        // Save recent command to history
        history[historyIndex] = malloc(strlen(command) + 1);
        strcpy(history[historyIndex], command);
        historyIndex = (historyIndex + 1) % MAX_HISTORY;
      }
    }
  }

  // Free memory used for recent commands
  for (int i = 0; i < MAX_HISTORY; i++) {
    free(history[i]);
  }

  return 0;
}

// Function to print recent commands
void printHistory(char **history, int historyIndex) {
  if (historyIndex == 0) {
    printf("No commands in history.\n");
  } else if (historyIndex < MAX_HISTORY) {
    for (int i = 0; i < historyIndex; i++) {
      printf("%d %s\n", i, history[i]);
    }
  } else {
    for (int i = historyIndex; i < MAX_HISTORY; i++) {
      printf("%d %s\n", i, history[i]);
    }
    for (int i = 0; i < historyIndex; i++) {
      printf("%d %s\n", i + MAX_HISTORY, history[i]);
    }
  }
}

// Function to parse command line arguments
int parseCommand(char *command, char **args) {
  int numArgs = 0;
  char *delim = " \t\r\n\a";
  char *token = strtok(command, delim);
  while (token != NULL) {
    args[numArgs] = token;
    numArgs++;
    token = strtok(NULL, delim);
  }
  args[numArgs] = NULL;
  return numArgs;
}

// Function to execute command
int executeCommand(char **args, char **history, int *historyIndex) {
  int shouldWait = 1;
  int numArgs = 0;
  // Check if command should run in the background
  while (args[numArgs] != NULL) {
    if (strcmp(args[numArgs], "&") == 0) {
      shouldWait = 0;
      args[numArgs] = NULL;
      break;
    }
    numArgs++;
  }

  pid_t pid = fork();
  if (pid < 0) {
    printf("Fork failed.\n");
    exit(1);
  } else if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      printf("Invalid command.\n");
      exit(1);
    }
  } else {
    // Parent process
    if (shouldWait) {
      wait(NULL);
    }
    return 0;
  }
}