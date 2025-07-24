//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* file_name;
    int file_size;
    char* last_modified;
} file_metadata;

typedef struct {
    char* directory_name;
    file_metadata* files;
    int num_files;
} directory_metadata;

directory_metadata* extract_metadata(char* path) {
    // create directory_metadata struct and initialize values
    directory_metadata* dir_meta = (directory_metadata*) malloc(sizeof(directory_metadata));
    dir_meta->directory_name = (char*) malloc(strlen(path) + 1);
    strcpy(dir_meta->directory_name, path);
    dir_meta->files = NULL;
    dir_meta->num_files = 0;
    
    // dummy code to simulate extracting files and metadata
    int num_files = 5;
    file_metadata* files = (file_metadata*) malloc(sizeof(file_metadata) * num_files);
    for (int i = 0; i < num_files; i++) {
        files[i].file_name = (char*) malloc(10);
        sprintf(files[i].file_name, "file_%d", i);
        files[i].file_size = rand() % 100 + 1; // random file size between 1 and 100 bytes
        files[i].last_modified = (char*) malloc(20);
        sprintf(files[i].last_modified, "20220101-%d", rand() % 10000); // random last modified date
    }
    
    // assign extracted metadata to directory_metadata struct
    dir_meta->files = files;
    dir_meta->num_files = num_files;
    
    return dir_meta;
}

void print_metadata(directory_metadata* dir_meta) {
    printf("Directory: %s\n", dir_meta->directory_name);
    printf("Number of files: %d\n", dir_meta->num_files);
    for (int i = 0; i < dir_meta->num_files; i++) {
        printf("File Name: %s\n", dir_meta->files[i].file_name);
        printf("File Size: %d bytes\n", dir_meta->files[i].file_size);
        printf("Last Modified: %s\n", dir_meta->files[i].last_modified);
        printf("\n");
    }
}

int main() {
    char* path = "/Users/user/documents/";
    directory_metadata* dir_meta = extract_metadata(path);
    print_metadata(dir_meta);
    return 0;
}