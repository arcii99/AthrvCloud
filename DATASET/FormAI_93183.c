//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_LEN 100

int main() {
    char metadata[MAX_METADATA_LEN];
    char* ptr;
    char* name;
    char* value;
    char* delimiter = "=";

    printf("Enter metadata (name=value format): ");
    fgets(metadata, MAX_METADATA_LEN, stdin);

    //Remove newline character
    metadata[strcspn(metadata, "\n")] = 0;

    //Split metadata into name and value
    ptr = strtok(metadata, delimiter);
    name = ptr;
    ptr = strtok(NULL, delimiter);
    value = ptr;

    //Print extracted metadata
    printf("Metadata name: %s\n", name);
    printf("Metadata value: %s\n", value);

    return 0;
}