//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_CMD_ARG 10 // Maximum number of command arguments
#define MAX_CMD_LEN 100 // Maximum length of command

void printPrompt(){
    char host[50];
    gethostname(host, sizeof(host)); // Get hostname
    printf("%s:%s$ ", host, get_current_dir_name()); // print prompt
}

void execute(char* cmd){
    // Tokenize command arguments
    char* cmd_tokens[MAX_CMD_ARG];
    int arg_count = 0;
    char* token = strtok(cmd, " ");
    while(token != NULL){
        cmd_tokens[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    cmd_tokens[arg_count] = NULL;

    pid_t child_pid = fork(); // Create child process

    if(child_pid < 0) // Fork failed
        exit(EXIT_FAILURE);

    else if(child_pid == 0){ // Child process
        int status = execvp(cmd_tokens[0], cmd_tokens);
        if(status == -1){ // execlp failed
            printf("Error executing command.\n");
            exit(EXIT_FAILURE);
        }
    }

    else{ // Parent process
        waitpid(child_pid, NULL, 0); // Wait for child process to finish
    }
}

int main(){
    while(1){
        printPrompt(); // print shell prompt
        char cmd[MAX_CMD_LEN];
        fgets(cmd, MAX_CMD_LEN, stdin); // read command from user

        if(strcmp(cmd, "exit\n") == 0){ // Exit command
            break;
        }

        int len = strlen(cmd);
        if(len > 0 && cmd[len-1] == '\n') // Replace newline character with null terminator
            cmd[len-1] = '\0';

        execute(cmd); // execute command
    }

    return 0;
}