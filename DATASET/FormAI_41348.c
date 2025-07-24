//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum file name and metadata length
#define MAX_FILENAME_LENGTH 100
#define MAX_METADATA_LENGTH 1000

// Define struct for file metadata
typedef struct {
    char author[MAX_METADATA_LENGTH];
    char date[MAX_METADATA_LENGTH];
    char description[MAX_METADATA_LENGTH];
    char keywords[MAX_METADATA_LENGTH];
} Metadata;

// Function for reading metadata from file
int read_metadata(const char* filename, Metadata* metadata) {
    // Open file in read-mode
    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("Failed to open file %s\n", filename);
        return -1;
    }

    // Read metadata from file
    char line[MAX_METADATA_LENGTH];
    while (fgets(line, MAX_METADATA_LENGTH, file_ptr) != NULL) {
        if (strncmp(line, "Author:", 7) == 0) {
            strcpy(metadata->author, line+8);
        }
        else if (strncmp(line, "Date:", 5) == 0) {
            strcpy(metadata->date, line+6);
        }
        else if (strncmp(line, "Description:", 12) == 0) {
            strcpy(metadata->description, line+13);
        }
        else if (strncmp(line, "Keywords:", 9) == 0) {
            strcpy(metadata->keywords, line+10);
        }
    }

    // Close file and return success code
    fclose(file_ptr);
    return 0;
}

int main() {
    // Define filename and metadata variables
    char filename[MAX_FILENAME_LENGTH];
    Metadata metadata;

    // Prompt user for filename
    printf("Enter filename to extract metadata from: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\r\n")] = '\0'; // remove newline character

    // Extract metadata from file
    int result = read_metadata(filename, &metadata);
    if (result == 0) {
        // Print metadata to console
        printf("\nMetadata for %s:\n", filename);
        printf("- Author: %s", metadata.author);
        printf("- Date: %s", metadata.date);
        printf("- Description: %s", metadata.description);
        printf("- Keywords: %s", metadata.keywords);
    }

    return 0;
}