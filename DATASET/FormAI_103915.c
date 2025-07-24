//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 512
#define MAX_METADATA_SIZE 32

typedef struct metadata {
    char name[MAX_METADATA_SIZE];
    char value[MAX_METADATA_SIZE];
} Metadata;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    Metadata metadata[MAX_LINE_SIZE];
    int num_metadata = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    printf("Metadata in file: %s\n", argv[1]);

    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        if (line[0] == '#') {
            char *name = strtok(line, "=");
            char *value = strtok(NULL, "=");
            strcpy(metadata[num_metadata].name, name+2);
            strcpy(metadata[num_metadata].value, value);
            num_metadata++;
        }
    }

    fclose(file);

    for (int i = 0; i < num_metadata; i++) {
        printf("%s=%s\n", metadata[i].name, metadata[i].value);
    }

    return 0;
}