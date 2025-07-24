//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1000
#define MAX_ARGS 100

void display_prompt(){
    printf("my_shell> ");
}

void execute_cmd(char** args){
    pid_t pid = fork();

    if(pid < 0){
        printf("Error: Fork failed!\n");
        exit(1);
    } else if (pid == 0){
        // Child process
        if(execvp(args[0], args) < 0){
            printf("Error: Command not found or could not be executed!\n");
            exit(1);
        }
    } else {
        // Parent process
        wait(NULL);
    }
}

void tokenize_cmd(char* cmd, char** args){
    int i = 0;
    char* token = strtok(cmd, " \n\r\t");

    while(token != NULL){
        args[i++] = token;
        token = strtok(NULL, " \n\r\t");
    }

    args[i] = NULL;
}

int main(){
    char cmd[MAX_CMD_LEN];
    char* args[MAX_ARGS];

    while(1){
        display_prompt();

        if(fgets(cmd, MAX_CMD_LEN, stdin) == NULL){
            printf("\n");
            exit(0);
        }

        tokenize_cmd(cmd, args);

        if(args[0] != NULL){
            execute_cmd(args);
        }
    }

    return 0;
}