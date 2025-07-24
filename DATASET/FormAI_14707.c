//FormAI DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    FILE *sourceFile;
    FILE *destFile;
    char sourceFilePath[MAX_SIZE];
    char destFilePath[MAX_SIZE];
    char tempBuffer[MAX_SIZE];
    size_t readBytes;

    printf("Enter the path of the source file: ");
    scanf("%s", sourceFilePath);

    printf("Enter the path of the destination file: ");
    scanf("%s", destFilePath);

    sourceFile = fopen(sourceFilePath, "rb");
    if (sourceFile == NULL) {
        printf("ERROR: Could not open source file\n");
        return 1;
    }

    destFile = fopen(destFilePath, "wb");
    if (destFile == NULL) {
        printf("ERROR: Could not open destination file\n");
        return 1;
    }

    printf("Copying data...\n");

    while ((readBytes = fread(tempBuffer, 1, sizeof(tempBuffer), sourceFile)) > 0) {
        fwrite(tempBuffer, 1, readBytes, destFile);
    }

    printf("Data copied successfully.\n");

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}