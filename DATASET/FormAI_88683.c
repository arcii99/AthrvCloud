//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
    char author[128];
    char version[32];
    char date[64];
} Metadata;

Metadata extract_metadata(const char* filename) {
    Metadata metadata = {0};
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open the file %s\n", filename);
        return metadata;
    }
    
    char line[MAX_METADATA_SIZE];
    while (fgets(line, MAX_METADATA_SIZE, file)) {
        char* key = strtok(line, ":"); // Split the line to key:value pair
        char* value = strtok(NULL, ":");
        if (key && value) {
            key[strcspn(key, "\r\n")] = '\0';
            value[strcspn(value, "\r\n")] = '\0';
            
            // Store the metadata to the corresponding field according to the key
            if (strcmp(key, "author") == 0) {
                strncpy(metadata.author, value, sizeof(metadata.author));
            }
            else if (strcmp(key, "version") == 0) {
                strncpy(metadata.version, value, sizeof(metadata.version));
            }
            else if (strcmp(key, "date") == 0) {
                strncpy(metadata.date, value, sizeof(metadata.date));
            }
        }
    }
    fclose(file);
    
    return metadata;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }
    
    Metadata metadata = extract_metadata(argv[1]);
    
    // Print the metadata
    printf("Author : %s\n", metadata.author);
    printf("Version: %s\n", metadata.version);
    printf("Date   : %s\n", metadata.date);
    
    return 0;
}