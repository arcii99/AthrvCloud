//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LENGTH 1024

//function to print current directory
void shell_prompt(){
    char cwd[MAX_LENGTH], *username;
    username = getenv("USER");
    getcwd(cwd, sizeof(cwd));
    printf("%s@ %s> ",username, cwd);
}

//function to parse user input
void parse_input(char* buffer, char** args, int* num_args){
    //parse the buffer and add the arguments to the args array
    char* token;
    token = strtok(buffer, " \r\n\t");
    int i = 0;
    while(token != NULL){
        args[i++] = token;
        token = strtok(NULL, " \r\n\t");
    }
    //set the last argument to NULL for execvp
    args[i] = NULL;
    *num_args = i;
}

int main(){
    printf("Welcome to My Shell!\n");
    while(1){
        shell_prompt();
        char buffer[MAX_LENGTH];
        char* args[MAX_LENGTH/2 + 1];
        int num_args = 0;
        
        //read user input
        fgets(buffer, MAX_LENGTH, stdin);
        
        //parse user input
        parse_input(buffer, args, &num_args);
        
        //check if user wants to exit shell
        if(strcmp(args[0],"exit") == 0){
            printf("Exiting My Shell...\n");
            return 0;
        }
        
        //fork child process to execute user command
        pid_t pid;
        pid = fork();
        
        if(pid == 0){
            //child process
            execvp(args[0], args);
            printf("My Shell: Command not found: %s\n", args[0]);
            exit(1);
        }
        else if(pid < 0){
            printf("My Shell: Fork error!\n");
        }
        else{
            //parent process
            wait(NULL);
        }
    }
    return 0;
}