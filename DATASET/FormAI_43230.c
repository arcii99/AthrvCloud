//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_SIZE 100000

struct file_metadata {
    char filename[MAX_SIZE];
    size_t filesize;
    char created_on[MAX_SIZE];
    char last_modified[MAX_SIZE];
};

void get_metadata(struct file_metadata *metadata, const char *filename) {
    struct stat filestat;
    if (stat(filename, &filestat) == -1) {
        printf("Error: file not found.\n");
        exit(1);
    }

    strncpy(metadata->filename, filename, MAX_SIZE);
    metadata->filesize = filestat.st_size;

    strftime(metadata->created_on, MAX_SIZE, "%Y-%m-%d %H:%M:%S", localtime(&filestat.st_ctime));
    strftime(metadata->last_modified, MAX_SIZE, "%Y-%m-%d %H:%M:%S", localtime(&filestat.st_mtime));
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: Usage: ./metadata_extractor [filename]\n");
        return 1;
    }

    struct file_metadata metadata;
    get_metadata(&metadata, argv[1]);

    printf("File: %s\n", metadata.filename);
    printf("Size: %lu bytes\n", metadata.filesize);
    printf("Created on: %s\n", metadata.created_on);
    printf("Last modified: %s\n", metadata.last_modified);

    return 0;
}