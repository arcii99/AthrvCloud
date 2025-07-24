//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_TOKENS 512
#define READ_END 0
#define WRITE_END 1

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char* tokens[MAX_TOKENS];
    int token_count = 0;

    while (1) {
        printf(">>> ");
        fflush(stdout);

        // read input from user
        if (!fgets(buffer, MAX_BUFFER_SIZE, stdin)) {
            break;
        }

        // tokenize input
        token_count = 0;
        char* token = strtok(buffer, " \r\n");
        while (token) {
            tokens[token_count] = token;
            token_count++;

            if (token_count >= MAX_TOKENS) {
                break;
            }

            token = strtok(NULL, " \r\n");
        }

        // null terminate tokens array
        tokens[token_count] = NULL;

        if (token_count > 0) {
            // handle exit command
            if (strcmp(tokens[0], "exit") == 0) {
                break;
            }

            // handle cd command
            if (strcmp(tokens[0], "cd") == 0) {
                if (token_count > 1) {
                    if (chdir(tokens[1]) < 0) {
                        perror(tokens[1]);
                    }
                } else {
                    chdir(getenv("HOME"));
                }

                continue;
            }

            // create pipe if piping commands
            int pipes[token_count - 1][2];
            for (int i = 0; i < token_count - 1; i++) {
                pipe(pipes[i]);
            }

            // execute commands and pipe output
            int pid;
            for (int i = 0; i < token_count; i++) {
                if ((pid = fork()) == 0) {
                    // child process

                    // redirect input
                    if (i != 0) {
                        dup2(pipes[i - 1][READ_END], STDIN_FILENO);
                    }

                    // redirect output
                    if (i != token_count - 1) {
                        dup2(pipes[i][WRITE_END], STDOUT_FILENO);
                    }

                    // close all pipe file descriptors in the child process
                    for (int j = 0; j < token_count - 1; j++) {
                        close(pipes[j][READ_END]);
                        close(pipes[j][WRITE_END]);
                    }

                    // execute command
                    if (execvp(tokens[i], &tokens[i]) < 0) {
                        perror(tokens[i]);
                        exit(EXIT_FAILURE);
                    }
                } else if (pid < 0) {
                    // error forking
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
            }

            // close all pipe file descriptors in the parent process
            for (int i = 0; i < token_count - 1; i++) {
                close(pipes[i][READ_END]);
                close(pipes[i][WRITE_END]);
            }

            // wait for child processes to complete
            for (int i = 0; i < token_count; i++) {
                wait(NULL);
            }
        }
    }

    return EXIT_SUCCESS;
}