//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>

#define MAX_ARGS 10
#define MAX_INPUT_SIZE 1000

char input[MAX_INPUT_SIZE];

char *args[MAX_ARGS];

volatile sig_atomic_t child_pid;

void handle_sigint(int sig){
    if(child_pid){
        kill(child_pid, SIGINT);
    }
}

int tokenize_input(char *input){
    int i = 0;
    args[i] = strtok(input, " \n");
    while(args[i] != NULL && i < MAX_ARGS){
        args[++i] = strtok(NULL, " \n");
    }
    return i;
}

void run_command(char *input){
    int num_tokens = tokenize_input(input);
    if(num_tokens == 0) return;
    if(strcmp(args[0], "exit") == 0){
        exit(0);
    }
    child_pid = fork();
    if(child_pid == 0){
        if(execvp(args[0], args) == -1){
            perror(args[0]);
        }
        exit(-1);
    }
    else if(child_pid > 0){
        int status;
        waitpid(child_pid, &status, 0);
        child_pid = 0;
    }
    else{
        perror("Failed to fork process");
    }
    memset(input, 0, sizeof(MAX_INPUT_SIZE));
    memset(args, 0, sizeof(char*)*MAX_ARGS);
}

int main(){
    signal(SIGINT, handle_sigint);
    while(1){
        printf("sh > ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        if(strlen(input) <= 1) continue;
        run_command(input);
    }
    return 0;
}