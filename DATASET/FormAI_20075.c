//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void extractMetadata(char *fileName) {
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }
    char metadata[50];
    int metadataIndex = 0;
    char currentChar = fgetc(fp);
    while (currentChar != EOF) {
        if (currentChar == '<') {
            currentChar = fgetc(fp);
            if (currentChar == '!') {
                currentChar = fgetc(fp);
                if (currentChar == '-') {
                    currentChar = fgetc(fp);
                    if (currentChar == '-') {
                        // This is a comment, skip it
                        continue;
                    }
                }
            }
        } else if (currentChar == '/') {
            currentChar = fgetc(fp);
            if (currentChar == '>') {
                metadataIndex--;
                if (metadataIndex < 0) {
                    printf("Parsing error: Invalid metadata syntax.");
                    fclose(fp);
                    return;
                }
            } else {
                metadata[metadataIndex] = currentChar;
                metadataIndex++;
            }
        } else if (currentChar == '>') {
            metadata[metadataIndex] = '\0';
            printf("%s\n", metadata);
            metadataIndex = 0;
        } else if (currentChar == ' ') {
            // Do nothing
        } else {
            metadata[metadataIndex] = currentChar;
            metadataIndex++;
        }
        currentChar = fgetc(fp);
    }
    fclose(fp);
}

int main() {
    extractMetadata("index.html");
    return 0;
}