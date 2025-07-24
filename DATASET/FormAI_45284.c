//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold metadata information
typedef struct metadata {
    char* author;
    char* title;
    int year;
    char* description;
} Metadata;

// Function to extract metadata from a file
Metadata extract_metadata(char* filename) {
    // Open file in read mode
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    // Allocate memory for metadata struct
    Metadata data;
    data.author = (char*)malloc(256*sizeof(char));
    data.title = (char*)malloc(256*sizeof(char));
    data.description = (char*)malloc(512*sizeof(char));
    // Read file line by line
    char line[512];
    while(fgets(line, 512, fp)) {
        // Check for metadata tags
        if (strstr(line, "AUTHOR:")) {
            // Copy author name to struct
            char* name = strchr(line, ':') + 1;
            strcpy(data.author, name);
        }
        else if (strstr(line, "TITLE:")) {
            // Copy title to struct
            char* title = strchr(line, ':') + 1;
            strcpy(data.title, title);
        }
        else if (strstr(line, "YEAR:")) {
            // Copy year to struct
            char* year_str = strchr(line, ':') + 1;
            data.year = atoi(year_str);
        }
        else if (strstr(line, "DESCRIPTION:")) {
            // Copy description to struct
            char* desc = strchr(line, ':') + 1;
            strcpy(data.description, desc);
        }
    }
    // Close file
    fclose(fp);
    // Return metadata struct
    return data;
}

int main() {
    // Test metadata extraction
    Metadata data = extract_metadata("book.txt");
    printf("Author: %s\n", data.author);
    printf("Title: %s\n", data.title);
    printf("Year: %d\n", data.year);
    printf("Description: %s\n", data.description);
    // Free memory
    free(data.author);
    free(data.title);
    free(data.description);
    return 0;
}