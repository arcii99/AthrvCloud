//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_ARGS 10 //Maximum number of arguments 
#define MAX_LENGTH 100 //Maximum length of string
#define MAX_HISTORY 20 //Maximum number of commands to be saved in history

int main(int argc, char *argv[]) {
    char input[MAX_LENGTH]; //To store input command
    char *tokens[MAX_ARGS]; //Command tokens for each argument
    char *history[MAX_HISTORY]; //To store commands in history
    int count = 0; //To keep track of history count
    int i, j, status;
    
    for(i = 0; i < MAX_HISTORY; i++) {
        history[i] = NULL; //Initialising history array to NULL
    }
    
    while(1) {
        printf(">> ");
        fgets(input, MAX_LENGTH, stdin); //Getting input command from user
        
        //Removing newline character from input
        if(input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }
        
        //Checking if command was entered
        if(strcmp(input, "") == 0) {
            continue;
        }
        
        //Command to exit shell
        if(strcmp(input, "exit") == 0) {
            exit(0);
        }
        
        //Command to view history
        if(strcmp(input, "history") == 0) {
            printf("\nCommand History:\n");
            for(i = count - 1; i >= 0; i--) {
                printf(" %d %s\n", i+1, history[i]);
            }
            continue;
        }
        
        //Adding command to history
        history[count % MAX_HISTORY] = strdup(input);
        count++;
        
        //Parsing input command into tokens
        tokens[0] = strtok(input, " ");
        
        for(i = 1; i < MAX_ARGS; i++) {
            tokens[i] = strtok(NULL, " ");
            if(tokens[i] == NULL) {
                break;
            }
        }
        
        //Built-in commands
        if(strcmp(tokens[0], "cd") == 0) {
            if(chdir(tokens[1]) != 0) {
                perror("cd");
            }
            continue;
        }
        
        //Executing commands
        pid_t pid = fork();
        
        if(pid < 0) {
            fprintf(stderr, "Error forking process\n");
            exit(1);
        } else if(pid == 0) {
            if(execvp(tokens[0], tokens) < 0) {
                fprintf(stderr, "Error executing command\n");
            }
            exit(0);
        } else {
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}