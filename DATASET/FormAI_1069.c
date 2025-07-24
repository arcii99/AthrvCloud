//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define MAX_LEN 1024

void extract_metadata(const char* filename) {
    printf("Extracting metadata from file: %s\n", filename);
    /* code for metadata extraction goes here */
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    DIR* dir;
    struct dirent* ent;
    char file_path[MAX_LEN];
    dir = opendir(argv[1]);
    if(dir == NULL) {
        printf("Error opening directory: %s\n", argv[1]);
        return 1;
    }
    while((ent = readdir(dir)) != NULL) {
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        snprintf(file_path, MAX_LEN - 1, "%s/%s", argv[1], ent->d_name);
        extract_metadata(file_path);
    }
    closedir(dir);
    return 0;
}