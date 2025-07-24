//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 20
#define MAX_CMD_LENGTH 100

void parse_command(char* cmd_line, char** commands);
int execute_command(char** commands);
int process_args(char** args);
void run_pipe(int pfd[2], char** commands, int command_count, int current_command);

int main() {
    char cmd_line[MAX_CMD_LENGTH];
    char* commands[MAX_COMMANDS];
    int status;
    pid_t pid;

    while (1) {
        printf("retro-sh > ");
        fgets(cmd_line, MAX_CMD_LENGTH, stdin);

        if (strcmp(cmd_line, "exit\n") == 0) {
            break;
        }

        parse_command(cmd_line, commands);
        status = execute_command(commands);
    }

    return 0;
}

void parse_command(char* cmd_line, char** commands) {
    char* token;
    int i = 0;

    token = strtok(cmd_line, "|");
    while (token != NULL && i < MAX_COMMANDS) {
        commands[i] = token;
        token = strtok(NULL, "|");
        i++;
    }
    commands[i] = NULL;
}

int execute_command(char** commands) {
    int command_count = 0;
    int pfd[2];
    pid_t pid;
    int status;

    while (commands[command_count] != NULL) {
        command_count++;
    }

    if (command_count == 1) {
        char* args[MAX_ARGS];
        process_args(args);
        pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else {
            waitpid(pid, &status, 0);
        }
    }
    else {
        int current_command = 0;
        run_pipe(pfd, commands, command_count, current_command);
    }

    return status;
}

int process_args(char** args) {
    char* token;
    int i = 0;

    token = strtok(args, " ");
    while (token != NULL && i < MAX_ARGS) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;

    return i;
}

void run_pipe(int pfd[2], char** commands, int command_count, int current_command) {
    pid_t pid;
    int status;

    if (current_command == command_count - 1) {
        char* args[MAX_ARGS];
        process_args(args);
        pid = fork();
        if (pid == 0) {
            dup2(pfd[0], STDIN_FILENO);
            close(pfd[1]);
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else {
            close(pfd[0]);
            close(pfd[1]);
            waitpid(pid, &status, 0);
        }
    }
    else {
        int new_pfd[2];
        pipe(new_pfd);
        pid = fork();
        if (pid == 0) {
            dup2(pfd[0], STDIN_FILENO);
            dup2(new_pfd[1], STDOUT_FILENO);
            close(pfd[1]);
            close(new_pfd[0]);
            char** new_commands = commands + current_command + 1;
            run_pipe(new_pfd, new_commands, command_count - current_command - 1, 0);
            exit(EXIT_SUCCESS);
        }
        else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else {
            close(pfd[0]);
            close(pfd[1]);
            close(new_pfd[1]);
            waitpid(pid, &status, 0);
            run_pipe(new_pfd, commands, command_count, current_command + 1);
        }
    }
}