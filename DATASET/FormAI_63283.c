//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024   // Maximum length for a line in the metadata file
#define MAX_METADATA_LINES 16 // Maximum number of lines in the metadata file
#define MAX_KEY_LENGTH 32      // Maximum length for a metadata key
#define MAX_VALUE_LENGTH 128   // Maximum length for a metadata value

// Struct to store metadata key-value pairs
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} MetadataPair;

// Function to extract metadata key-value pairs from a file
int extract_metadata(const char* filename, MetadataPair* metadata, int max_pairs) {
    FILE* file = fopen(filename, "r"); // Open file for read-only access
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s' for reading.\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    int pair_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line_num++;

        if (pair_count >= max_pairs) {
            fprintf(stderr, "Error: Maximum number of metadata pairs reached (%d).\n", max_pairs);
            fclose(file);
            return -1;
        }

        if (line[0] == '#' || line[0] == '\n') {
            continue; // Skip comments and empty lines
        }

        char* separator = strchr(line, '='); // Find the key-value separator (=)
        if (separator == NULL) {
            fprintf(stderr, "Error: Invalid metadata format on line %d.\n", line_num);
            fclose(file);
            return -1;
        }

        *separator = '\0'; // Null-terminate the key string at the separator
        strncpy(metadata[pair_count].key, line, MAX_KEY_LENGTH-1); // Copy the key string to the metadata array
        metadata[pair_count].key[MAX_KEY_LENGTH-1] = '\0'; // Make sure the key string is null-terminated
        
        strncpy(metadata[pair_count].value, separator+1, MAX_VALUE_LENGTH-1); // Copy the value string to the metadata array
        metadata[pair_count].value[MAX_VALUE_LENGTH-1] = '\0'; // Make sure the value string is null-terminated

        pair_count++;
    }

    fclose(file);

    return pair_count;
}

int main() {
    MetadataPair metadata[MAX_METADATA_LINES];
    int num_pairs;

    num_pairs = extract_metadata("example_metadata.txt", metadata, MAX_METADATA_LINES);

    if (num_pairs < 0) {
        fprintf(stderr, "Error extracting metadata.\n");
        return EXIT_FAILURE;
    }

    printf("Loaded metadata:\n");
    for (int i = 0; i < num_pairs; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    return EXIT_SUCCESS;
}