//FormAI DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *input_file;
    char *filename = argv[1];
    char buffer[256];
    int value;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Failed to open %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (fgets(buffer, sizeof(buffer), input_file) == NULL) {
        if (feof(input_file)) {
            fprintf(stderr, "Unexpected end of file in %s\n", filename);
            exit(EXIT_FAILURE);
        }
        if (ferror(input_file)) {
            fprintf(stderr, "Error reading from %s: %s\n", filename, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    value = atoi(buffer);
    if (value == 0) {
        fprintf(stderr, "Invalid value in %s: %s\n", filename, buffer);
        exit(EXIT_FAILURE);
    }

    printf("The value in the file is: %d\n", value);

    if (fclose(input_file) != 0) {
        fprintf(stderr, "Failed to close %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}