//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

// define maximum command length and maximum arguments in command
#define MAX_CMD_LEN 100
#define MAX_ARGS 10

// function to parse the command and arguments
void parse_args(char* cmd, char** args){
    int i = 0;
    char* arg = strtok(cmd, " ");

    while(arg != NULL){
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;
}

// function to execute the command
void execute(char** args){

    // fork a child process
    pid_t pid = fork();

    if(pid < 0){
        printf("Error: Failed to fork child process.\n");
        exit(-1);
    }
    else if(pid == 0){
        // child process
        if(execvp(args[0], args) < 0){
            printf("Error: Failed to execute command.\n");
            exit(-1);
        }
    }
    else{
        // parent process
        wait(NULL);
    }
}

int main(){
    char cmd[MAX_CMD_LEN];
    char* args[MAX_ARGS];

    while(1){
        printf(">>");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // remove new line character
        cmd[strcspn(cmd, "\n")] = 0;

        // exit shell if command is exit
        if(strcmp(cmd, "exit") == 0){
            exit(0);
        }

        // parse the command
        parse_args(cmd, args);

        // execute the command
        execute(args);
    }

    return 0;
}