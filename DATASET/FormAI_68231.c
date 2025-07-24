//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_NUM 50
#define PROMPT ">> "

int main(int argc, char *argv[]) {
  char cmd[MAX_CMD_LEN];
  char *args[MAX_ARG_NUM];
  int status;
  char *token;

  printf("Welcome to Unix-like Shell\n\n");

  while(1) {
    printf(PROMPT);
    fflush(stdout);

    fgets(cmd, MAX_CMD_LEN, stdin);

    if(cmd[0] == '\n') {
      printf("Enter a command\n");
      continue;
    }

    if(strlen(cmd)-1 > MAX_CMD_LEN) {
      printf("Command too long\n");
      continue;
    }

    for(int i=0; i<MAX_ARG_NUM; i++) args[i] = NULL;

    args[0] = strtok(cmd, " \n");

    for(int i=1; i<MAX_ARG_NUM; i++) {
      if(args[i-1] == NULL) break;
      args[i] = strtok(NULL, " \n");
    }
  
    if(strcmp(args[0], "exit") == 0) {
      printf("Goodbye\n");
      break;
    }

    pid_t pid = fork();

    if(pid < 0) {
      printf("Failed to execute command\n");
      continue;
    }

    if(pid == 0) {
      execvp(args[0], args);
      printf("Command not found\n");
      exit(1);
    }
    
    wait(&status);

    if(WIFSIGNALED(status)) {
      printf("Command terminated by signal %d\n", WTERMSIG(status));
    }
  }

  return 0;
}