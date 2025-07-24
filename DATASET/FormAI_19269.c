//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_CMD_LINE_LEN 1024
#define MAX_NUM_ARGS 64
#define MAX_NUM_PIPES 16

int spawn_child(char** args, int* pipe_fd, int pipe_num, int is_first, int is_last){
    pid_t pid;
    if ((pid = fork()) < 0){
        printf("Error: child process creation failed.\n");
        return 1;
    } else if (pid == 0) {
        if (is_first && !is_last){
            dup2(pipe_fd[pipe_num+1], STDOUT_FILENO);
        } else if (is_last && !is_first) {
            dup2(pipe_fd[pipe_num-2], STDIN_FILENO);
        } else if (!is_last && !is_first){
            dup2(pipe_fd[pipe_num+1], STDOUT_FILENO);
            dup2(pipe_fd[pipe_num-2], STDIN_FILENO);
        }
        if (execvp(args[0], args) < 0){
            printf("Error: Command not found.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        if (!is_first){
            close(pipe_fd[pipe_num-2]);
        }
        if (!is_last){
            close(pipe_fd[pipe_num+1]);
        }
        wait(NULL);
    }
    return 0;
}

int execute_pipeline(char* cmd_line){
    int num_pipes = 0, cmd_counter = 0;
    char* args[MAX_NUM_ARGS];
    char* cmds[MAX_NUM_PIPES][MAX_NUM_ARGS];
    int pipe_fd[MAX_NUM_PIPES*2];
    memset(pipe_fd, 0, sizeof(pipe_fd));

    // split command line into individual commands separated by |
    char* token = strtok(cmd_line, "|");
    while (token != NULL){
        int num_args = 0;
        char* arg = strtok(token, " ");
        while (arg != NULL){
            args[num_args++] = arg;
            arg = strtok(NULL, " ");
        }
        args[num_args] = NULL;
        if (num_pipes > 0){
            pipe(pipe_fd + (num_pipes-1)*2);
        }
        for (int i=0; i<num_args; i++){
            cmds[num_pipes][i] = args[i];
        }
        cmds[num_pipes++][num_args] = NULL;
        token = strtok(NULL, "|");
    }
    int is_first = 1, is_last = 0;
    for (cmd_counter = 0; cmd_counter < num_pipes-1; cmd_counter++){
        is_last = 0;
        spawn_child(cmds[cmd_counter], pipe_fd, cmd_counter*2, is_first, is_last);
        is_first = 0;
    }
    is_last = 1;
    spawn_child(cmds[cmd_counter], pipe_fd, cmd_counter*2, is_first, is_last);

    return 0;
}

int main(){
    char cmd_line[MAX_CMD_LINE_LEN];
    while (1){
        printf("$$ ");
        fgets(cmd_line, MAX_CMD_LINE_LEN, stdin);
        if (strcmp(cmd_line, "exit\n") == 0){
            break;
        }
        execute_pipeline(cmd_line);
    }
    return 0;
}