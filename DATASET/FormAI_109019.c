//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define METADATA_SIZE 4096

typedef struct FileInfo {
    char filename[128];
    int size;
    char* metadata;
} FileInfo;

void extractMetadata(char* filename, char* metadata) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // find metadata start position
    char line[256];
    int metadataStartPos = -1;
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "-----BEGIN METADATA-----\n") == 0) {
            metadataStartPos = ftell(file);
            break;
        }
    }
    if (metadataStartPos == -1) {
        printf("Metadata not found in file %s\n", filename);
        return;
    }

    // find metadata end position
    int metadataEndPos = -1;
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "-----END METADATA-----\n") == 0) {
            metadataEndPos = ftell(file) - strlen(line);
            break;
        }
    }
    if (metadataEndPos == -1) {
        printf("Metadata not properly formatted in file %s\n", filename);
        return;
    }

    // extract metadata
    fseek(file, metadataStartPos, SEEK_SET);
    int metadataSize = metadataEndPos - metadataStartPos;
    fgets(metadata, metadataSize, file);

    fclose(file);
}

void printFileInfo(FileInfo fileInfo) {
    printf("Filename: %s\n", fileInfo.filename);
    printf("Size: %d\n", fileInfo.size);
    printf("Metadata: %s\n", fileInfo.metadata);
    printf("\n");
}

int main() {
    FileInfo fileInfo1;
    strcpy(fileInfo1.filename, "file1.txt");
    fileInfo1.size = 100;

    fileInfo1.metadata = malloc(METADATA_SIZE * sizeof(char));
    extractMetadata(fileInfo1.filename, fileInfo1.metadata);

    FileInfo fileInfo2;
    strcpy(fileInfo2.filename, "file2.pdf");
    fileInfo2.size = 200;

    fileInfo2.metadata = malloc(METADATA_SIZE * sizeof(char));
    extractMetadata(fileInfo2.filename, fileInfo2.metadata);

    printFileInfo(fileInfo1);
    printFileInfo(fileInfo2);

    free(fileInfo1.metadata);
    free(fileInfo2.metadata);

    return 0;
}