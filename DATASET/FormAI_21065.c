//FormAI DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *file_ptr;

    if (argc != 2) {
        printf("Error: Missing file name argument!\n");
        exit(EXIT_FAILURE);
    }

    if ((file_ptr = fopen(argv[1], "r")) == NULL) {
        printf("Error %d: Unable to open file '%s'\n", errno, argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("File '%s' opened successfully\n", argv[1]);

    // Do some processing on the file

    if (fclose(file_ptr) != 0) {
        printf("Error %d: Unable to close file '%s'\n", errno, argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("File '%s' closed successfully\n", argv[1]);

    return 0;
}