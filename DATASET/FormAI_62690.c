//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    char command[200];
    while(1){
        printf("Enter a puzzle: ");
        scanf("%[^\n]", command);
        getchar();

        if(strcmp(command, "solve this puzzle")==0){
            printf("Congrats! You solved it.\n");
        }
        else if(strcmp(command, "what is the meaning of life?")==0){
            printf("Sorry, that's a question I cannot solve.\n");
        }
        else if(strcmp(command, "exit")==0){
            printf("Exiting Program.\n");
            exit(0);
        }
        else{
            pid_t pid=fork();
            if(pid==0){
                char *args[]={"/bin/bash", "-c", command, NULL};
                execvp(args[0],args);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
    }
    return 0;
}