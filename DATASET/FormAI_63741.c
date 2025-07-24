//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
/*
 * This is a basic Unix-like shell program built using recursive approach
 * The program accepts commands inputted by users via the terminal and then
 * executes them just like a typical Unix shell.
 *
 * By Yemi Bedu
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 8192
#define MAX_ARG_COUNT 64

/* function that reads input from the user via the terminal */
void read_input(char *inputBuffer) {
    printf("Enter command: ");
    fflush(stdout);
    fgets(inputBuffer, MAX_CMD_LENGTH, stdin);
    int inputLength = strlen(inputBuffer);
    inputBuffer[inputLength - 1] = '\0';   // remove the newline character
}

/* function that parses the command string to obtain command name and arguments */
int parse_input(char *input, char **args) {
    int arg_count = 0;
    while (*input != '\0') {
        while (*input == ' ' || *input == '\t' || *input == '\n')
            *input++ = '\0';
        *args++ = input;
        arg_count++;
        while (*input != '\0' && *input != ' ' && *input != '\t' && *input != '\n')
            input++;
    }
    *args = NULL;

    return arg_count;
}

/* recursive function that pipes the output of one command into another command */
void pipe_commands(char **command1_args, char **command2_args) {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("Error creating the pipe!");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("Error creating a child process!");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* child process */
        close(pipefd[0]);   // close unused read-end of pipe
        dup2(pipefd[1], STDOUT_FILENO); //redirect child stdout to pipe write-end

        if (execvp(command1_args[0], command1_args) == -1) {
            perror("Error executing command1!");
            exit(EXIT_FAILURE);
        }

    } else {
        /* parent process */
        close(pipefd[1]);   // close unused write-end of pipe
        dup2(pipefd[0], STDIN_FILENO); // redirect parent stdin to pipe read-end

        if (execvp(command2_args[0], command2_args) == -1) {
            perror("Error executing command2!");
            exit(EXIT_FAILURE);
        }
    }
}

/* recursive function that executes the commands entered by the user */
void execute_commands(char **arg_list) {
    char **pipe_index;
    int pipeline_count = 0;
    char *next_command[MAX_ARG_COUNT + 1];

    for (pipe_index = arg_list; *pipe_index; pipe_index++) {
        if (strcmp(*pipe_index, "|") == 0) {
            pipeline_count++;
            *pipe_index = NULL;
            execute_commands(next_command);
            arg_list = pipe_index + 1;
            break;
        } else {
            next_command[pipe_index - arg_list] = *pipe_index;
        }
    }

    if (*pipe_index == NULL) {
        execute_command(arg_list);
    } else {
        pipeline_count++;
        execute_command(next_command);
        for (int i = 1; i < pipeline_count; i++) {
            pipe_commands(next_command, arg_list);
        }
    }
}

/* function that executes a single command entered by the user */
void execute_command(char **arg_list) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("Error creating a child process!");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* child process */
        if (execvp(arg_list[0], arg_list) == -1) {
            perror("Error executing command!");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else {
        /* parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/* main function */
int main(int argc, char **argv) {
    char input[MAX_CMD_LENGTH];
    char *args[MAX_ARG_COUNT + 1];
    int arg_count;

    while (1) {
        read_input(input);
        arg_count = parse_input(input, args);
        if (arg_count > 0) {
            execute_commands(args);
        }
    }

    return EXIT_SUCCESS;
}