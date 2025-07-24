//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_CMD 10
#define MAX_ARGS 10
#define MAX_ARG_LEN 100

int main(){
  char cmd[MAX_CMD][MAX_ARG_LEN];
  char args[MAX_CMD][MAX_ARGS][MAX_ARG_LEN];
  int cmd_count;
  int arg_count[MAX_CMD];
  int i, j;
  pid_t pid;
  int status;

  while(1){
    printf(">>>");
    fflush(stdout);
    fgets(cmd[0], MAX_ARG_LEN, stdin);

    cmd_count = 0;
    arg_count[cmd_count] = 0;

    for(i=0; i<strlen(cmd[0]); i++){
      if(cmd[0][i] == '\n'){
        cmd[0][i] = '\0';
        break;
      }
      else if(cmd[0][i] == ' '){
        cmd_count++;
        arg_count[cmd_count] = 0;
      }
      else{
        if(arg_count[cmd_count] == 0){
          snprintf(args[cmd_count][arg_count[cmd_count]], MAX_ARG_LEN, "%s", cmd[cmd_count]);
        }
        snprintf(args[cmd_count][arg_count[cmd_count]], MAX_ARG_LEN, "%s %c", args[cmd_count][arg_count[cmd_count]], cmd[0][i]);
      }
    }

    cmd_count++;

    if(strcmp(cmd[0], "exit") == 0){
      printf("Exiting Shell\n");
      exit(0);
    }

    int pipes[MAX_CMD][2];

    for(i=0; i<cmd_count; i++){
      if(pipe(pipes[i]) == -1){
        printf("Error: Pipe Failed\n");
        exit(1);
      }

      pid = fork();

      if(pid < 0){
        printf("Error: Fork Failed\n");
        exit(1);
      }
      else if(pid == 0){
        if(i > 0){
          if(dup2(pipes[i-1][0], STDIN_FILENO) == -1){
            printf("Error: Duplication Failed\n");
            exit(1);
          }
        }

        if(i != cmd_count-1){
          if(dup2(pipes[i][1], STDOUT_FILENO) == -1){
            printf("Error: Duplication Failed\n");
            exit(1);
          }
        }

        for(j=0; j<cmd_count; j++){
          if(close(pipes[j][0]) == -1){
            printf("Error: Pipe Failed\n");
            exit(1);
          }

          if(close(pipes[j][1]) == -1){
            printf("Error: Pipe Failed\n");
            exit(1);
          }
        }

        char *command[MAX_ARGS];
        for(j=0; j<arg_count[i]; j++){
          command[j] = args[i][j];
        }
        command[j] = NULL;

        if(execvp(command[0], command) == -1){
          printf("%s: Command not found\n", command[0]);
          exit(1);
        }
      }
      else{
        if(close(pipes[i][1]) == -1){
          printf("Error: Pipe Failed\n");
          exit(1);
        }
      }
    }

    for(i=0; i<cmd_count; i++){
      if(wait(&status) == -1){
        printf("Error: Wait Failed\n");
        exit(1);
      }
    }

    for(i=0; i<cmd_count; i++){
      if(close(pipes[i][0]) == -1){
        printf("Error: Pipe Failed\n");
        exit(1);
      }

      if(close(pipes[i][1]) == -1){
        printf("Error: Pipe Failed\n");
        exit(1);
      }
    }
  }

  return 0;
}