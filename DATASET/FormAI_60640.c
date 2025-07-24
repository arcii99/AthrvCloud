//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void) {
    FILE *file;
    char *filename = "nonexistent.txt";
    int num;

    // Try to open the file
    file = fopen(filename, "r");

    if (file == NULL) {
        // The file could not be opened, check for error
        switch (errno) {
            case ENOENT:
                printf("Error: File not found\n");
                break;
            case EACCES:
                printf("Error: Permission denied\n");
                break;
            default:
                printf("Error: %s\n", strerror(errno));
                break;
        }
        return EXIT_FAILURE;
    }

    // The file was successfully opened, read a number from it
    if (fscanf(file, "%d", &num) == 1) {
        printf("The number is %d\n", num);
    }
    else {
        printf("Error: Could not read number from file\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);
    return EXIT_SUCCESS;
}