//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the metadata keys and values
#define MAX_SIZE 100

// Function for extracting the metadata from a string
void extractMetadata(char* str) {

    // Initialize an empty dictionary to store the metadata
    char metadata[MAX_SIZE][MAX_SIZE];
    int num_keys = 0;

    int i = 0;
    while (str[i] != '\0') {

        // If a metadata key is found, extract the key and value
        if (str[i] == '<' && str[i+1] != '/') {
            char key[MAX_SIZE];
            int j = 0;
            while (str[i+1] != '>') {
                key[j] = str[i+1];
                i++;
                j++;
            }
            key[j] = '\0';

            i++;
            char value[MAX_SIZE];
            j = 0;
            while (str[i] != '<') {
                value[j] = str[i];
                i++;
                j++;
            }
            value[j] = '\0';

            // Add the metadata to the dictionary
            strcpy(metadata[num_keys], key);
            strcat(metadata[num_keys], ": ");
            strcat(metadata[num_keys], value);
            num_keys++;

        // If a metadata key is being closed, skip over it
        } else if (str[i] == '<' && str[i+1] == '/') {
            while (str[i+1] != '>') {
                i++;
            }
        }

        // Move on to the next character in the string
        i++;
    }

    // Print out the extracted metadata
    printf("Metadata Extracted:\n");
    for (int k=0; k<num_keys; k++) {
        printf("%s\n", metadata[k]);
    }
}

int main() {
    char example_string[] = "<title>Jane Eyre</title><author>Charlotte Bronte</author>";
    extractMetadata(example_string);
    return 0;
}