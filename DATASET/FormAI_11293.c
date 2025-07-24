//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdint.h>

struct Metadata {
    uint32_t fileSize;
    uint32_t numEntries;
    char author[30];
};

void extractMetadata(const char* filename, struct Metadata* data) {
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    // Read file size
    fseek(file, 0L, SEEK_END);
    data->fileSize = ftell(file);
    rewind(file);

    // Read number of entries
    fread(&data->numEntries, sizeof(uint32_t), 1, file);

    // Read author name
    fread(&data->author, sizeof(char), 30, file);

    fclose(file);
}

int main() {
    struct Metadata data;
    extractMetadata("file.bin", &data);

    printf("File size: %d bytes\n", data.fileSize);
    printf("Number of entries: %d\n", data.numEntries);
    printf("Author: %s\n", data.author);

    return 0;
}