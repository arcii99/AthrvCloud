//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *file;
    char *filename = "nonexistent_file.txt";

    // Opening the file 
    file = fopen(filename, "r");
    if (file == NULL) {
        // Checking for any error in opening the file
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Reading the file
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Closing the file
    if (fclose(file) == -1) {
        // Checking for any error in closing the file
        fprintf(stderr, "Error closing file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}