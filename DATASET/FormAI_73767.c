//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 100
#define MAX_LENGTH 1024

void executeCommands(char* commands[]);
void readCommands(char* commandLine, char* commands[]);

int main(){
  char* commands[MAX_COMMANDS];
  char commandLine[MAX_LENGTH];

  while (1){
    printf("MyShell> ");
    fgets(commandLine, MAX_LENGTH, stdin);

    // Remove trailing newline
    commandLine[strcspn(commandLine, "\n")] = 0;
    if (strcmp(commandLine, "exit") == 0){
      printf("Exiting MyShell...\n");
      break;
    }

    readCommands(commandLine, commands);
    executeCommands(commands);
  }

  return 0;
}

void readCommands(char* commandLine, char* commands[]){
  int i = 0;

  commands[i] = strtok(commandLine, " ");
  while (commands[i] != NULL && i < MAX_COMMANDS){
    i++;
    commands[i] = strtok(NULL, " ");
  }
  commands[i] = NULL;
}

void executeCommands(char* commands[]){
  pid_t pid = fork();

  if (pid == 0){
    // Child process
    execvp(commands[0], commands);
    printf("Command not found: %s\n", commands[0]);
    exit(1);
  } else if (pid < 0){
    // Error forking
    printf("Error forking!\n");
    exit(1);
  } else {
    // Parent process
    wait(NULL);
  }
}