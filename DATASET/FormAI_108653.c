//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_ARGS 10
#define BUFFER_SIZE 1024

int main(){

    char input_buffer[BUFFER_SIZE];
    char *args[MAX_ARGS];
    int status;

    while(1){
        printf("mysh$ ");
        fgets(input_buffer, BUFFER_SIZE, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0'; //remove new line character

        int i = 0;
        char *current_arg = strtok(input_buffer, " ");

        while(current_arg != NULL && i<MAX_ARGS-1){
            args[i++] = current_arg;
            current_arg = strtok(NULL, " ");
        }
        args[i] = NULL;

        if(args[0] == NULL){ //empty command
            continue;
        }

        if(strcmp(args[0], "exit") == 0){ //exit shell
            exit(0);
        }

        pid_t pid = fork();

        if(pid == -1){ //fork error
            perror("fork");
            exit(1);
        }

        if(pid == 0){ //child process
            if(execvp(args[0], args) == -1){ //execute command
                perror("execvp");
                exit(1);
            }
            exit(0);
        }

        else{ //parent process
            waitpid(pid, &status, 0); //wait for child process to finish
        }
        
    }

    return 0;
}