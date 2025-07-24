//FormAI DATASET v1.0 Category: Error handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    FILE *fp;

    fp = fopen("non_existing_file.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Do something with the file...

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}