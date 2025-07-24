//FormAI DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *fp;
    char filename[100];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;

    printf("Enter the log file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Processing log file...\n\n");

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "ERROR") != NULL) {
            printf("%s", line);
            count++;
        }
    }

    printf("\n\nTotal number of errors found: %d\n", count);

    fclose(fp);

    if (line) {
        free(line);
    }

    return 0;
}