//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

/* Surrealistic-style Unix-like Shell */

int main(){
    printf("Welcome to the Surrealistic Shell!\n");
    printf("Type 'exit' to leave the shell.\n");

    char command[100], *args[20];
    int status = 1;

    while(status){
        printf(">>> ");
        fgets(command, 100, stdin);
        int i = 0;

        while(command[i] != '\n'){
            i++;
        }
        command[i] = '\0';

        if(strcmp(command, "exit") == 0){
            status = 0;
        }
        else{
            char *token = strtok(command, " ");
            int j = 0;

            while(token != NULL){
                args[j] = token;
                token = strtok(NULL, " ");
                j++;
            }

            args[j] = NULL;

            pid_t pid = fork();

            if(pid == 0){
                execvp(args[0], args);
                printf("Command not found\n");
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
    }
    printf("Leaving the surrealistic shell. Goodbye!\n");
    return 0;
}