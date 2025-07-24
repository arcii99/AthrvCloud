//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
/*
   Title: C Metadata Extractor
   Author: [Your Name Here]
   Date: [Date Here]
   Description: This program extracts metadata from a C code file and displays it
*/

#include <stdio.h>

// Function to extract metadata
void extract_metadata(const char* filename) {
    FILE* fp;
    char line[256];
    int lines_count = 0;
    int function_count = 0;
    int variable_count = 0;
    int comment_count = 0;
    int header_count = 0;

    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("File doesn't exist.");
        return;
    }

    // Read each line of the file
    while (fgets(line, sizeof(line), fp)) {
        lines_count++;

        // Check for function declaration
        if ((line[0] == 'i' && line[1] == 'n' && line[2] == 't') || (line[0] == 'v' && line[1] == 'o' && line[2] == 'i' && line[3] == 'd' && line[4] == ' ' && line[5] != 'm' && line[6] != 'a' && line[7] != 'i' && line[8] != 'n')) {
            function_count++;
        }

        // Check for variable declaration
        if (line[0] == 'v' && line[1] == 'a' && line[2] == 'r' && line[3] == ' ') {
            variable_count++;
        }

        // Check for comments
        if (line[0] == '/' && line[1] == '/') {
            comment_count++;
        }

        // Check for header files
        if (line[0] == '#') {
            header_count++;
        }
    }

    // Close file
    fclose(fp);

    // Display metadata
    printf("Lines of code: %d\n", lines_count);
    printf("Functions: %d\n", function_count);
    printf("Variables: %d\n", variable_count);
    printf("Comments: %d\n", comment_count);
    printf("Header files: %d\n", header_count);
}

int main() {
    extract_metadata("example.c");
    return 0;
}