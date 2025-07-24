//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    char command[100]; // To store the command entered by user
    while(1){ // Loop to continuously accept commands    
        printf(">> "); // Display prompt
        fgets(command, 100, stdin); // Get input and store in command        
        int arg_len = strlen(command); // Calculate length of command string        
        command[arg_len-1] = '\0'; // Set last character to NULL        
        char *args[10]; // Array to store arguments after parsing command        
        args[0] = strtok(command, " "); // Extract first argument        
        int i=1;        
        while(args[i-1]!=NULL){ // Loop to extract all arguments            
            args[i] = strtok(NULL, " "); // Get next argument            
            i++;
        }
        pid_t pid = fork(); // Create child process        
        if(pid==0){ // If in child process            
            int ret = execvp(args[0], args); // Execute the command            
            if(ret==-1){ // If error occurred in execution                
                printf("Invalid Command\n"); // Display error message                
                exit(0);
            }
            exit(0);
        }        
        else{ // If in parent process            
            wait(NULL); // Wait for child process to finish            
        }        
    }
    return 0;
}