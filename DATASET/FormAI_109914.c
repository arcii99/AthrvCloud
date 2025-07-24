//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024

int main(){
    char command[MAX_BUFFER];
    char *args[MAX_BUFFER/2+1];
    int should_run = 1;
    
    while(should_run){
        printf(">>> ");
        fflush(stdout);
        
        fgets(command, MAX_BUFFER, stdin);
        command[strlen(command)-1] = '\0';
        
        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;
        
        if(strcmp(args[0], "exit") == 0){
            should_run = 0;
            continue;
        }
        
        pid_t pid = fork();
        if(pid < 0){
            printf("Error: fork() failed\n");
            continue;
        } else if (pid == 0) {
            if(execvp(args[0], args) == -1){
                printf("Error: command not found\n");
                exit(0);
            }
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    return 0;
}