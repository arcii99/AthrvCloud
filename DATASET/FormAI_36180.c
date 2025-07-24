//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  char input[100];
  char *args[10][10]; //array to store tokens for each input
  int cmd_count = 0; //counter for number of commands entered

  printf("\nWelcome to the shape shifting shell!\n");

  while (1) {
    printf("\nEnter a command: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; //removes newline character from input string

    if (strcmp(input, "exit") == 0) { //exit if user enters "exit"
      printf("\nGoodbye!\n");
      exit(0);
    }

    //split input into tokens
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
      args[cmd_count][i++] = token;
      token = strtok(NULL, " ");
    }
    args[cmd_count][i] = NULL;

    pid_t pid = fork();
    
    if (pid < 0) { //fork error handling
      perror("Error forking process");
      exit(1);
    } 
    else if (pid == 0) { //child process
      if (execvp(args[cmd_count][0], args[cmd_count]) < 0) { 
        perror("Error executing command");
        exit(1);
      }
    } 
    else { //parent process
      wait(NULL); //wait for child process to finish
    }

    cmd_count++;
  }
  return 0;
}