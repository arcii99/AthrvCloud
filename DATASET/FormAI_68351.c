//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 20 // maximum number of arguments in a command
#define MAX_CMD_LEN 1024 // maximum length of a command
#define PROMPT ">>"

void execute_command(char **args){
    pid_t pid = fork(); // fork a child process
    if (pid == -1) {
        perror("fork");
        return;
    }
    if (pid == 0) { // child process
        if (execvp(args[0], args) == -1) { // execute the command
            perror("exec");
            exit(1);
        }
    } else { // parent process
        int status;
        if (waitpid(pid, &status, 0) == -1) { // wait for child process to complete
            perror("waitpid");
        }
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) { // check for non-zero exit status
            printf("Command failed.\n");
        }
    }
}

int main(){
    char cmd[MAX_CMD_LEN + 1];
    char *args[MAX_ARGS + 1];
    while (1){
        printf("%s ", PROMPT);
        fflush(stdout);
        fgets(cmd, sizeof(cmd), stdin);
        size_t len = strlen(cmd);
        if (len > 0 && cmd[len - 1] == '\n') { // remove trailing newline
            cmd[len - 1] = '\0';
        }
        char *token = strtok(cmd, " "); // tokenize the command
        int i = 0;
        while (token != NULL && i < MAX_ARGS) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // add null terminator at the end of arguments array
        if (i > 0) { // if there is at least one argument
            if (strcmp(args[0], "exit") == 0) { // exit the shell
                exit(0);
            } else if (strcmp(args[0], "cd") == 0) { // change directory
                if (i > 1) {
                    if (chdir(args[1]) == -1) {
                        perror("chdir");
                    }
                } else {
                    printf("cd: missing argument.\n");
                }
            } else { // execute command
                execute_command(args);
            }
        }
    }
    return 0;
}