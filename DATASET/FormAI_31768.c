//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define BUFFER_SIZE 1024
#define TOK_DELIM " \t\r\n\a"

char *read_input(void)
{
    char *buffer = NULL;
    ssize_t bufsize = 0;
    getline(&buffer, &bufsize, stdin);
    return buffer;
}

char **split_input(char *line)
{
    int bufsize = BUFFER_SIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += BUFFER_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int execute(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("error in execvp");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("error in fork");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main(){
	char *line;
    char **args;
    int status;

    do {
        printf("$ ");
        line = read_input();
        args = split_input(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
    return 0;
}