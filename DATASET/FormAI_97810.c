//FormAI DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Check if the user provided the correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        // Print an error message with the appropriate error code
        printf("Error opening file: %s (error code: %d)\n", strerror(errno), errno);
        exit(EXIT_FAILURE);
    }

    // Read the contents of the file
    char buffer[1024];
    int bytesRead = fread(buffer, sizeof(char), sizeof(buffer), fp);
    if (ferror(fp) != 0) {
        // Print an error message with the appropriate error code
        printf("Error reading file: %s (error code: %d)\n", strerror(errno), errno);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Print the contents of the file
    printf("File contents:\n%s", buffer);

    // Close the file
    if (fclose(fp) != 0) {
        // Print an error message with the appropriate error code
        printf("Error closing file: %s (error code: %d)\n", strerror(errno), errno);
        exit(EXIT_FAILURE);
    }

    return 0;
}