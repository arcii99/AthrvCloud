//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to check if a given file has .c extension
bool hasCExtension(const char *filename) {
    const char *ext = strrchr(filename, '.');
    if (ext == NULL) {
        return false;
    }
    if (strcmp(ext, ".c") == 0) {
        return true;
    }
    return false;
}

// Function to extract metadata from a C file
void extractMetadata(const char *filename) {
    FILE *fp;
    char line[MAX_SIZE];
    int lines_count = 0;
    int comments_count = 0;
    int blank_lines_count = 0;
    int characters_count = 0;
    int max_line_length = 0;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Process the file line by line
    while (fgets(line, MAX_SIZE, fp) != NULL) {
        lines_count++;
        int length = strlen(line);
        characters_count += length;

        // Check if the line is a comment
        if (line[0] == '/' && line[1] == '/') {
            comments_count++;
        }

        // Check if the line is blank
        if (length == 1 && line[0] == '\n') {
            blank_lines_count++;
        }

        // Check the length of the line
        if (length > max_line_length) {
            max_line_length = length;
        }
    }

    // Close the file
    fclose(fp);

    // Print the metadata
    printf("Metadata for file %s:\n", filename);
    printf("Number of Lines: %d\n", lines_count);
    printf("Number of Comments: %d\n", comments_count);
    printf("Number of Blank Lines: %d\n", blank_lines_count);
    printf("Number of Characters: %d\n", characters_count);
    printf("Maximum Line Length: %d\n", max_line_length);
}

int main() {
    char filename[MAX_SIZE];

    // Get the file name from the user
    printf("Enter the file name: ");
    fgets(filename, MAX_SIZE, stdin);

    // Remove the trailing newline character from the filename
    filename[strcspn(filename, "\n")] = '\0';

    // Check if the file has .c extension
    if (!hasCExtension(filename)) {
        printf("Error: The file %s is not a C file\n", filename);
        return EXIT_FAILURE;
    }

    // Extract metadata from the file
    extractMetadata(filename);

    return EXIT_SUCCESS;
}