//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function declarations
void extract_metadata(char *filename);

// Main function
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    extract_metadata(filename);

    return 0;
}

// Function to extract metadata from file
void extract_metadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char *key, *value;
    int num_lines = 0;

    // Read file line by line
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        // Check if the line contains metadata
        if (strstr(buffer, "META:") != NULL) {
            num_lines++;
            printf("Metadata Line %d: %s", num_lines, buffer);

            // Extract key-value pair from metadata line
            key = strtok(buffer, ":");
            value = strtok(NULL, ":");

            // Remove leading/trailing spaces from value
            value[strcspn(value, "\n")] = '\0'; // Remove newline character
            while (*value == ' ') value++; // Remove leading spaces
            char *end;
            while (isspace(end = *(value + strlen(value) - 1))); // Remove trailing spaces
            *(end + 1) = '\0';

            printf("Key: %s\tValue: %s\n", key, value);
        }
    }

    fclose(fp);

    if (num_lines == 0) {
        printf("No metadata found in file.\n");
    }
}