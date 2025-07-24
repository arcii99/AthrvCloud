//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
// Metadata Extractor Program
// Version 1.0.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100

// function to extract metadata
void extract_metadata(const char* filename) {
    printf("Extracting metadata from %s...\n", filename);
    // code to extract metadata goes here
    printf("Metadata extraction complete.\n");
}

int main() {
    char filename[MAX_FILE_NAME];
    printf("Enter the name of the file to extract metadata from: ");
    fgets(filename, MAX_FILE_NAME, stdin);
    // remove newline from filename
    filename[strcspn(filename, "\n")] = 0;
    // check if file extension is valid
    char* ext = strrchr(filename, '.');
    if (ext == NULL || strcmp(ext, ".c") != 0) {
        printf("Invalid file extension. Metadata can only be extracted from .c files.\n");
        return 1;
    }
    // call function to extract metadata
    extract_metadata(filename);
    return 0;
}