//FormAI DATASET v1.0 Category: System administration ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

void enterCommand(char *command){
    printf("Enter command: ");
    fgets(command, 100, stdin);
    command[strcspn(command, "\n")] = 0;
}

void executeCommand(char *command){
    pid_t pid;
    int status;
    char *args[50];

    pid = fork();

    if(pid == -1){
        printf("\n Error: Unable to fork child process\n");
        exit(0);
    }

    if(pid == 0){
        char *token = strtok(command, " ");
        for(int i = 0; i < 50 && token != NULL; i++){
            args[i] = token;
            token = strtok(NULL, " ");
        }
        args[49] = NULL;

        if(execvp(args[0], args) < 0){
            printf("\nError executing command\n");
            exit(0);
        }
    }
    else{
        waitpid(-1, &status, 0);
    }
}

int main(){
    char command[100];

    while(1){
        enterCommand(command);

        if(strcmp(command, "exit") == 0){
            exit(0);
        }

        executeCommand(command);
    }

    return 0;
}