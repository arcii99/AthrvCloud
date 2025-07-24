//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct metadata {
    char title[100];
    char author[100];
    int year;
    char description[500];
} Metadata;

int main() {
    char metadataText[MAX_METADATA_SIZE]; // assuming metadata is less than 1024 bytes
    FILE *filePtr = fopen("book.txt", "r"); // open the file in read mode
    if (filePtr == NULL) {
        printf("Error opening the file.");
        return 1;
    }

    fgets(metadataText, MAX_METADATA_SIZE, filePtr); // read the first line from file
    fclose(filePtr); // close the file

    // parse the metadata to create a Metadata object
    Metadata bookMetadata;
    char* token = strtok(metadataText, "|"); // assuming metadata is separated by pipe
    int i = 0;
    while (token != NULL) {
        switch (i) {
            case 0: // title
                strcpy(bookMetadata.title, token);
                break;
            case 1: // author
                strcpy(bookMetadata.author, token);
                break;
            case 2: // year
                bookMetadata.year = atoi(token);
                break;
            case 3: // description
                strcpy(bookMetadata.description, token);
                break;
            default:
                break;
        }
        token = strtok(NULL, "|");
        i++;
    }

    // print the metadata values
    printf("Title: %s\n", bookMetadata.title);
    printf("Author: %s\n", bookMetadata.author);
    printf("Year: %d\n", bookMetadata.year);
    printf("Description: %s\n", bookMetadata.description);

    return 0;
}