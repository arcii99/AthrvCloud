//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define BUFFER_SIZE 128

int main(){
    char input[BUFFER_SIZE];    //string to hold user input
    char *args[10];             //array to hold arguments 

    printf("Wake up, samurai! It's time to enter the Cyberworld.\n");
    printf("Initiating Cyber Shell...\n");

    while(1){
        printf("> "); //prompt for user input
        fgets(input, BUFFER_SIZE, stdin); //read user input

        input[strcspn(input, "\n")] = 0; //remove trailing newline

        if(strcmp(input, "exit") == 0){ //check if user wants to exit
            printf("Exiting Cyber Shell...\n");
            exit(0);
        }

        int i=0;
        args[i] = strtok(input, " "); //split user input by space delimiter
        while(args[i] != NULL){
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i] = NULL; //make last element NULL for execvp

        pid_t pid = fork(); //create child process

        if(pid == -1){ //fork error
            perror("fork");
            exit(1);
        }

        else if(pid == 0){ //child process
            if(execvp(args[0], args) == -1){ //execute command
                printf("Command not found, samurai.\n");
                exit(1);
            }
        }

        else{ //parent process
            int status;
            waitpid(pid, &status, 0); //wait for child process to complete
        }
    }
    return 0;
}