//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGC 10
#define MAX_LINE_LENGTH 100
#define MAX_PATH_LENGTH 200
#define MAX_NUM_PATHS 10

char *builtin_commands[] = {"cd", "exit"};

int execute_command(char **command_argv, char **paths, int num_paths) {
    int i, status;
    pid_t pid = fork();

    if (pid == 0) {
        char command_path[MAX_PATH_LENGTH];
        for (i = 0; i < num_paths; i++) {
            strcpy(command_path, paths[i]);
            strcat(command_path, "/");
            strcat(command_path, command_argv[0]);
            if (access(command_path, X_OK) == 0) {
                execv(command_path, command_argv);
            }
        }
        printf("%s: command not found\n", command_argv[0]);
        exit(1);
    } else if (pid == -1) {
        printf("Failed to fork process\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

void change_directory(char *path) {
    if (chdir(path) == -1) {
        printf("%s: no such directory\n", path);
    }
}

int is_builtin_command(char *command) {
    int i;
    for (i = 0; i < sizeof(builtin_commands) / sizeof(char *); i++) {
        if (strcmp(command, builtin_commands[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int execute_builtin_command(char *command, char **command_argv) {
    if (strcmp(command, "cd") == 0) {
        if (command_argv[1] == NULL) {
            printf("cd: no path specified\n");
        } else {
            change_directory(command_argv[1]);
        }
        return 0;
    } else if (strcmp(command, "exit") == 0) {
        exit(0);
    }
    return 1;
}

void parse_command(char *line, char **command, char **command_argv) {
    int argc = 0;
    char *token;

    token = strtok(line, " \n");
    while (token != NULL && argc < MAX_ARGC) {
        if (argc == 0) {
            *command = token;
        }
        command_argv[argc++] = token;
        token = strtok(NULL, " \n");
    }
    command_argv[argc] = NULL;
}

int read_line(char *line) {
    return fgets(line, MAX_LINE_LENGTH, stdin) != NULL;
}

void print_prompt() {
    char cwd[MAX_PATH_LENGTH];
    getcwd(cwd, MAX_PATH_LENGTH);
    printf("%s$ ", cwd);
}

int main() {
    char *paths[MAX_NUM_PATHS] = {"/bin", "/usr/bin"};
    int num_paths = 2;

    while (1) {
        char line[MAX_LINE_LENGTH];
        char *command = NULL;
        char *command_argv[MAX_ARGC + 1] = {NULL};

        print_prompt();
        if (!read_line(line)) {
            printf("\n");
            break;
        }
        parse_command(line, &command, command_argv);
        if (command == NULL) {
            continue;
        }
        if (is_builtin_command(command)) {
            execute_builtin_command(command, command_argv);
        } else {
            execute_command(command_argv, paths, num_paths);
        }
    }
    return 0;
}