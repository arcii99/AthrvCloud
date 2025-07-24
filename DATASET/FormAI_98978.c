//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isSeparator(char c) {
    // Determine if a character is a separator
    return (c == ' ' || c == '\n' || c == '\t');
}

void extractMetadata(char* data) {
    // Extract metadata from a string

    // Variables
    char key[MAX_SIZE], value[MAX_SIZE];
    bool readingKey = true, inQuotes = false;
    int i, j, k = 0;

    // Loop through the string
    for (i = 0; i < strlen(data); i++) {
        char c = data[i];

        // If a separator is found, toggle the reading key boolean
        if (isSeparator(c) && !inQuotes) {
            readingKey = !readingKey;
            k = 0;
            continue;
        }

        // If a quote is found, toggle the in quotes boolean
        if (c == '\"') {
            inQuotes = !inQuotes;
            continue;
        }

        // Add the current character to either the key or the value
        if (readingKey) {
            key[k++] = c;
        } else {
            value[k++] = c;
        }
    }

    // Null-terminate the strings
    key[k] = '\0';
    value[k] = '\0';

    // Print the key-value pair
    printf("Metadata: %s=%s\n", key, value);
}

int main() {
    // Example usage

    char data[MAX_SIZE];

    // Prompt the user for input
    printf("Enter a string with metadata: ");
    fgets(data, MAX_SIZE, stdin);

    // Extract metadata from the input string
    extractMetadata(data);

    return 0;
}