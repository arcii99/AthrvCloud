//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct Metadata {
    char* name;
    int size;
} Metadata;

void extractMetadata(const char* filename, Metadata* metadata) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: cannot open file\n");
        return;
    }
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    char* buffer = malloc(size);
    if (buffer == NULL) {
        printf("Error: memory allocation failed\n");
        fclose(fp);
        return;
    }
    rewind(fp);
    fread(buffer, sizeof(char), size, fp);
    fclose(fp);
    metadata->name = filename;
    metadata->size = size;
    free(buffer);
}

int main() {
    Metadata metadata;
    extractMetadata("example.mp3", &metadata);
    printf("Name: %s | Size: %d bytes\n", metadata.name, metadata.size);
    return 0;
}