//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 100000 // maximum size for input file
#define MAX_METADATA_SIZE 1000 // maximum size for metadata

// Function to extract metadata from the given input file and store it in the metadata string.
// Returns 1 if successful and 0 if there was an error.
int extract_metadata(const char* input_file, char* metadata) {
    FILE* fp = NULL;
    char buffer[MAX_FILE_SIZE];
    char* ptr = NULL;
    int i = 0;
    int j = 0;
    int count = 0;

    // Open input file in read mode
    fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error opening input file!\n");
        return 0;
    }

    // Read input file contents into a buffer
    if (fgets(buffer, MAX_FILE_SIZE, fp) == NULL) {
        printf("Error reading input file contents!\n");
        fclose(fp);
        return 0;
    }

    // Search for metadata markers in the input file buffer
    ptr = strstr(buffer, "BEGIN_METADATA");
    if (ptr == NULL) {
        printf("Error: metadata marker not found!\n");
        fclose(fp);
        return 0;
    }

    ptr += strlen("BEGIN_METADATA");
    while (*ptr == ' ' || *ptr == '\t' || *ptr == '\r' || *ptr == '\n') {
        ptr++; // Skip whitespace characters
    }

    // Extract metadata from input file buffer
    for (i = 0; i < MAX_METADATA_SIZE; i++) {
        if (*ptr == '\0' || *ptr == '\n' || count >= 2) {
            break; // Stop when end of metadata or two newline characters are encountered
        }
        metadata[i] = *ptr++;
        if (metadata[i] == ':') {
            count++;
        }
    }

    // Remove any trailing whitespace characters from the metadata string
    j = i - 1;
    while (j >= 0 && (metadata[j] == ' ' || metadata[j] == '\t' || metadata[j] == '\r' || metadata[j] == '\n')) {
        metadata[j--] = '\0';
    }

    // Close input file
    fclose(fp);

    // Check if metadata string is empty
    if (strlen(metadata) == 0) {
        printf("Error: no metadata found!\n");
        return 0;
    }

    // Return success
    return 1;
}

int main() {
    char metadata[MAX_METADATA_SIZE];

    // Extract metadata from input file
    if (extract_metadata("input.txt", metadata)) {
        printf("Metadata: %s\n", metadata);
    }
    
    return 0;
}