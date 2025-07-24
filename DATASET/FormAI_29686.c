//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// function to extract metadata
void extractMetadata(char *file_name, char *metadata) {
    // read file line by line
    FILE *fp;
    char line[100];
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        strcpy(metadata, "Error: Could not open file");
        return;
    }
    // loop through lines until metadata is found
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "METADATA")) {
            strcpy(metadata, line);
            break;
        }
    }
    fclose(fp);
    if (!strstr(metadata, "METADATA")) {
        strcpy(metadata, "Error: No metadata found in file");
    }
}

int main() {
    // initialize variables
    char file_name[100];
    char metadata[100];
    // get file name from user
    printf("Enter file name: ");
    scanf("%s", file_name);
    // extract metadata
    extractMetadata(file_name, metadata);
    // display metadata
    printf("Metadata found in file: %s\n", metadata);
    return 0;
}