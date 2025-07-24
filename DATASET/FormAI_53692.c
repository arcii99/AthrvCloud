//FormAI DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *fp;
    char filename[] = "nonexistent_file.txt";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // some code that uses the file

    if (fclose(fp) != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return 0;
}