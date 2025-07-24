//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

//Custom prompt
#define PROMPT "\033[0;32mCyberPunk-Shell$ \033[0m"

int main(){
    char input[1024];
    while(1){
        printf(PROMPT);
        fgets(input, 1024, stdin); //Takes user input
        input[strcspn(input, "\r\n")] = 0; //Removes the trailing newline character
        if(strcmp(input, "exit") == 0) //If the user input matches "exit", the program terminates
            break;
        
        char* arguments[64];
        char* token = strtok(input, " "); //Tokenizes the user input by spaces
        
        int i = 0;
        while(token != NULL){
            arguments[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        arguments[i] = NULL;
        
        //Execution
        pid_t child_pid = fork();
        if(child_pid == 0){
            execvp(arguments[0], arguments);
            exit(0);
        }
        else{
            wait(NULL);
        }
    }
    return 0;
}