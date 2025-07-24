//FormAI DATASET v1.0 Category: System administration ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

int main(){

    char cmd[MAX_CMD_LEN];
    char* args[MAX_ARGS];
    int arg_count;

    while(1){
        printf(">");
        fgets(cmd, MAX_CMD_LEN, stdin);

        //remove the newline character from the end of cmd
        cmd[strcspn(cmd, "\n")] = 0;

        //parse the command into separate arguments
        char* arg_string = strtok(cmd, " ");
        arg_count = 0;
        while(arg_string != NULL && arg_count < MAX_ARGS-1){
            args[arg_count++] = arg_string;
            arg_string = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        if(arg_count > 0){
            if(fork() == 0){
                execvp(args[0], args);  //execute the command
                printf("Command not found\n");
                exit(0);
            }
            else{
                wait(NULL);  //wait for child process to finish
            }
        }
    }

    return 0;
}