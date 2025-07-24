//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024

int calculate_directory_size(const char* path);

int main(int argc, const char** argv) {
    if(argc != 2) {
        printf("usage: cdiskanalyzer <path>\n");
        return 1;
    }

    int size = calculate_directory_size(argv[1]);
    if(size < 0) {
        printf("error: could not calculate directory size\n");
        return 1;
    }

    printf("%d bytes\n", size);

    return 0;
}

int calculate_directory_size(const char* path) {
    DIR* directory = opendir(path);
    if(directory == NULL) {
        printf("error: could not open directory %s\n", path);
        return -1;
    }

    int total_size = 0;
    struct dirent* dirent;
    while((dirent = readdir(directory))) {
        if(strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        char child_path[MAX_PATH_LENGTH] = "";
        strcat(child_path, path);
        strcat(child_path, "/");
        strcat(child_path, dirent->d_name);

        if(dirent->d_type == DT_DIR) {
            total_size += calculate_directory_size(child_path);
        } else if(dirent->d_type == DT_REG) {
            FILE* file = fopen(child_path, "r");
            if(file == NULL) {
                printf("error: could not open file %s\n", child_path);
                return -1;
            }

            fseek(file, 0L, SEEK_END);
            total_size += ftell(file);

            fclose(file);
        }
    }

    closedir(directory);

    return total_size;
}