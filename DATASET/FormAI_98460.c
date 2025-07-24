//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    printf("*** Welcome to my Unix-like Shell! ***\n\n");

    while(1){
        char *input_buffer = NULL;
        size_t input_size = 0;
        ssize_t input_length = getline(&input_buffer, &input_size, stdin); //Read user input from command line
        if(input_length == -1){
            printf("\n"); //if user presses enter on an empty line, getline() will return -1
            continue;
        }

        input_buffer[strcspn(input_buffer, "\n")] = '\0'; //replace newline character with null termination

        char* command_args[100];
        char* argument = strtok(input_buffer, " ");
        int i = 0;
        while(argument != NULL) { //Parse input_buffer and populate command_args array
            command_args[i++] = argument;
            argument = strtok(NULL, " ");
        }
        command_args[i] = NULL; //terminate command_args array with NULL
        
        pid_t pid = fork();
        if (pid == -1) { //if fork() fails, handle the error
            printf("\n*** Fork error ***\n\n");
            continue;
        } else if (pid == 0) {
            int ret = execvp(command_args[0], command_args); //Run the command if child process
            if(ret == -1) {
                printf("\n*** Command not found ***\n\n"); //execvp() returns -1 and sets errno if command is not found
                exit(1);
            } 
        } else {
            int status;
            waitpid(pid, &status, 0); //wait for child process to finish
        }
    }
    return 0;
}