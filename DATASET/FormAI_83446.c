//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_FILENAME 255

struct metadata {
    char title[255];
    char artist[255];
    int year;
};

void extract_metadata(char* filename, struct metadata* meta) {
    // logic to extract metadata from the file
    // ...
    
    // temporary hardcoded values for demonstration purposes
    strcpy(meta->title, "Enter Sandman");
    strcpy(meta->artist, "Metallica");
    meta->year = 1991;
}

int main() {
    char filename[MAX_SIZE_FILENAME];
    struct metadata* meta = malloc(sizeof(struct metadata));
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    extract_metadata(filename, meta);
    
    printf("Title: %s\n", meta->title);
    printf("Artist: %s\n", meta->artist);
    printf("Year: %d\n", meta->year);
    
    free(meta);
    return 0;
}