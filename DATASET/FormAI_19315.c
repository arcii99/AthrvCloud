//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

void shell_loop();
char *read_line();
char **parse_line(char *line);
int launch_process(char **arguments);
int execute_built_in(char **arguments);
int execute_process(char **arguments);
int number_of_built_ins();
int exit_built_in(char **arguments);
int help_built_in(char **arguments);

/* List of built-in commands */
char *built_in_commands[] = {
    "exit", 
    "help"
};

/* Corresponding functions for built-in commands */
int (*built_in_functions[]) (char **) = {
    &exit_built_in,
    &help_built_in
};

/* Main function */
int main() {
    shell_loop();
    return 0;
}

/* Shell loop */
void shell_loop() {
    char *line;
    char **arguments;
    int status;
    
    do {
        printf("> ");
        line = read_line();
        arguments = parse_line(line);
        status = launch_process(arguments);
        
        free(line);
        free(arguments);
    } while (status);
}

/* Read line from user */
char *read_line() {
    char *line = NULL;
    size_t buffer_size = 0;
    
    getline(&line, &buffer_size, stdin);
    return line;
}

/* Split line into array of arguments */
char **parse_line(char *line) {
    int buffer_size = BUFFER_SIZE, index = 0;
    char **tokens = malloc(buffer_size * sizeof(char*));
    char *token;
    
    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    token = strtok(line, TOKEN_DELIMITERS);
    while (token != NULL) {
        tokens[index++] = token;
        
        if (index >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char*));
            
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        
        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[index] = NULL;
    return tokens;
}

/* Launch process based on arguments */
int launch_process(char **arguments) {
    if (arguments[0] == NULL) {
        return 1;
    }
    
    for (int i = 0; i < number_of_built_ins(); i++) {
        if (strcmp(arguments[0], built_in_commands[i]) == 0) {
            return (*built_in_functions[i])(arguments);
        }
    }
    
    return execute_process(arguments);
}

/* Number of built-in commands */
int number_of_built_ins() {
    return sizeof(built_in_commands) / sizeof(char *);
}

/* Execute built-in command */
int execute_built_in(char **arguments) {
    if (strcmp(arguments[0], "exit") == 0) {
        return exit_built_in(arguments);
    } else if (strcmp(arguments[0], "help") == 0) {
        return help_built_in(arguments);
    }

    return 1;
}

/* Exit built-in command */
int exit_built_in(char **arguments) {
    return 0;
}

/* Help built-in command */
int help_built_in(char **arguments) {
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built-in:\n");
    
    for (int i = 0; i < number_of_built_ins(); i++) {
        printf("  %s\n", built_in_commands[i]);
    }
    
    printf("Use the man command for information on other programs.\n");
    return 1;
}

/* Execute process */
int execute_process(char **arguments) {
    pid_t pid, wait_pid;
    int status;
    
    pid = fork();
    
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error");
        }
        
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error");
    } else {
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    
    return 1;
}