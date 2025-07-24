//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileInfo {
    char* filename;
    char* type;
    long size_in_bytes;
    char* creation_time;
};

void extract_metadata(struct FileInfo* file_info) {
    // simulate retrieving metadata
    printf("Extracting metadata for %s...\n", file_info->filename);
    file_info->type = "JPEG";
    file_info->size_in_bytes = 1024;
    file_info->creation_time = "2022-01-01 12:00:00";
    printf("Metadata extracted successfully!\n");
}

void print_file_info(struct FileInfo file_info) {
    printf("\nFile information:\n");
    printf("Name: %s\n", file_info.filename);
    printf("Type: %s\n", file_info.type);
    printf("Size (in bytes): %ld\n", file_info.size_in_bytes);
    printf("Creation time: %s\n", file_info.creation_time);
}

int main() {
    char* filename = "example.jpg";

    struct FileInfo file_info;
    file_info.filename = filename;

    extract_metadata(&file_info);
    print_file_info(file_info);

    return 0;
}