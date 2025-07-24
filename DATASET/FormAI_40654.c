//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// function to extract metadata from file
void extractMetadata(char* file_path) {
    FILE* file = fopen(file_path, "r");

    // check if file exists
    if (file == NULL) {
        printf("Error: file not found.\n");
        return;
    }

    // read file metadata
    char name[50];
    int size;
    char date_modified[20];
    fread(name, sizeof(name), 1, file);
    fread(&size, sizeof(size), 1, file);
    fread(date_modified, sizeof(date_modified), 1, file);

    // print metadata
    printf("File Name: %s\n", name);
    printf("File Size: %d bytes\n", size);
    printf("Date Modified: %s\n", date_modified);

    // close file
    fclose(file);
}

int main() {
    printf("Welcome to the Metadata Extractor!\n");
    printf("Please enter the path to the file you wish to extract metadata from: ");
    
    char file_path[100];
    scanf("%s", file_path);
    
    extractMetadata(file_path);
    
    return 0;
}