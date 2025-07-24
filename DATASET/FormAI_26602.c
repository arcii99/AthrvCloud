//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* value;
} Metadata;

int main() {
    char data[] = "name: Alice\nage: 25\naddress: 1234 Main St.";
    char* pairs[3];
    Metadata metadata[3];

    // Split the data into pairs (name: value)
    pairs[0] = strtok(data, "\n");
    for (int i = 1; i < 3; i++) {
        pairs[i] = strtok(NULL, "\n");
    }

    // Split the pairs into name and value and store in Metadata structs
    for (int i = 0; i < 3; i++) {
        char* name = strtok(pairs[i], ":");
        char* value = strtok(NULL, "");
        metadata[i].name = malloc(strlen(name) + 1);
        metadata[i].value = malloc(strlen(value) + 1);
        strcpy(metadata[i].name, name);
        strcpy(metadata[i].value, value);
    }

    // Print out the extracted metadata
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < 3; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }

    return 0;
}