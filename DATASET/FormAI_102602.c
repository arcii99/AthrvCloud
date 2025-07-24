//FormAI DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    long long lines = 0;
    long long errors = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        lines++;

        if (strstr(line, "ERROR") != NULL) {
            errors++;
            printf("%s", line);
        }
    }
    printf("Total lines: %lld\n", lines);
    printf("Total errors: %lld\n", errors);

    if (line)
        free(line);

    fclose(fp);
    exit(EXIT_SUCCESS);
}