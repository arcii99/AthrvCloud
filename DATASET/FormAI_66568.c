//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory path>\n", argv[0]);
        exit(1);
    }
    
    char *path = argv[1];
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat info;
    
    if (dir == NULL) {
        printf("Unable to open directory: %s\n", path);
        exit(1);
    }
    
    printf("Files in directory: %s\n", path);
    
    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof full_path, "%s/%s", path, entry->d_name);
        if (stat(full_path, &info) != 0) {
            printf("Unable to get info for file: %s\n", full_path);
            continue;
        }
        
        if (S_ISREG(info.st_mode)) {
            printf("Regular file: %s, size: %ld\n", entry->d_name, info.st_size);
        } else if (S_ISDIR(info.st_mode)) {
            printf("Directory: %s\n", entry->d_name);
        } else {
            printf("Unknown filetype: %s\n", entry->d_name);
        }
    }
    
    closedir(dir);
    
    return 0;
}