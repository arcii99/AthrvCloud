//FormAI DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void clear_input_buffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

void print_prompt(){
    printf(">>> ");
    fflush(stdout);
}

void execute_command(char* command){
    int status;
    pid_t pid = fork();
    if(pid == 0) {
        char* args[4];
        args[0] = "/bin/sh";
        args[1] = "-c";
        args[2] = command;
        args[3] = NULL;
        execv("/bin/sh", args);
        exit(1);
    } else if(pid < 0) {
        printf("Error executing command.\n");
    } else {
        waitpid(pid, &status, 0);
    }
}

int main(){
    while(1){
        print_prompt();
        char input[256];
        fgets(input, sizeof input, stdin);
        
        char* command = strtok(input, "\n");
        if(!command){
            clear_input_buffer();
            continue;
        }
        
        if(strcmp(command, "exit") == 0){
            break;
        }
        
        execute_command(command);    
    }
    
    return 0;
}