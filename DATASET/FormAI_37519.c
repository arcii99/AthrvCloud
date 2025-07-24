//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define MAX_PATH_LENGTH 1024
#define MAX_PATHS 64

// Function declarations
int parse_command(char* command, char** arguments);
int execute_command(char** arguments, char** paths, int path_count);

int main() {
    // Initialize paths
    char** paths = malloc(MAX_PATHS * sizeof(char*));
    int path_count = 0;
    char* path = strtok(getenv("PATH"), ":");
    while (path != NULL) {
        paths[path_count++] = path;
        path = strtok(NULL, ":");
    }

    while (1) {
        // Print prompt
        char cwd[MAX_PATH_LENGTH];
        getcwd(cwd, sizeof(cwd));
        printf("%s$ ", cwd);

        // Read command
        char command[MAX_COMMAND_LENGTH];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        // Parse command
        char* arguments[MAX_ARGUMENTS];
        int argument_count = parse_command(command, arguments);

        // Execute command
        execute_command(arguments, paths, path_count);

        // Free memory
        for (int i = 0; i < argument_count; i++) {
            free(arguments[i]);
        }
    }

    // Free memory
    for (int i = 0; i < path_count; i++) {
        free(paths[i]);
    }
    free(paths);

    return 0;
}

int parse_command(char* command, char** arguments) {
    int argument_count = 0;

    // Parse arguments from command
    char* argument = strtok(command, " ");
    while (argument != NULL) {
        arguments[argument_count] = malloc((strlen(argument) + 1) * sizeof(char));
        strcpy(arguments[argument_count], argument);
        argument_count++;
        argument = strtok(NULL, " ");
    }
    arguments[argument_count] = NULL;

    return argument_count;
}

int execute_command(char** arguments, char** paths, int path_count) {
    // Check if command is empty
    if (arguments[0] == NULL) {
        return -1;
    }

    char* command_path = NULL;

    // Try to find command in paths
    for (int i = 0; i < path_count; i++) {
        char* path = paths[i];
        char command[MAX_PATH_LENGTH + MAX_COMMAND_LENGTH + 1];
        sprintf(command, "%s/%s", path, arguments[0]);
        if (access(command, X_OK) == 0) {
            command_path = malloc((strlen(command) + 1) * sizeof(char));
            strcpy(command_path, command);
            break;
        }
    }

    // Try to execute command
    if (command_path != NULL) {
        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Error: Failed to fork\n");
            free(command_path);
            return -1;
        } else if (pid == 0) {
            // Child process
            execv(command_path, arguments);
            fprintf(stderr, "Error: Failed to execute %s\n", command_path);
            free(command_path);
            return -1;
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
            free(command_path);
            return WEXITSTATUS(status);
        }
    } else {
        fprintf(stderr, "Error: Command not found\n");
        return -1;
    }
}