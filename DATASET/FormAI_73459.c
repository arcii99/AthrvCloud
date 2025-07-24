//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to hold metadata information
struct Metadata {
    char key[20];
    char value[50];
};

// Function to extract metadata from string
struct Metadata extract_metadata(char *str) {
    struct Metadata metadata;
    int i = 0, j = 0;
    bool is_key = true;

    // Loop through each character in string
    while (str[i] != '\0') {
        // Check if current character is an '='
        if (str[i] == '=') {
            metadata.key[j] = '\0';
            is_key = false;
            j = 0;
        } else if (str[i] == ';') {
            metadata.value[j] = '\0';
            break;
        } else {
            if (is_key) {
                metadata.key[j] = str[i];
            } else {
                metadata.value[j] = str[i];
            }
            j++;
        }
        i++;
    }

    return metadata;
}

int main() {
    char str[] = "author=John Doe;title=Sample Book;year=2021;";
    struct Metadata metadata;

    // Loop through string to extract metadata
    int i = 0;
    while (str[i] != '\0') {
        metadata = extract_metadata(&str[i]);
        printf("%s: %s\n", metadata.key, metadata.value);
        i += strlen(metadata.key) + strlen(metadata.value) + 2;  // '2' is for '=' and ';' characters
    }

    return 0;
}