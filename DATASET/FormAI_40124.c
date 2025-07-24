//FormAI DATASET v1.0 Category: Error handling ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc != 2) { // Check if the number of arguments is correct
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r"); // Open the file for reading
    if (fp == NULL) { // Check if the file was opened correctly
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    // File processing code here...

    if (fclose(fp) != 0) { // Check if the file was closed correctly
        perror("fclose");
        exit(EXIT_FAILURE);
    }

    return 0;
}