//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program extracts metadata from a C file
 * and prints it out to the console.
 * It reads the file line by line and looks for
 * metadata tags which are defined as comments
 * starting with the word "METADATA".
 * The program prints out the value associated with each tag.
 * Valid tags are: "AUTHOR", "VERSION", "DESCRIPTION"
 * Example usage: ./metadata_extractor my_program.c
*/

#define MAX_LINE_LENGTH 256
#define MAX_TAG_LENGTH 32

int main(int argc, char** argv) {

    // Check if file name is provided
    if (argc < 2) {
        printf("ERROR: Please provide file name as argument.\n");
        return -1;
    }

    // Open the C file
    FILE *file = fopen(argv[1], "r");

    // Check if file is successfully opened
    if (file == NULL) {
        printf("ERROR: Could not open file %s.\n", argv[1]);
        return -1;
    }

    // Variables for metadata
    char author[MAX_TAG_LENGTH];
    char version[MAX_TAG_LENGTH];
    char description[MAX_TAG_LENGTH];

    // Read the file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {

        // Look for metadata tags
        if (strstr(line, "METADATA")) {

            // Look for AUTHOR tag
            if (strstr(line, "AUTHOR")) {
                char *start = strstr(line, "AUTHOR ");
                strncpy(author, start + strlen("AUTHOR "), MAX_TAG_LENGTH);
            }

            // Look for VERSION tag
            if (strstr(line, "VERSION")) {
                char *start = strstr(line, "VERSION ");
                strncpy(version, start + strlen("VERSION "), MAX_TAG_LENGTH);
            }

            // Look for DESCRIPTION tag
            if (strstr(line, "DESCRIPTION")) {
                char *start = strstr(line, "DESCRIPTION ");
                strncpy(description, start + strlen("DESCRIPTION "), MAX_TAG_LENGTH);
            }
        }
    }

    // Print out the metadata
    printf("AUTHOR: %s", author);
    printf("VERSION: %s", version);
    printf("DESCRIPTION: %s", description);

    // Close the file
    fclose(file);

    return 0;
}