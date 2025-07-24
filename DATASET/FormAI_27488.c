//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Alan Touring
#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char metadata[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    fseek(file, 0, SEEK_SET);
    fread(metadata, 100, 1, file);
    printf("Metadata extracted from file %s: %s\n", filename, metadata);
    fclose(file);
    return 0;
}