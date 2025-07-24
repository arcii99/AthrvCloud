//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Metadata of file %s:\n", argv[1]);

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "author:")) {
            printf("Author: %s", line + 7);
        } else if (strstr(line, "title:")) {
            printf("Title: %s", line + 6);
        } else if (strstr(line, "date:")) {
            printf("Date: %s", line + 5);
        }
    }

    printf("\n");

    fclose(fp);
    if (line) free(line);
    exit(EXIT_SUCCESS);
}