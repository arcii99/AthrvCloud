//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function to sync files
void sync_files(char* source_directory, char* dest_directory) {
    DIR* source = opendir(source_directory);
    if (source == NULL) {
        printf("Error: Could not open source directory\n");
        return;
    }
    DIR* dest = opendir(dest_directory);
    if (dest == NULL) {
        printf("Error: Could not open destination directory\n");
        return;
    }
    
    // loop through source directory
    struct dirent* item;
    while ((item = readdir(source)) != NULL) {
        if (strcmp(item->d_name, ".") == 0 || strcmp(item->d_name, "..") == 0) {
            continue; // ignore special directories
        }
        char* source_path = malloc(strlen(source_directory) + strlen(item->d_name) + 2);
        sprintf(source_path, "%s/%s", source_directory, item->d_name);
        struct stat source_stat;
        stat(source_path, &source_stat);
        
        if (S_ISREG(source_stat.st_mode)) {
            // if it's a regular file, copy it to the destination
            char* dest_path = malloc(strlen(dest_directory) + strlen(item->d_name) + 2);
            sprintf(dest_path, "%s/%s", dest_directory, item->d_name);
            FILE* source_file = fopen(source_path, "r");
            FILE* dest_file = fopen(dest_path, "w");
            if (source_file == NULL || dest_file == NULL) {
                printf("Error: Could not open file %s\n", item->d_name);
                continue;
            }
            char buffer[4096];
            size_t nread;
            while ((nread = fread(buffer, 1, sizeof buffer, source_file)) > 0) {
                fwrite(buffer, 1, nread, dest_file);
            }
            fclose(source_file);
            fclose(dest_file);
            free(dest_path);
        } else if (S_ISDIR(source_stat.st_mode)) {
            // if it's a directory, recursively sync its contents
            char* dest_path = malloc(strlen(dest_directory) + strlen(item->d_name) + 2);
            sprintf(dest_path, "%s/%s", dest_directory, item->d_name);
            mkdir(dest_path, source_stat.st_mode);
            sync_files(source_path, dest_path);
            free(dest_path);
        } else {
            printf("Warning: Skipping file %s (not a regular file or directory)\n", item->d_name);
        }
        
        free(source_path);
    }
    
    closedir(source);
    closedir(dest);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <dest_directory>\n", argv[0]);
        return 1;
    }
    sync_files(argv[1], argv[2]);
    return 0;
}