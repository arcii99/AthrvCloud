//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char command[256];
    printf("> ");

    while (fgets(command, sizeof(command), stdin)) {
        if (strcmp(command, "exit\n") == 0) {
            printf("Exiting program...\n");
            break;
        }
        char *token = strtok(command, " ");
        while (token) {
            printf("Token: %s\n", token);
            token = strtok(NULL, " ");
        }
        printf("> ");
    }
    return 0;
}