//FormAI DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// define a custom error code
#define MY_ERROR_CODE 500

int main() {
    FILE *fp;

    // attempt to open a file
    fp = fopen("nonexistentfile.txt", "r");
    if (fp == NULL) {
        // file could not be opened
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // divide by zero to force a runtime error
    int numerator = 10;
    int denominator = 0;
    int result;
    if (denominator == 0) {
        result = numerator / denominator;
    }

    // check for runtime error and handle it
    if (errno == EDOM || errno == ERANGE || result == MY_ERROR_CODE) {
        printf("A runtime error occurred.\n");
        exit(EXIT_FAILURE);
    }

    // close file and exit
    fclose(fp);
    return 0;
}