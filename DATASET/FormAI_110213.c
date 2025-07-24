//FormAI DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *file = NULL;
    char *filename = "non_existent_file.txt";
    char *buffer = NULL;
    size_t size = 0;

    // Attempt to open the file for reading
    if ((file = fopen(filename, "r")) == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    // Allocate a buffer to store the file content
    buffer = malloc(size + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Read the file content into the buffer
    if (fread(buffer, 1, size, file) != size) {
        perror("Failed to read file");
        exit(EXIT_FAILURE);
    }

    // Print the file content
    printf("File content:\n%s", buffer);

    // Clean up resources
    free(buffer);
    fclose(file);

    return 0;
}