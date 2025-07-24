//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define DELIMITER " \t\r\n\a"

void print_prompt() {
  printf("Thou art ready to enter thy command, my lord!>\n");
}

void read_input(char *input_string) {
  fgets(input_string,MAX_INPUT,stdin);
}

int parse_input(char *input_string, char **input_args) {
  int arg_count = 0;
  char *arg;

  arg = strtok(input_string, DELIMITER);
  while(arg != NULL) {
    input_args[arg_count++] = arg;
    arg = strtok(NULL, DELIMITER);
  }
  input_args[arg_count] = NULL;
  return arg_count;
}

void execute_command(char **input_args) {
  pid_t pid;
  int status;

  pid = fork();
  if(pid < 0) {
    printf("Error: Could not create process, my lord!\n");
    exit(EXIT_FAILURE);
  } else if(pid == 0) {
    if(execvp(input_args[0], input_args) == -1) {
      printf("Error: Could not execute command, my lord!\n");
      exit(EXIT_FAILURE);
    }
  } else {
    do {
      waitpid(pid, &status, WUNTRACED);
    } while(!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}

int main() {
  char input_string[MAX_INPUT];
  char *input_args[MAX_ARGS];
  int arg_count;

  while(1) {
    print_prompt();
    read_input(input_string);
    arg_count = parse_input(input_string, input_args);
    if(strcmp(input_args[0],"exit") == 0) {
      printf("Thou hast left the Shell, my lord! Fare thee well.\n");
      break;
    } else {
      execute_command(input_args);
    }
  }
  return 0;
}