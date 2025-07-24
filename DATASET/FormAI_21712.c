//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_LINE 80
#define BUFFER_SIZE 50

char buffer[BUFFER_SIZE];

int main(void){
    char *args[MAX_LINE/2 + 1];
    int should_run = 1; 
    int background = 0;
    pid_t pid;
    int status;
    printf("Mind-bending Shell Program\n");
    printf("==========================\n");
    fflush(stdout);

    while (should_run){
        printf("Mind-bending$ ");
        fflush(stdout);

        fgets(buffer, BUFFER_SIZE, stdin);
        if(strlen(buffer) <= 1){
            continue;
        }
        char *token = strtok(buffer,"\n");

        if(strcmp(token, "exit") == 0){
            should_run = 0;
            break;
        }
        int index = 0;
        char **temp_args = malloc(sizeof(char*)*(MAX_LINE/2 + 1));

        token = strtok(token," ");
        while(token != NULL){
            if(strcmp(token, "&") == 0){
                background = 1;
            }
            temp_args[index++] = token;

            token = strtok(NULL," ");
        }
        temp_args[index] = NULL;

        args[0] = temp_args[0];

        int i; 
        for(i = 1;i<index && temp_args[i] != NULL;i++){
            if(strcmp(temp_args[i-1], "&") != 0){
                args[i] = temp_args[i];
            }
            else{
                args[i-1] = NULL;
                args[i] = NULL;
                break;
            }
        }
        
        if ((pid = fork()) < 0) {    
            perror("Fork error");
            exit(1);
        }
        else if (pid == 0) {      
            if(background) {
                freopen("/dev/null", "w", stdout);
                freopen("/dev/null", "w", stderr);
            }
            execvp(args[0], args);
            printf("Invalid command\n");
            exit(0);
        }
        else if(background){
            printf("Background process created with PID %d\n",pid);
        }
        else {
            waitpid(-1, &status, 0);
        }
        background = 0;
    }

    return 0;
}