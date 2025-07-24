//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the maximum length of metadata
#define MAX_METADATA_LENGTH 100

// Struct for storing metadata
typedef struct {
    int key;
    char value[MAX_METADATA_LENGTH];
} Metadata;

int main() {
    // Define the input string and metadata array
    char input[] = "Hello world! [key1: value1][key2: value2][key3: value3]";
    Metadata metadata[3];

    // Define variables for parsing the input string
    int input_length = strlen(input);
    char current_char;
    int current_index = 0;
    int current_metadata_index = 0;
    char current_metadata_key[MAX_METADATA_LENGTH];
    char current_metadata_value[MAX_METADATA_LENGTH];

    // Loop through the input string
    for (int i = 0; i < input_length; i++) {
        current_char = input[i];

        // If the current character is "[", start parsing metadata
        if (current_char == '[') {
            // Reset variables for parsing metadata
            current_index = 0;
            memset(current_metadata_key, 0, sizeof(current_metadata_key));
            memset(current_metadata_value, 0, sizeof(current_metadata_value));
        }

        // If the current character is ":", set the current key
        else if (current_char == ':') {
            metadata[current_metadata_index].key = atoi(current_metadata_key);
            current_index = 0;
        }

        // If the current character is "]", set the current value and move to the next metadata item
        else if (current_char == ']') {
            strcpy(metadata[current_metadata_index].value, current_metadata_value);
            current_metadata_index++;
            current_index = 0;
        }

        // Otherwise, add the current character to the current key or value
        else {
            if (current_index < MAX_METADATA_LENGTH) {
                if (current_metadata_index % 2 == 0) current_metadata_key[current_index] = current_char;
                else current_metadata_value[current_index] = current_char;

                current_index++;
            }
        }
    }

    // Print out the extracted metadata
    for (int i = 0; i < 3; i++) {
        printf("Metadata[%d]: key=%d, value=%s\n", i, metadata[i].key, metadata[i].value);
    }

    return 0;
}