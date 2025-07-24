//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of metadata we'll allow
#define MAX_META_LEN 256

// Define structure for metadata key-value pair
typedef struct metadata {
    char key[MAX_META_LEN];
    char value[MAX_META_LEN];
} metadata_t;

// Define structure for directory entry
typedef struct dir_entry {
    char filename[MAX_META_LEN];
    metadata_t *metadata;
    int num_metadata;
} dir_entry_t;

// Function to extract metadata from a file
metadata_t *extract_metadata(char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }
    // Read the metadata line-by-line and store it in a dynamically allocated array
    char line[MAX_META_LEN];
    metadata_t *metadata = malloc(0);
    int num_metadata = 0;
    while (fgets(line, MAX_META_LEN, file)) {
        // Strip the newline character from the end of the line
        line[strcspn(line, "\n")] = 0;
        // Check if the line is a metadata line
        if (strncmp(line, "meta:", 5) == 0) {
            // Split the line into key and value
            char *key = strtok(line+5, "=");
            char *value = strtok(NULL, "=");
            // Allocate memory for the new metadata entry and copy the key/value
            metadata_t new_metadata;
            strcpy(new_metadata.key, key);
            strcpy(new_metadata.value, value);
            // Append the new metadata entry to the array
            metadata = realloc(metadata, (num_metadata+1)*sizeof(metadata_t));
            metadata[num_metadata++] = new_metadata;
        }
    }
    // Close the file and return the metadata array
    fclose(file);
    if (num_metadata == 0) {
        printf("No metadata found in file: %s\n", filename);
        free(metadata);
        return NULL;
    } else {
        metadata_t *result = realloc(metadata, num_metadata*sizeof(metadata_t));
        return result;
    }
}

// Function to print metadata key-value pairs
void print_metadata(metadata_t *metadata, int num_metadata) {
    for (int i = 0; i < num_metadata; ++i) {
        printf("%s=%s\n", metadata[i].key, metadata[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Filename not provided\n");
        return 1;
    }
    // Extract metadata from file and print it
    metadata_t *metadata = extract_metadata(argv[1]);
    if (metadata) {
        print_metadata(metadata, sizeof(metadata)/sizeof(metadata_t));
        free(metadata);
    }
    return 0;
}