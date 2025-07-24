//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *fp;

    // check if user provided filename
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open the file
    fp = fopen(argv[1], "r");

    // check if file opening was successful or not
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    // read contents of file
    char c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    // close the file
    if (fclose(fp) == EOF) {
        fprintf(stderr, "Error closing file %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}