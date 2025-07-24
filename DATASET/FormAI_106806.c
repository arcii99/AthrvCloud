//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64
#define MAX_PIPES 16

void execute_command(char **args, int in_fd, int out_fd);

int main(int argc, char **argv) {
    char command_line[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    char **pipes[MAX_PIPES];
    char *delimiter = " \t\n";
    int num_pipes;

    while (1) {
        num_pipes = 0;

        printf("$ ");
        fgets(command_line, MAX_COMMAND_LENGTH, stdin);
        args[0] = strtok(command_line, delimiter);

        while (args[num_pipes] != NULL) {
            num_pipes++;
            args[num_pipes] = strtok(NULL, delimiter);
        }

        if (num_pipes > 0) {
            int pipe_count = 0;
            int pipe_fds[MAX_PIPES][2];
            int child_pid;

            while (pipes[pipe_count] != NULL) {
                pipe(pipes[pipe_count]);
                pipe_count++;
            }

            for (int i = 0; i < num_pipes; i++) {
                if (strcmp(args[i], "|") == 0) {
                    args[i] = NULL;
                    pipes[pipe_count] = &args[i+1];
                    pipe_count++;
                }
            }

            pipes[pipe_count] = NULL;

            for (int i = 0; i <= pipe_count; i++) {
                if ((child_pid = fork()) == -1) {
                    perror("Failed to fork process");
                    exit(1);
                } else if (child_pid == 0) {
                    if (i != 0) {
                        dup2(pipe_fds[i-1][0], STDIN_FILENO);
                        close(pipe_fds[i-1][0]);
                    }

                    if (i != pipe_count) {
                        dup2(pipe_fds[i][1], STDOUT_FILENO);
                        close(pipe_fds[i][1]);
                    }

                    execute_command(pipes[i], STDIN_FILENO, STDOUT_FILENO);
                    exit(0);
                } else {
                    if (i != 0) {
                        close(pipe_fds[i-1][0]);
                    }

                    if (i != pipe_count) {
                        close(pipe_fds[i][1]);
                    }
                }
            }

            for (int i = 0; i < pipe_count; i++) {
                wait(NULL);
            }
        } else {
            execute_command(args, STDIN_FILENO, STDOUT_FILENO);
        }
    }

    return 0;
}

void execute_command(char **args, int in_fd, int out_fd) {
    int pid, status, output_fd, input_fd;

    if (*args == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    if ((pid = fork()) < 0) {
        perror("Failed to fork process");
        exit(1);
    }

    if (pid == 0) {
        if (in_fd != STDIN_FILENO) {
            dup2(in_fd, STDIN_FILENO);
            close(in_fd);
        }

        if (out_fd != STDOUT_FILENO) {
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
        }

        if (strcmp(args[0], "cd") == 0) {
            if (args[1]) {
                chdir(args[1]);
            } else {
                chdir(getenv("HOME"));
            }

            exit(0);
        }

        if (strcmp(args[0], "pwd") == 0) {
            char work_dir[1024];

            getcwd(work_dir, sizeof(work_dir));
            printf("%s\n", work_dir);

            exit(0);
        }

        if (strcmp(args[0], ">>") == 0) {
            if (args[1]) {
                if ((output_fd = open(args[1], O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1) {
                    perror("Unable to open file");
                    exit(EXIT_FAILURE);
                }

                dup2(output_fd, STDOUT_FILENO);
            }

            execute_command(args + 2, STDIN_FILENO, STDOUT_FILENO);
            exit(0);
        }

        if (strcmp(args[0], ">") == 0) {
            if (args[1]) {
                if ((output_fd = open(args[1], O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1) {
                    perror("Unable to open file");
                    exit(EXIT_FAILURE);
                }

                dup2(output_fd, STDOUT_FILENO);
                close(output_fd);
            }

            execute_command(args + 2, STDIN_FILENO, STDOUT_FILENO);
            exit(0);
        }

        if (strcmp(args[0], "<") == 0) {
            if (args[1]) {
                if ((input_fd = open(args[1], O_RDONLY, 0644)) == -1) {
                    perror("Unable to open file");
                    exit(EXIT_FAILURE);
                }

                dup2(input_fd, STDIN_FILENO);
            }

            execute_command(args + 2, STDIN_FILENO, STDOUT_FILENO);
            exit(0);
        }

        execvp(args[0], args);
        perror("Execution failed");
        exit(1);
    }

    waitpid(pid, &status, 0);
}