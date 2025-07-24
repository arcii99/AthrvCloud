//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read metadata from file
int read_metadata(char* filename, char* metadata) {
    FILE* fp;
    char buffer[100];
    int i = 0;

    // Open file in read mode
    fp = fopen(filename, "r");

    // If file doesn't exist, return error
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    // Read file line by line
    while (fgets(buffer, 100, fp) != NULL) {
        // Check if line contains metadata
        if (strstr(buffer, "Metadata:") != NULL) {
            // Copy metadata to buffer
            strcpy(metadata, buffer+strlen("Metadata:"));
            // Remove newline character from end of string
            metadata[strcspn(metadata, "\n")] = 0;
            // Increment counter
            i++;
        }
    }

    // Close file
    fclose(fp);

    // If no metadata was found, return error
    if (i == 0) {
        printf("Error: No metadata found in file %s\n", filename);
        return -1;
    }

    // Return number of metadata records found
    return i;
}

int main() {
    char metadata[100];
    int num_metadata;

    // Call read_metadata function
    num_metadata = read_metadata("example.txt", metadata);

    // Print metadata
    printf("Metadata: %s\n", metadata);

    // Print number of metadata records found
    printf("Number of metadata records found: %d\n", num_metadata);

    return 0;
}