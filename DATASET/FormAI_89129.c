//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    int number_of_lines;
    int number_of_characters;
} Metadata;

Metadata extract_metadata(char *file_name) {
    FILE *file = fopen(file_name, "r");
    char line[MAX_FILE_NAME_LENGTH];
    Metadata metadata;

    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    metadata.number_of_lines = 0;
    metadata.number_of_characters = 0;

    while (fgets(line, MAX_FILE_NAME_LENGTH, file)) {
        metadata.number_of_lines++;
        metadata.number_of_characters += strlen(line);
    }

    fclose(file);
    return metadata;
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    Metadata metadata;

    printf("Enter file name: ");
    scanf("%s", file_name);

    metadata = extract_metadata(file_name);

    printf("Number of lines: %d\n", metadata.number_of_lines);
    printf("Number of characters: %d\n", metadata.number_of_characters);

    return 0;
}