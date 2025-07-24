//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_ARGS 64
#define MAX_COMMANDS 16

int execute_external_command(char* args[]);
int execute_internal_command(char* args[]);
int check_for_redirection(char* args[]);
int run_command(char* command[]);
int process_line(char* line);

int main(){
    char* line_buffer = malloc(MAX_BUFFER_SIZE * sizeof(char));
    if(line_buffer == NULL){
        perror("Error: Could not allocate memory!");
        exit(EXIT_FAILURE);
    }

    while(1){
        printf("> ");
        fgets(line_buffer, MAX_BUFFER_SIZE, stdin);
        process_line(line_buffer);
    }

    free(line_buffer);
    return 0;
}

int process_line(char* line){
    char* commands[MAX_COMMANDS];
    int num_commands = 0;

    char* command = strtok(line, "|");
    while(command != NULL && num_commands < MAX_COMMANDS){
        commands[num_commands] = command;
        num_commands++;
        command = strtok(NULL, "|");
    }

    int i = 0;
    int read_end = STDIN_FILENO;
    int write_end = -1;
    while(i < num_commands){
        char* args[MAX_ARGS];
        int num_args = 0;

        char* arg = strtok(commands[i], " \t\r\n");
        while(arg != NULL && num_args < MAX_ARGS){
            args[num_args] = arg;
            num_args++;
            arg = strtok(NULL, " \t\r\n");
        }

        int redirection = check_for_redirection(args);
        if(redirection > 0){
            if(i+1 >= num_commands){
                printf("Error: Redirection operator found but no output file specified\n");
                return -1;
            }

            int out_file = open(args[redirection+1], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
            if(out_file == -1){
                perror("Error: Could not open output file\n");
                return -1;
            }

            write_end = out_file;
        }

        int pid = fork();
        if(pid == -1){
            perror("Error: Failed to create child process!");
            return -1;
        }
        else if(pid == 0){
            if(i != 0){
                if(dup2(read_end, STDIN_FILENO) == -1){
                    perror("Error: Failed to redirect input!");
                    exit(EXIT_FAILURE);
                }
            }

            if(write_end != -1){
                if(dup2(write_end, STDOUT_FILENO) == -1){
                    perror("Error: Failed to redirect output!");
                    exit(EXIT_FAILURE);
                }
            }

            if(execute_internal_command(args) == 1){
                exit(EXIT_FAILURE);
            }

            if(execute_external_command(args) == 1){
                exit(EXIT_FAILURE);
            }
        }
        else{
            waitpid(pid, NULL, 0);
            if(write_end != -1){
                close(write_end);
                write_end = -1;
            }
            read_end = STDOUT_FILENO;
        }

        i++;
    }

    return 0;
}

int execute_external_command(char* args[]){
    char* command_path = getenv("PATH");
    if(command_path == NULL){
        command_path = "/bin:/usr/bin";
    }

    char* path = strtok(command_path, ":");
    while(path != NULL){
        char command_location[MAX_BUFFER_SIZE];
        snprintf(command_location, MAX_BUFFER_SIZE, "%s/%s", path, args[0]);

        if(access(command_location, X_OK) == 0){
            args[0] = command_location;
            return run_command(args);
        }

        path = strtok(NULL, ":");
    }

    return 0;
}

int execute_internal_command(char* args[]){
    if(strcmp(args[0], "cd") == 0){
        if(args[1] == NULL){
            chdir(getenv("HOME"));
        }
        else{
            if(chdir(args[1]) == -1){
                perror("Error: Failed to change directory!");
            }
        }

        return 1;
    }
    else if(strcmp(args[0], "exit") == 0){
        exit(0);
    }

    return 0;
}

int check_for_redirection(char* args[]){
    int i = 0;
    while(args[i] != NULL){
        if(strcmp(args[i], ">") == 0){
            return i;
        }

        i++;
    }

    return -1;
}

int run_command(char* command[]){
    int pid = fork();
    if(pid == -1){
        perror("Error: Failed to create child process!");
        return -1;
    }
    else if(pid == 0){
        execv(command[0], command);
        perror("Error: Failed to execute command!");
        exit(EXIT_FAILURE);
    }
    else{
        waitpid(pid, NULL, 0);
    }

    return 0;
}