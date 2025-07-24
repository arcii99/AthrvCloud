//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to extract metadata from a C program
void extractMetadata(char* filename) {
    FILE* filePtr;
    char buffer[MAX];

    // Open the file in read mode
    filePtr = fopen(filename, "r");

    // Check if file was opened correctly
    if (filePtr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read line by line from file
    while (fgets(buffer, MAX, filePtr)) {
        // Check if line contains metadata
        if (strstr(buffer, "/*") != NULL) {
            // Extract metadata from line
            char* start = strstr(buffer, "/*") + 2;
            char* end = strstr(buffer, "*/") - 1;
            int length = end - start + 1;

            // Print metadata
            printf("%.*s\n", length, start);
        }
    }

    // Close the file
    fclose(filePtr);
}

int main() {
    char filename[MAX];

    // Get filename from user
    printf("Enter filename: ");
    fgets(filename, MAX, stdin);
    strtok(filename, "\n");

    // Extract metadata from file
    extractMetadata(filename);

    return 0;
}