//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char *title;
    char *author;
    char *description;
    int year;
} Metadata;

Metadata *parse_metadata(char *filename) {
    FILE *fp;
    char buff[255];
    Metadata *meta = malloc(sizeof(Metadata));
    meta->title = NULL;
    meta->author = NULL;
    meta->description = NULL;
    meta->year = 0;
    
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }
    
    while (!feof(fp)) {
        fgets(buff, 255, fp);
        if (strncmp(buff, "Title:", 6) == 0) {
            meta->title = malloc(sizeof(char) * (strlen(buff) - 7));
            strncpy(meta->title, &buff[7], strlen(buff) - 8);
        } else if (strncmp(buff, "Author:", 7) == 0) {
            meta->author = malloc(sizeof(char) * (strlen(buff) - 8));
            strncpy(meta->author, &buff[8], strlen(buff) - 9);
        } else if (strncmp(buff, "Description:", 12) == 0) {
            meta->description = malloc(sizeof(char) * (strlen(buff) - 13));
            strncpy(meta->description, &buff[13], strlen(buff) - 14);
        } else if (strncmp(buff, "Year:", 5) == 0) {
            meta->year = atoi(&buff[6]);
        }
    }
    
    fclose(fp);
    return meta;
}

int main() {
    Metadata *book = parse_metadata("book.txt");
    if(book != NULL) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Description: %s\n", book->description);
        printf("Year: %d\n", book->year);
    }
    return 0;
}