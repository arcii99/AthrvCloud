//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 10
#define MAX_BUFFER_SIZE 1024

int main(){
    char command[MAX_COMMANDS][MAX_ARGS][MAX_BUFFER_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    int command_count=0;
    char* token;

    printf("Simple Shell\n");
    printf("Enter command(s)\n");

    while(1){
        memset(&command[command_count], 0, sizeof(command[command_count]));
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        buffer[strlen(buffer)-1] = '\0';

        token = strtok(buffer, " ");
        int arg_count = 0;
        while(token != NULL){
            strcpy(command[command_count][arg_count], token);
            token = strtok(NULL, " ");
            arg_count++;
        }

        if(strcmp(command[command_count][0], "quit") == 0){
            break;
        }

        command_count++;

        int pid = fork();
        if (pid == -1){
            printf("Error while creating new process.\n");
        }
        else if (pid == 0){
            char* args[MAX_ARGS];
            for(int i = 0; i<arg_count;++i){
                args[i] = command[command_count-1][i];
            }
            args[arg_count] = NULL;
            int res = execvp(args[0], args);
            if (res == -1){
                printf("Error executing command: %s\n", args[0]);
            }
            exit(-1);
        }
        else{
            int status;
            waitpid(-1, &status, 0);
        }
    }
    return 0;
}