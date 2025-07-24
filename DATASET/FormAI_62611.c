//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of the metadata and data strings
#define MAX_METADATA_LENGTH 100
#define MAX_DATA_LENGTH 1000

// Define the struct to hold the metadata key-value pairs
typedef struct metadata {
    char key[MAX_METADATA_LENGTH];
    char value[MAX_DATA_LENGTH];
} metadata_t;

// Define the function to extract metadata from a file
void extract_metadata(char *file_name) {

    // Open the file in read mode
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Unable to open file %s\n", file_name);
        return;
    }

    // Initialize a flag to indicate when we are reading metadata
    bool reading_metadata = true;

    // Initialize a counter for the number of metadata entries
    int num_metadata_entries = 0;

    // Initialize an array to hold the extracted metadata
    metadata_t *metadata_array = malloc(sizeof(metadata_t));

    // Initialize variables to hold the current metadata key-value pair
    char metadata_key[MAX_METADATA_LENGTH];
    char metadata_value[MAX_DATA_LENGTH];

    // Loop through the file, line by line
    char line[MAX_DATA_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // If we encounter the end of the metadata section, stop reading metadata
        if (strstr(line, "-->") != NULL) {
            reading_metadata = false;
        }

        // If we are reading metadata and the line contains a colon, assume it is a key-value pair
        else if (reading_metadata && strstr(line, ":") != NULL) {
            // Split the line into the key and value strings
            char *key = strtok(line, ":");
            char *value = strtok(NULL, ":");

            // Remove any leading or trailing white space from the key and value strings
            if (key != NULL) {
                strcpy(metadata_key, key);
                trim_whitespace(metadata_key);
                trim_whitespace(value);

                // Add the metadata key-value pair to the array
                strcpy(metadata_array[num_metadata_entries].key, metadata_key);
                strcpy(metadata_array[num_metadata_entries].value, metadata_value);
                num_metadata_entries++;

                // Expand the size of the metadata array if necessary
                if (num_metadata_entries % 10 == 0) {
                    metadata_array = realloc(metadata_array, (num_metadata_entries+10)*sizeof(metadata_t));
                }
            }
        }
    }

    // Print out the extracted metadata
    printf("Extracted metadata for file %s:\n", file_name);
    for (int i = 0; i < num_metadata_entries; i++) {
        printf("Key: %s, Value: %s\n", metadata_array[i].key, metadata_array[i].value);
    }

    // Close the file and free memory
    fclose(file);
    free(metadata_array);
}

// Define the function to remove any leading or trailing white space from a string
void trim_whitespace(char *str) {
    char *end;

    // Trim leading white space
    while (isspace(*str)) {
        str++;
    }

    // Trim trailing white space
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }

    // Terminate the trimmed string
    *(end+1) = '\0';
}

// Define the main function to call the metadata extraction function
int main() {
    extract_metadata("example_file.txt");
    return 0;
}