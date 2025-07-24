//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    // Check if user provided filename
    if (argc < 2) {
        fprintf(stderr, "Usage: ./file_read <filename>\n");
        exit(EXIT_FAILURE);
    }

    // Attempt to open file
    fp = fopen(argv[1], "r");

    // Check if file was successfully opened
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n",
                argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Read and output contents of file
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }

    // Check if error occurred while reading file
    if (ferror(fp)) {
        fprintf(stderr, "Error reading file %s: %s\n",
                argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Close the file
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file %s: %s\n",
                argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}