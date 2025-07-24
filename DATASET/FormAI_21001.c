//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_CMD_LENGTH 50

int main(){
    char cmd[MAX_CMD_LENGTH], *args[MAX_ARGS];
    pid_t pid;
    int status;
    while(1){
        printf("myshell> ");
        if(fgets(cmd, MAX_CMD_LENGTH, stdin)==NULL)
            break;
        cmd[strlen(cmd)-1] = '\0'; // remove trailing newline
        int i = 0;
        args[i] = strtok(cmd, " \t");
        while(args[i]!=NULL && i<MAX_ARGS-1){
            i++;
            args[i] = strtok(NULL, " \t");
        }
        args[i+1] = NULL;
        if(args[0]!=NULL){
            pid = fork();
            if(pid<0){
                printf("fork failed\n");
                exit(EXIT_FAILURE);
            }
            else if(pid==0){
                execvp(args[0], args);
                printf("exec failed\n");
                exit(EXIT_FAILURE);
            }
            else{
                wait(&status);
            }
        }
    }
    return 0;
}