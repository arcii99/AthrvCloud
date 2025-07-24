//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

void execute(char **cmd_tokens) {
    if (execvp(cmd_tokens[0], cmd_tokens) == -1) {
        printf("Command not found. \n");
        exit(EXIT_FAILURE);
    }
}

void tokenize(char* cmd_str, char** cmd_tokens) {
    char* token;
    int i = 0;
    token = strtok(cmd_str, " ");
    while(token != NULL){
        cmd_tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    cmd_tokens[i] = NULL;   
}

int main(int argc, char* argv[]) {
    char cmd_input[MAX_CMD_LENGTH];
    char* cmd_tokens[MAX_ARGS];

    while(1) {
        printf(">> ");
        fgets(cmd_input, MAX_CMD_LENGTH, stdin);
        cmd_input[strcspn(cmd_input, "\n")] = 0; // remove newline character from input string
        pid_t proc_id = fork();

        if(proc_id < 0){
            printf("Forking failed.\n");
            exit(1);
        }

        if(proc_id == 0){
            tokenize(cmd_input, cmd_tokens);
            execute(cmd_tokens);
            exit(EXIT_SUCCESS);
        } else {
            wait(NULL);
        }
    }
    return 0;
}