//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct representing C metadata
typedef struct {
    char* filename;
    char* author;
    char* date;
    int num_lines;
} CMetadata;

// Function to extract metadata from C file
CMetadata extract_metadata(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);
    }

    char line[256];
    char* metadata[] = {"Filename:", "Author:", "Date:"};
    CMetadata c_metadata = {NULL, NULL, NULL, 0};

    while (fgets(line, sizeof(line), file)) {
        // Check if line contains metadata
        for (int i = 0; i < sizeof(metadata) / sizeof(metadata[0]); i++) {
            char* pos = strstr(line, metadata[i]);
            if (pos != NULL) {
                pos += strlen(metadata[i]);
                while (*pos == ' ') pos++;

                // Store metadata in struct
                switch (i) {
                    case 0:
                        c_metadata.filename = strdup(pos);
                        break;
                    case 1:
                        c_metadata.author = strdup(pos);
                        break;
                    case 2:
                        c_metadata.date = strdup(pos);
                        break;
                }
            }
        }

        // Count number of lines in file
        c_metadata.num_lines++;
    }

    fclose(file);

    return c_metadata;
}

int main() {
    char* file_path = "example.c";
    CMetadata c_metadata = extract_metadata(file_path);

    printf("Metadata for file '%s':\n", file_path);
    printf("Filename: %s", c_metadata.filename);
    printf("Author: %s", c_metadata.author);
    printf("Date: %s", c_metadata.date);
    printf("Number of lines: %d\n", c_metadata.num_lines);

    return 0;
}