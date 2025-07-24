//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1000

int main(void) {
    char metadata[MAX_METADATA_SIZE] = "Title: A Unique Metadata Extractor Example\n"
                                        "Author: John Doe\n"
                                        "Date: 2021-06-01\n"
                                        "Description: This program extracts metadata from a file.\n"
                                        "License: MIT License\n";

    char *title;
    char *author;
    char *date;
    char *description;
    char *license;
    char *token;
    char *key;
    char *value;
    
    title = author = date = description = license = NULL;
    token = strtok(metadata, "\n");

    while (token != NULL) {
        key = strtok(token, ": ");
        value = strtok(NULL, "\n");
        
        if (strcmp(key, "Title") == 0) {
            title = value;
        } else if (strcmp(key, "Author") == 0) {
            author = value;
        } else if (strcmp(key, "Date") == 0) {
            date = value;
        } else if (strcmp(key, "Description") == 0) {
            description = value;
        } else if (strcmp(key, "License") == 0) {
            license = value;
        }
        
        token = strtok(NULL, "\n");
    }
    
    printf("Title: %s\n", title);
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);
    printf("Description: %s\n", description);
    printf("License: %s\n", license);

    return 0;
}