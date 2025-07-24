//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *command;
    char *arg1;
    char *arg2;
    char *arg3;

    if (argc != 2) {
        printf("Usage: admin <file>\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Parse command and arguments from line
        command = strtok(line, " \n");
        if (command == NULL) {
            continue;
        }
        arg1 = strtok(NULL, " \n");
        arg2 = strtok(NULL, " \n");
        arg3 = strtok(NULL, " \n");

        // Execute command based on parsed input
        if (strcmp(command, "ls") == 0) {
            if (arg1 != NULL) {
                printf("Invalid 'ls' command: too many arguments\n");
                continue;
            }
            system("ls");
        } else if (strcmp(command, "rm") == 0) {
            if (arg1 == NULL) {
                printf("Invalid 'rm' command: no arguments\n");
                continue;
            }
            if (arg2 != NULL || arg3 != NULL) {
                printf("Invalid 'rm' command: too many arguments\n");
                continue;
            }
            char *rm_command = (char*) malloc(strlen(arg1) + 4);
            sprintf(rm_command, "rm %s", arg1);
            system(rm_command);
            free(rm_command);
        } else if (strcmp(command, "mv") == 0) {
            if (arg1 == NULL || arg2 == NULL) {
                printf("Invalid 'mv' command: not enough arguments\n");
                continue;
            }
            if (arg3 != NULL) {
                printf("Invalid 'mv' command: too many arguments\n");
                continue;
            }
            char *mv_command = (char*) malloc(strlen(arg1) + strlen(arg2) + 5);
            sprintf(mv_command, "mv %s %s", arg1, arg2);
            system(mv_command);
            free(mv_command);
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    fclose(file);
    return 0;
}