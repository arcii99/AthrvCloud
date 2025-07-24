//FormAI DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

int main() {
    printf("Hello there, let's analyze some logs!\n");

    char filename[MAX_LINE];
    printf("What is the name of the log file? ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Oops, looks like that file doesn't exist!\n");
        return -1;
    }

    int num_lines = 0;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file)) {
        num_lines++;
        char *token;
        token = strtok(line, " ");
        while (token != NULL) {
            if (strcmp(token, "error") == 0) {
                printf("Uh oh, found an error in line %d!\n", num_lines);
            }
            token = strtok(NULL, " ");
        }
    }

    printf("Finished analyzing %d lines of logs. Good job team!\n", num_lines);

    fclose(file);

    return 0;
}