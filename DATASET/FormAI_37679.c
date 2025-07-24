//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

// function declaration
void loop();
char* read_input();
char** split_line(char* line);
int execute_command(char** args);
int launch_process(char** args);
int cd_builtin(char** args);
int help_builtin(char** args);
int exit_builtin(char** args);

// main function
int main(int argc, char** argv) {
    loop();
    return 0;
}

void loop() {
    char* input;
    char** args;
    int status;
    
    do {
        printf("> ");
        input = read_input();
        args = split_line(input);
        status = execute_command(args);
        
        free(input);
        free(args);
    } while(status);
}

char* read_input() {
    char* buffer = NULL;
    size_t size = 0;
    getline(&buffer, &size, stdin);
    return buffer;
}

char** split_line(char* line) {
    int buffer_size = BUFFER_SIZE, position = 0;
    char** tokens = malloc(buffer_size * sizeof(char*));
    char* token;
    
    if(!tokens) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    token = strtok(line, TOKEN_DELIMITERS);
    while(token != NULL) {
        tokens[position] = token;
        position++;
        
        if(position >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char*));
            
            if(!tokens) {
                fprintf(stderr, "Memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        
        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[position] = NULL;
    return tokens;
}

int execute_command(char** args) {
    if(args[0] == NULL) { // empty command entered
        return 1;
    }
    
    if(strcmp(args[0], "cd") == 0) {
        return cd_builtin(args);
    }
    
    if(strcmp(args[0], "help") == 0) {
        return help_builtin(args);
    }
    
    if(strcmp(args[0], "exit") == 0) {
        return exit_builtin(args);
    }
    
    return launch_process(args);
}

int launch_process(char** args) {
    pid_t pid, wpid;
    int status;
    
    pid = fork();
    if (pid == 0) { // child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "%s: Command not found\n", args[0]);
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // error occured
        fprintf(stderr, "Fork failed\n");
    } else { // parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    
    return 1;
}

int cd_builtin(char** args) {
    if(args[1] == NULL) { // no argument passed to cd command
        fprintf(stderr, "Expected argument to cd command\n");
    } else {
        if(chdir(args[1]) != 0) {
            perror("cd error");
        }
    }
    return 1;
}

int help_builtin(char** args) {
    printf("\n######## Basic Unix-like Shell Example ########\n\n");
    printf("Type program names and arguments, and press enter.\n");
    printf("The following built-in commands are supported:\n");
    printf("cd [dir]: Change current working directory\n");
    printf("help: List all the supported commands\n");
    printf("exit: Exit the shell\n\n");
    printf("########### Happy Coding! ###########\n");
    return 1;
}

int exit_builtin(char** args) {
    printf("Goodbye!\n");
    return 0;
}