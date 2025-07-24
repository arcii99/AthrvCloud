//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* This program is designed to extract metadata from a C program and display it to the user.
* It supports the following metadata: program name, author, creation date, and last modified date.
*/

int main(int argc, char *argv[]) {
    // Ensure correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: ./metadata program_name.c\n");
        return 1;
    }

    // Open the input file
    FILE *fp = fopen(argv[1], "r");

    // Make sure the file exists
    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open file.\n");
        return 2;
    }

    char line[100];

    // Initialize metadata variables
    char *program_name = NULL;
    char *author = NULL;
    char *creation_date = NULL;
    char *last_modified_date = NULL;

    // Read each line in the file
    while (fgets(line, sizeof(line), fp)) {
        // Check for program name
        if (strstr(line, "Program Name:") != NULL) {
            strtok(line, ":");
            program_name = strtok(NULL, "\n");
        }

        // Check for author
        if (strstr(line, "Author:") != NULL) {
            strtok(line, ":");
            author = strtok(NULL, "\n");
        }

        // Check for creation date
        if (strstr(line, "Created:") != NULL) {
            strtok(line, ":");
            creation_date = strtok(NULL, "\n");
        }

        // Check for last modified date
        if (strstr(line, "Last Modified:") != NULL) {
            strtok(line, ":");
            last_modified_date = strtok(NULL, "\n");
        }
    }

    // Print out metadata
    printf("Program Name: %s\n", program_name);
    printf("Author: %s\n", author);
    printf("Creation Date: %s\n", creation_date);
    printf("Last Modified Date: %s\n", last_modified_date);

    // Close the input file
    fclose(fp);

    return 0;
}