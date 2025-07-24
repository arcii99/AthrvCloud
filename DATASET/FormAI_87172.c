//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program extracts metadata from a C source file

int main(int argc, char *argv[]) {

    // Checking if filename argument was passed
    if (argc < 2) {
        printf("Usage: ./metadata-extractor <file.c>\n");
        return 1;
    }

    // Opening file for reading
    FILE *file = fopen(argv[1], "r");

    // Checking if file exists
    if (file == NULL) {
        printf("Error: %s does not exist\n", argv[1]);
        return 1;
    }

    // Reading file line by line
    char line[100];
    char *name, *date, *description;
    while (fgets(line, 100, file)) {
        // Checking if line contains metadata
        if (strstr(line, "// Name: ")) {
            name = strchr(line, ' ') + 1;
            // Removing newline character
            name[strlen(name)-1] = '\0';
        }
        if (strstr(line, "// Date: ")) {
            date = strchr(line, ' ') + 1;
            date[strlen(date)-1] = '\0';
        }
        if (strstr(line, "// Description: ")) {
            description = strchr(line, ' ') + 1;
            description[strlen(description)-1] = '\0';
        }
    }

    // Closing file
    fclose(file);

    // Printing extracted metadata
    printf("Name: %s\n", name);
    printf("Date: %s\n", date);
    printf("Description: %s\n", description);

    return 0;
}