//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int tokenize(char* line, char* tokens[], char* delim){
    int token_count = 0;
    char* token = strtok(line, delim);

    while(token != NULL && token_count < MAX_NUM_TOKENS){
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, delim);
    }

    return token_count;
}

int main(){
    char line[MAX_INPUT_SIZE];            
    char* tokens[MAX_NUM_TOKENS];         
    char* cmd;                             
    char* args[MAX_NUM_TOKENS];             
    int token_count;                       
    int i, status;                         

    while (1) {                             
        printf("shell> ");                   
        fgets(line, MAX_INPUT_SIZE, stdin);   

        token_count = tokenize(line, tokens, " \n");
        
        if(token_count == 0){
            continue;
        }

        cmd = tokens[0];

        if(strcmp(cmd, "exit") == 0){
            exit(0);
        }

        for(i=0; i<token_count; i++){
            args[i] = tokens[i];
        }
        args[i] = NULL;                      

        if(fork() == 0){
            execvp(cmd, args);
            printf("ERROR: Unknown command\n");
            exit(0);
        }
        else{
            wait(&status);
        }
    }
    
    return 0;
}