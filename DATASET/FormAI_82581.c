//FormAI DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        if (errno == ENOENT) {
            printf("File not found: %s\n", argv[1]);
        } else if (errno == EACCES) {
            printf("You do not have permission to access this file: %s\n", argv[1]);
        } else {
            printf("Unknown error occurred while opening the file: %s\n", argv[1]);
        }
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    if (ferror(fp)) {
        printf("An error occurred while reading the file: %s\n", argv[1]);
    }

    if (fclose(fp) == EOF) {
        printf("An error occurred while closing the file: %s\n", argv[1]);
    }

    return 0;
}