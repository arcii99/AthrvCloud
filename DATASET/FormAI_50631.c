//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
/* 
   This program simulates a Unix-like shell interface using C language.
   
   The user can enter any Linux/Unix command and the program will execute it.
   The program also supports some built-in commands such as "cd" and "exit". 
   
   Author: [Your Name]
   Date:   [Current date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 1000
#define MAX_COMMANDS 1000

/*
   Function: get_input()
   ----------------------
   This function takes input from the user and stores it in a char array.
   
   input: a char array to store the user input
*/
void get_input(char input[]) {
    printf("$ ");
    fgets(input, MAX_ARGS, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
}

/*
   Function: parse_input()
   -----------------------
   This function takes the user input and splits it into an array of commands.
   
   input: the user input as a char array
   commands: an array of char arrays to store the commands
   Returns: the number of commands
*/
int parse_input(char input[], char* commands[]) {
    int i = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        commands[i++] = token;
        token = strtok(NULL, " ");
    }
    commands[i] = NULL; // Append NULL to the end to mark the end of the list
    return i;
}

/*
   Function: execute_commands()
   ----------------------------
   This function executes the commands provided by the user.
   
   commands: an array of char arrays containing the commands
*/
void execute_commands(char* commands[]) {
    int pid, status;
    int pipefd[2];
    int commands_count = 0;
    char* argv[MAX_ARGS];
    char* bin_path = "/bin/";

    for (int i = 0; commands[i] != NULL; i++) {
        if (strcmp(commands[i], "|") == 0) { // If "pipe" character found
            commands_count++;
            if (pipe(pipefd) < 0) {
                printf("Pipe error\n");
                exit(1);
            }
            pid = fork();
            if (pid < 0) { // If fork() fails
                printf("Fork error\n");
                exit(1);
            } else if (pid == 0) { // If child process
                close(STDOUT_FILENO); // Close standard output
                dup(pipefd[1]); // Redirect standard output to pipe
                close(pipefd[0]); // Close unused read end of pipe
                close(pipefd[1]); // Close write end of pipe
                execv(strcat(bin_path, commands[commands_count-1]), argv); // Execute command
            } else { // If parent process
                close(STDIN_FILENO); // Close standard input
                dup(pipefd[0]); // Redirect standard input to pipe
                close(pipefd[1]); // Close unused write end of pipe
                close(pipefd[0]); // Close read end of pipe
                execv(strcat(bin_path, commands[i+1]), argv); // Execute command
            }
        }
        argv[i] = commands[i];
    }

    if (commands_count == 0) {
        pid = fork();
        if (pid < 0) { // If fork() fails
            printf("Fork error\n");
            exit(1);
        } else if (pid == 0) { // If child process
            execv(strcat(bin_path, commands[0]), argv); // Execute command
        } else { // If parent process
            waitpid(pid, &status, 0); // Wait for child process to finish
        }
    }
}

/*
   Function: main()
   -----------------
   This is the main function of the program. It takes input from the user and
   executes the commands provided.
*/
int main() {
    char input[MAX_ARGS];
    char* commands[MAX_COMMANDS];
    int num_commands;

    while(1) {
        get_input(input);
        num_commands = parse_input(input, commands);
        if (strcmp(commands[0], "exit") == 0) {
            exit(0); // Exit program when "exit" command is entered
        } else if (strcmp(commands[0], "cd") == 0) {
            if (chdir(commands[1]) != 0) {
                printf("cd error\n");
            }
        } else {
            execute_commands(commands);
        }
    }

    return 0;
}