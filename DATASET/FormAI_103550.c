//FormAI DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: program <filename>\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        if (errno == ENOENT) {
            printf("File does not exist: %s\n", argv[1]);
            exit(EXIT_FAILURE);
        } else {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }

    printf("File opened successfully: %s\n", argv[1]);

    // rest of program logic goes here

    fclose(file);
    return EXIT_SUCCESS;
}