//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold metadata for a file
typedef struct file_metadata {
    char* filename; // Name of the file
    char* author; // Author of the file
    char* date_created; // Date the file was created
    char* date_modified; // Date the file was last modified
    int file_size; // Size of the file in bytes
} file_metadata;

// Function to extract metadata from a file
file_metadata* extract_metadata(char* filename) {
    // Allocate memory for the metadata struct
    file_metadata* metadata = (file_metadata*) malloc(sizeof(file_metadata));
    // Initialize metadata values to NULL or 0
    metadata->filename = NULL;
    metadata->author = NULL;
    metadata->date_created = NULL;
    metadata->date_modified = NULL;
    metadata->file_size = 0;
    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // Error opening the file
        printf("Error opening file: %s\n", filename);
        return metadata;
    }
    // Read the first line of the file, which should contain the filename
    char line[256];
    if (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character from line
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }
        // Allocate memory for the filename and copy the line into it
        metadata->filename = (char*) malloc(len + 1);
        strncpy(metadata->filename, line, len + 1);
    }
    // Read the remaining lines of the file, looking for metadata tags
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character from line
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }
        // Check for author tag
        if (strncmp(line, "<author>", 8) == 0) {
            // Allocate memory for the author and copy the value between the tags into it
            metadata->author = (char*) malloc(len - 15);
            strncpy(metadata->author, line + 8, len - 15);
        }
        // Check for date created tag
        else if (strncmp(line, "<date_created>", 14) == 0) {
            // Allocate memory for the date created and copy the value between the tags into it
            metadata->date_created = (char*) malloc(len - 27);
            strncpy(metadata->date_created, line + 14, len - 27);
        }
        // Check for date modified tag
        else if (strncmp(line, "<date_modified>", 15) == 0) {
            // Allocate memory for the date modified and copy the value between the tags into it
            metadata->date_modified = (char*) malloc(len - 28);
            strncpy(metadata->date_modified, line + 15, len - 28);
        }
        // Check for file size tag
        else if (strncmp(line, "<file_size>", 11) == 0) {
            // Convert the value between the tags to an integer and store it in metadata
            metadata->file_size = atoi(line + 11);
        }
    }
    // Close the file
    fclose(file);
    // Return the metadata struct
    return metadata;
}

int main() {
    // Test the metadata extraction function
    file_metadata* metadata = extract_metadata("example_file.txt");
    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Date created: %s\n", metadata->date_created);
    printf("Date modified: %s\n", metadata->date_modified);
    printf("File size: %d bytes\n", metadata->file_size);
    // Free the allocated memory
    free(metadata->filename);
    free(metadata->author);
    free(metadata->date_created);
    free(metadata->date_modified);
    free(metadata);
    return 0;
}