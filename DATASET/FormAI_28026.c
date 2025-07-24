//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handleError(int errnum, const char *msg) {
    if (errnum == EACCES) {
        fprintf(stderr, "Access error: %s\n", msg);
    } else if (errnum == ENOENT) {
        fprintf(stderr, "File not found: %s\n", msg);
    } else if (errnum == EINVAL) {
        fprintf(stderr, "Invalid argument: %s\n", msg);
    } else {
        fprintf(stderr, "Error %d: %s\n", errnum, msg);
    }

    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        handleError(errno, argv[1]);
    }

    int numLines = 0;
    char buffer[1024];

    while (fgets(buffer, 1024, fp) != NULL) {
        numLines++;
        printf("Line %d: %s", numLines, buffer);
    }

    if (fclose(fp) == -1) {
        handleError(errno, "");
    }

    printf("File read successfully.\n");

    return 0;
}