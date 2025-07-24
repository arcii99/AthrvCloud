//FormAI DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source-file> <backup-file>\n", argv[0]);
        return 1;
    }

    FILE* sourceFile = fopen(argv[1], "rb");
    if (!sourceFile) {
        printf("Error: Unable to open source file '%s'.\n", argv[1]);
        return 1;
    }

    FILE* backupFile = fopen(argv[2], "wb");
    if (!backupFile) {
        printf("Error: Unable to open backup file '%s'.\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int readBytes = 0;
    while ((readBytes = fread(buffer, sizeof(char), BUFFER_SIZE, sourceFile))) {
        fwrite(buffer, sizeof(char), readBytes, backupFile);
        memset(buffer, 0, BUFFER_SIZE);
    }

    fclose(sourceFile);
    fclose(backupFile);

    printf("File '%s' backed up to '%s'.\n", argv[1], argv[2]);

    return 0;
}