//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
    char author[100];
    char title[100];
    char date[20];
    char keywords[200];
};

void extractMetadata(char *filename, struct Metadata *metadata) {
    // Actual metadata extraction code would be here, but for brevity 
    // let's just set some dummy values
    strcpy(metadata->author, "John Smith");
    strcpy(metadata->title, "The Adventures of Sherlock Holmes");
    strcpy(metadata->date, "1892");
    strcpy(metadata->keywords, "detective, mystery, crime");
}

void printMetadata(struct Metadata metadata) {
    printf("Author: %s\n", metadata.author);
    printf("Title: %s\n", metadata.title);
    printf("Date: %s\n", metadata.date);
    printf("Keywords: %s\n", metadata.keywords);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    
    struct Metadata metadata;
    extractMetadata(argv[1], &metadata);
    printf("Metadata for file %s:\n", argv[1]);
    printMetadata(metadata);
    
    return 0;
}