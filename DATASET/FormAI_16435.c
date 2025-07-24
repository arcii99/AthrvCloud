//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define MAXSIZE 1000 // maximum input size
#define MAXARGS 100 // maximum arguments

char *built_in[] = {"cd", "exit"}; // list of built-in commands

int exec_args(char **args, char *input_file, char *output_file) {
    pid_t pid;
    int status;
    int fd_in = 0, fd_out = 1; // default to stdin and stdout

    if (input_file) { // if an input file is specified
        fd_in = open(input_file, O_RDONLY); // open the file
        if (fd_in < 0) {
            printf("Error: Unable to open input file\n");
            return 0;
        }
        dup2(fd_in, STDIN_FILENO); // redirect input to file
    }

    if (output_file) { // if an output file is specified
        fd_out = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd_out < 0) {
            printf("Error: Unable to open output file\n");
            return 0;
        }
        dup2(fd_out, STDOUT_FILENO); // redirect output to file
    }

    pid = fork(); // create new process
    if (pid == 0) { // child process
        if (execvp(args[0], args) == -1) { // execute program
            printf("Error: Unable to execute command\n");
            return 0;
        }
        exit(EXIT_FAILURE); // if execvp fails, exit child process
    } else if (pid < 0) { // error occurred
        printf("Error: Unable to fork child process\n");
        return 0;
    } else { // parent process
        waitpid(pid, &status, 0); // wait for child to complete
    }

    if (input_file) close(fd_in); // close input file
    if (output_file) close(fd_out); // close output file

    return status;
}

int parse_args(char **args, char *input_file, char *output_file) {
    int n = 0;
    char *token;

    // parse input string by spaces
    token = strtok(NULL, " ");
    while (token) {
        if (*token == '>') { // check for output redirection symbol
            if (output_file) {
                printf("Error: Multiple output redirection not allowed\n");
                return 0;
            }
            token = strtok(NULL, " ");
            output_file = token;
        } else if (*token == '<') { // check for input redirection symbol
            if (input_file) {
                printf("Error: Multiple input redirection not allowed\n");
                return 0;
            }
            token = strtok(NULL, " ");
            input_file = token;
        } else { // add argument to list
            args[n++] = token;
        }
        token = strtok(NULL, " ");
    }
    args[n] = NULL;

    return exec_args(args, input_file, output_file); // execute command with arguments and IO files
}

int execute_cmd(char **args) {
    if (!args[0]) return 1; // empty command line
    for (int i = 0; i < 2; i++) { // check for built-in commands (cd, exit)
        if (strcmp(args[0], built_in[i]) == 0) {
            if (i == 0) { // cd
                if (args[1]) {
                    if (chdir(args[1]) != 0)
                        printf("Error: Directory not found\n");
                } else {
                    printf("cd missing argument\n");
                }
                return 1;
            } else { // exit
                exit(0);
            }
        }
    }
    return parse_args(args, NULL, NULL); // execute external command
}

int main() {
    char line[MAXSIZE]; // input buffer
    char *args[MAXARGS]; // list of arguments

    while (1) { // continuous loop until exit
        printf("myshell> "); // print prompt
        fflush(stdout); // clear output buffer
        fgets(line, MAXSIZE, stdin); // read input string
        line[strcspn(line, "\n")] = '\0'; // remove new line character

        if (!line[0]) // if input is empty, prompt again
            continue;

        char *token = strtok(line, " "); // parse input string by spaces
        int n = 0;
        while (token) {
            args[n++] = token;
            token = strtok(NULL, " ");
        }
        args[n] = NULL;

        execute_cmd(args); // execute command
    }

    return 0;
}