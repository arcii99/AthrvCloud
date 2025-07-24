//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

typedef struct {
    char author[MAX_LEN];
    char title[MAX_LEN];
    char date[MAX_LEN];
    char version[MAX_LEN];
} Metadata;

void extract_metadata(const char* filename, Metadata* metadata) {
    // Open file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file \"%s\".\n", filename);
        exit(1);
    }

    // Extract metadata
    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, fp)) {
        if (strncmp(line, "Author:", 7) == 0) {
            strcpy(metadata->author, line + 8);
            metadata->author[strcspn(metadata->author, "\r\n")] = '\0';
        } else if (strncmp(line, "Title:", 6) == 0) {
            strcpy(metadata->title, line + 7);
            metadata->title[strcspn(metadata->title, "\r\n")] = '\0';
        } else if (strncmp(line, "Date:", 5) == 0) {
            strcpy(metadata->date, line + 6);
            metadata->date[strcspn(metadata->date, "\r\n")] = '\0';
        } else if (strncmp(line, "Version:", 8) == 0) {
            strcpy(metadata->version, line + 9);
            metadata->version[strcspn(metadata->version, "\r\n")] = '\0';
        }
    }

    // Close file
    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(1);
    }

    // Extract metadata
    Metadata metadata = {0};
    extract_metadata(argv[1], &metadata);

    // Print metadata
    printf("Author:  %s\n", metadata.author);
    printf("Title:   %s\n", metadata.title);
    printf("Date:    %s\n", metadata.date);
    printf("Version: %s\n", metadata.version);

    return 0;
}