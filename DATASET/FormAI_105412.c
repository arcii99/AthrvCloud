//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100], command[100], arg1[100], arg2[100];
    char cwd[1024];

    while(1) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s> ", cwd);
        } else {
            printf("Error: could not get current working directory.\n");
            exit(1);
        }

        fgets(input, 100, stdin);
        sscanf(input, "%s %s %s", command, arg1, arg2);

        if (strcmp(command, "cd") == 0) {
            if (chdir(arg1) != 0) {
                printf("Error: could not change directory.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            exit(0);
        } else {
            char full_command[200];
            sprintf(full_command, "%s %s %s", command, arg1, arg2);
            system(full_command);
        }
    }

    return 0;
}