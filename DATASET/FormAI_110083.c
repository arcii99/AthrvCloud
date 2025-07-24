//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[50];
    char value[100];
} Metadata;

void extractMetadata(char *filename, Metadata **metadata, int *count) {
    FILE *fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file.");
        return;
    }

    char line[200];
    int index = 0;
    while(fgets(line, sizeof(line), fp) != NULL) {
        if(strncmp(line, "/*", 2) == 0 || strncmp(line, "//", 2) == 0) {
            Metadata *m = (Metadata *) malloc(sizeof(Metadata));
            if(strncmp(line, "/*", 2) == 0) {
                sscanf(line, "/* %49[^:]: %99[^\n]", m->key, m->value);
            } else {
                sscanf(line, "// %49[^:]: %99[^\n]", m->key, m->value);
            }
            metadata[index++] = m;
        }
    }

    fclose(fp);
    *count = index;
}

int main() {
    Metadata *metadata[50];
    int count = 0;

    extractMetadata("sample.c", metadata, &count);

    printf("Metadata count: %d\n", count);

    for(int i = 0; i < count; i++) {
        printf("Key: %s, Value: %s\n", metadata[i]->key, metadata[i]->value);
        free(metadata[i]);
    }

    return 0;
}