//FormAI DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char* filename = "non_existent_file.txt";
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);

        // Using the system's errno to handle the error
        switch(errno) {
            case ENOENT:
                printf("File '%s' does not exist.\n", filename);
                break;
            case EACCES:
                printf("Access to file '%s' is denied.\n", filename);
                break;
            default:
                printf("Unknown error occurred while opening file '%s'.\n", filename);
                break;
        }

        // Exiting the program with a non-zero status code
        exit(EXIT_FAILURE);
    }

    // If the file was opened successfully, continue with the program
    printf("File '%s' opened successfully.\n", filename);

    fclose(fp);

    return 0;
}