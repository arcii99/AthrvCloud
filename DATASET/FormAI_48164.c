//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_INPUT_SIZE 1024
#define DELIMITER " "

int main() {
  char* input = (char*) malloc(sizeof(char) * MAX_INPUT_SIZE);
  char* args[MAX_ARGS];
  int status = 0;
  
  while (1) {
    printf(">> ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strlen(input) - 1] = '\0';
    
    if (strcmp(input, "exit") == 0) break;
    
    int i = 0;
    args[i] = strtok(input, DELIMITER);
    while(args[i] != NULL && i < MAX_ARGS) {
      i++;
      args[i] = strtok(NULL, DELIMITER);
    }
    args[i] = NULL;
    
    pid_t pid = fork();
    
    if (pid == 0) {
      execvp(args[0], args);
      printf("Error: Unknown command found.\n");
      return -1;
    }
    else if (pid < 0) {
      printf("Error: Failed to fork.\n");
    }
    else {
      wait(&status);
    }
  }
  
  printf("Exiting shell.\n");
  free(input);
  return 0;
}