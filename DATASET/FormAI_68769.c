//FormAI DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    FILE *fp;
    char *filename = "non_existent_file.txt";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // some code here that reads from the file

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}