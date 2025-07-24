//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
/*Hey there! I am a Unix-like shell program written in C.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_NUM_ARGUMENTS 10

int main()
{
  char command[MAX_COMMAND_LENGTH];
  char *arguments[MAX_NUM_ARGUMENTS];

  while(1)
  {
    /* Get user input */
    printf("$ ");
    fgets(command,MAX_COMMAND_LENGTH,stdin);

    /* Parse command and arguments */
    char *token = strtok(command," \n");
    int i = 0;
    while(token != NULL)
    {
      arguments[i] = token;
      token = strtok(NULL," \n");
      i++;
    }
    arguments[i] = NULL;

    /* Ignore empty commands */
    if(i == 0)
    {
      continue;
    }

    /* Exit the shell if user enters 'exit' */
    if(strcmp(arguments[0], "exit") == 0)
    {
      printf("Exiting shell...\n");
      break;
    }

    /* Fork and execute the command */
    pid_t pid = fork();

    /* Handle errors */
    if(pid < 0)
    {
      printf("Error: Fork failed.\n");
      continue;
    }
    else if(pid == 0)
    {
      /* Child process */
      execvp(arguments[0],arguments);
      printf("Error: Exec failed.\n");
      exit(EXIT_FAILURE);
    }
    else
    {
      /* Parent process */
      int status;
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}