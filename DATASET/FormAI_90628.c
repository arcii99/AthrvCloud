//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
    char name[100];
    char type[50];
    char value[256];
};

void extractMetadata(char *str, struct Metadata *metadata);
void printMetadata(struct Metadata *metadata);

int main() {
    char str[] = "Name: John\nType: Student\nAge: 20\nGPA: 3.5\n";
    
    // Split the string by newlines and extract metadata
    char *tokens[4];
    tokens[0] = strtok(str, "\n");
    for (int i = 1; i < 4; i++) {
        tokens[i] = strtok(NULL, "\n");
    }
    
    struct Metadata metadata[3];
    for (int i = 0; i < 3; i++) {
        extractMetadata(tokens[i], &metadata[i]);
    }
    
    // Print the extracted metadata
    for (int i = 0; i < 3; i++) {
        printMetadata(&metadata[i]);
    }
    
    return 0;
}

// Extracts metadata from a given string
void extractMetadata(char *str, struct Metadata *metadata) {
    char *token = strtok(str, ": ");
    strcpy(metadata->name, token);
    
    token = strtok(NULL, ": ");
    strcpy(metadata->type, token);
    
    token = strtok(NULL, ": ");
    strcpy(metadata->value, token);
}

// Prints the metadata
void printMetadata(struct Metadata *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Type: %s\n", metadata->type);
    printf("Value: %s\n", metadata->value);
}