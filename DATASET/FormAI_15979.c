//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
// Ada Lovelace Style C Metadata Extractor

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct metadata {
    char field[50];
    char value[100];
};

void extract_metadata(FILE* file) {
    char line[200];
    int count = 0;
    struct metadata metadata[50];

    while (fgets(line, sizeof(line), file)) {
        char* field = strtok(line, ":");
        char* value = strtok(NULL, "\n");

        strcpy(metadata[count].field, field);
        strcpy(metadata[count].value, value);
        count++;
    }

    printf("Metadata:\n");

    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", metadata[i].field, metadata[i].value);
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");

    if (file != NULL) {
        extract_metadata(file);
        fclose(file);
    } else {
        printf("Unable to open file.");
    }
    
    return 0;
}