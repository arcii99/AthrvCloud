//FormAI DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH_MAX 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char lineBuf[LINE_LENGTH_MAX];
    char *token;
    char *filename;
    char *searchTerm;
    int lineNumber = 1;
    int count = 0;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <logfile> <search_term>\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];
    searchTerm = argv[2];

    file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Could not open %s\n", filename);
        return EXIT_FAILURE;
    }

    while (fgets(lineBuf, LINE_LENGTH_MAX, file)) {
        token = strtok(lineBuf, " ");

        if (!strcmp(token, searchTerm)) {
            count++;
            printf("Found at line %d: %s", lineNumber, lineBuf);
        }

        lineNumber++;
    }

    printf("Found %d occurrences of '%s' in %s\n", count, searchTerm, filename);

    fclose(file);

    return EXIT_SUCCESS;
}