//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define BUFFER_SIZE 256 //maximum size of the input command
#define MAX_ARGS 10 //maximum number of arguments in the command

int main(){
    char input[BUFFER_SIZE]; //input string
    char* args[MAX_ARGS]; //array of arguments
    pid_t child_pid; //child process id
    int status; //status of child process

    while(1){ //infinite loop for shell
        printf("$ "); //print shell prompt
        fgets(input, BUFFER_SIZE, stdin); //read input

        //parse input
        char* token = strtok(input, " ");
        int i = 0;
        while(token != NULL){
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i-1][strlen(args[i-1])-1] = '\0'; //remove newline character

        //execute command
        child_pid = fork(); //create child process
        if(child_pid < 0){ //fork error
            perror("Fork error");
        }
        else if(child_pid == 0){ //child process
            if(execvp(args[0], args) == -1){ //execute command
                perror("Exec error");
                exit(EXIT_FAILURE); //exit child process on error
            }
        }
        else{ //parent process
            waitpid(child_pid, &status, WUNTRACED); //wait for child process to finish
        }
    }

    return 0;
}