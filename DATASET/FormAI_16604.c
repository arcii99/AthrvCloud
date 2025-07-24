//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void type_prompt(){
    printf("\n>>> ");
}

void read_command(char* command, char** parameters){
    char input[MAX_INPUT_SIZE];
    char* token;
    int token_count = 0;
    
    fgets(input, MAX_INPUT_SIZE, stdin);
    token = strtok(input, " \n");
    
    while(token != NULL && token_count < MAX_NUM_TOKENS){
        parameters[token_count] = strdup(token);
        token_count++;
        token = strtok(NULL, " \n");
    }
    
    parameters[token_count] = NULL;
    strcpy(command, parameters[0]);
}

int main(){
    char command[MAX_INPUT_SIZE];
    char* parameters[MAX_NUM_TOKENS];
    pid_t child_pid;
    int status;
    
    while(1){
        type_prompt();
        read_command(command, parameters);
        
        if(strcmp(command, "exit") == 0){
            break;
        }
        
        child_pid = fork();
        
        if(child_pid == 0){
            //child process
            execvp(command, parameters);
            printf("*** ERROR: exec failed\n");
            exit(1);
        }
        else{
            //parent process
            waitpid(child_pid, &status, 0);
        }
    }
    return 0;
}