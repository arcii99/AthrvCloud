//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_ARG_LEN 50

int main(){
    char input[100];
    char* args[MAX_ARGS];
    int status;
    
    while(1){
        printf("$ ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';  // remove newline character
        
        // parse the input
        char* token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS){
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
        
        //fork the process
        pid_t pid = fork();
        
        if(pid == -1){
            printf("Error: Failed to fork process.\n");
            exit(1);
        }
        else if(pid == 0){
            //child process
            execvp(args[0], args);
            printf("Error: Command not found.\n");
            exit(1);
        }
        else{
            //parent process
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}