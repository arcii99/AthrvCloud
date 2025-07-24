//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of metadata
#define MAX_METADATA_LEN 100

// Define the metadata structure
typedef struct {
    char author[MAX_METADATA_LEN];
    char date[MAX_METADATA_LEN];
    char version[MAX_METADATA_LEN];
    char description[MAX_METADATA_LEN];
} Metadata;

// Function to extract metadata from a file
Metadata extract_metadata(char* filepath) {
    // Define the metadata object
    Metadata metadata;

    // Open the file
    FILE* file = fopen(filepath, "r");

    // If the file cannot be opened, return empty metadata
    if (!file) {
        printf("Error opening file.");
        memset(&metadata, 0, sizeof(Metadata));
        return metadata;
    }

    // Read the file line by line
    char line[MAX_METADATA_LEN];
    while (fgets(line, MAX_METADATA_LEN, file)) {
        // If the line contains metadata, extract it
        if (strncmp(line, "// Author:", 10) == 0) {
            strcpy(metadata.author, &line[10]);
            metadata.author[strcspn(metadata.author, "\n")] = 0;
        } else if (strncmp(line, "// Date:", 8) == 0) {
            strcpy(metadata.date, &line[8]);
            metadata.date[strcspn(metadata.date, "\n")] = 0;
        } else if (strncmp(line, "// Version:", 11) == 0) {
            strcpy(metadata.version, &line[11]);
            metadata.version[strcspn(metadata.version, "\n")] = 0;
        } else if (strncmp(line, "// Description:", 15) == 0) {
            strcpy(metadata.description, &line[15]);
            metadata.description[strcspn(metadata.description, "\n")] = 0;
        }
    }

    // Close the file
    fclose(file);

    // Return the metadata object
    return metadata;
}

// Example usage
int main() {
    // Extract metadata from a C source code file
    Metadata metadata = extract_metadata("example.c");

    // Print the metadata
    printf("Author: %s\n", metadata.author);
    printf("Date: %s\n", metadata.date);
    printf("Version: %s\n", metadata.version);
    printf("Description: %s\n", metadata.description);

    return 0;
}