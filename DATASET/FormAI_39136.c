//FormAI DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char path[100];
    char line[100];
    int count = 0;

    printf("Enter path to log file: ");
    scanf("%s", path);

    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("\nError opening file.\n");
        exit(1);
    }

    printf("\nLOG ANALYSIS\n\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, " ");
        if (strcmp(token, "Error") == 0) {
            printf("Error found: %s", line);
            count++;
        } else {
            printf("Line: %s", line);
        }
    }

    printf("\n\nNumber of errors found: %d\n", count);

    fclose(fp);
    return 0;
}