//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the metadata string
#define MAX_LEN 100

// Function to extract metadata from a given string
char* extract_metadata(char* str) {
    
    // Define variables for storing metadata and tokens
    char* metadata = malloc(MAX_LEN);
    char* token;
    char* delimiter = ":";

    // Get the first token
    token = strtok(str, delimiter);

    // Traverse through the string and extract the metadata
    while (token != NULL) {

        // If the token contains "metadata", store it as the metadata
        if (strstr(token, "metadata")) {
            strcpy(metadata, token);
            break;
        }
        
        // Get the next token
        token = strtok(NULL, delimiter);
    }
    
    // Return the extracted metadata
    return metadata;
}

int main() {

    // Define a sample string containing metadata
    char sample_string[] = "title:Sample Title,artist:Sample Artist,metadata:123456";

    // Extract the metadata from the sample string
    char* metadata = extract_metadata(sample_string);

    // Print the extracted metadata
    printf("Extracted metadata: %s\n", metadata);

    // Free the memory allocated for the metadata string
    free(metadata);
    
    return 0;
}