//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
#define MAX_ARG_LEN 20
#define MAX_ARGS_NUM 10

int main() {
  char cmd[MAX_CMD_LEN], *buf = NULL, *arg_arr[MAX_ARGS_NUM], *tok = NULL;
  int i, status, arg_num;
  size_t buf_size = 0;
  pid_t pid;

  while(1) {
    printf("linuxish-shell> ");
    getline(&buf, &buf_size, stdin);

    if(strcmp(buf, "exit\n") == 0) {
      exit(0);
    }

    tok = strtok(buf, " \n");
    arg_num = 0;
    while(tok != NULL && arg_num < MAX_ARGS_NUM) {
      arg_arr[arg_num] = tok;
      tok = strtok(NULL, " \n");
      arg_num++;
    }
    arg_arr[arg_num] = NULL;

    if((pid = fork()) < 0) {
      perror("Fork error");
    } else if(pid == 0) {
      if(execvp(arg_arr[0], arg_arr) < 0) {
        perror("Execution error");
        exit(1);
      }
    } else {
      waitpid(pid, &status, 0);
    }
  }
  return 0;
}