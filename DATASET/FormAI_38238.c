//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define error codes
#define FILE_NOT_FOUND 404
#define FILE_WRITE_ERROR 500

int main() {

    FILE *file;

    // Open file for reading
    file = fopen("example.txt", "r");

    // Check if file exists
    if (file == NULL) {
        printf("Error: File not found (error code %d).\n", FILE_NOT_FOUND);
        return FILE_NOT_FOUND;
    }

    // Read file and print contents to console
    printf("Contents of example.txt:\n");
    char character;
    while ((character = fgetc(file)) != EOF) {
        printf("%c", character);
    }
    printf("\n");

    // Close file
    fclose(file);

    // Open file for writing
    file = fopen("example.txt", "w");

    // Check if file can be written to
    if (file == NULL) {
        printf("Error: Could not write to file (error code %d).\n", FILE_WRITE_ERROR);
        return FILE_WRITE_ERROR;
    }

    // Write to file
    fputs("This is an example file.\n", file);

    // Close file
    fclose(file);

    // Open file again for reading
    file = fopen("example.txt", "r");

    // Read file and print contents to console again
    printf("New contents of example.txt:\n");
    while ((character = fgetc(file)) != EOF) {
        printf("%c", character);
    }
    printf("\n");

    // Close file
    fclose(file);

    return 0;
}