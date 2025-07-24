//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_SIZE 1000

// Function to extract metadata
void extract_metadata(char* filename) {

    // Open file for reading
    FILE* fp = fopen(filename, "r");

    // Check if file exists or not
    if (fp == NULL) {
        printf("Sorry, the file %s does not exist.\n", filename);
        return;
    }

    // Variables to store metadata
    char author[MAX_SIZE];
    char date[MAX_SIZE];
    char version[MAX_SIZE];
    char description[MAX_SIZE];

    // Read file line by line until metadata is found
    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, fp)) {
        if (strncmp(line, "// Author:", 10) == 0) {
            strcpy(author, line + 11);
        } else if (strncmp(line, "// Date:", 8) == 0) {
            strcpy(date, line + 9);
        } else if (strncmp(line, "// Version:", 11) == 0) {
            strcpy(version, line + 12);
        } else if (strncmp(line, "// Description:", 15) == 0) {
            strcpy(description, line + 16);
            break;
        }
    }

    // Close file
    fclose(fp);

    // Print extracted metadata
    printf("Author: %s", author);
    printf("Date: %s", date);
    printf("Version: %s", version);
    printf("Description: %s", description);
}

// Main function
int main() {
    // Extract metadata from sample file
    extract_metadata("sample.c");
    return 0;
}