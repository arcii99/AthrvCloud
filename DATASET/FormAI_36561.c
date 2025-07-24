//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate the size of a directory
long long get_directory_size(char *path) {

    long long total_size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    struct dirent *entry;
    struct stat info;

    while ((entry = readdir(dir)) != NULL) {

        char *child_path = (char*) malloc(sizeof(char) * (strlen(path) + strlen(entry->d_name) + 2));
        sprintf(child_path, "%s/%s", path, entry->d_name);

        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {

            if (stat(child_path, &info) == 0) {
                if (S_ISDIR(info.st_mode)) {
                    total_size += get_directory_size(child_path);
                } else {
                    total_size += info.st_size;
                }
            }
        }
        free(child_path);
    }
    closedir(dir);
    return total_size;
}

// Function to convert bytes to human readable format
void format_size(long long size, char *result) {
    if (size < 1024) {
        sprintf(result, "%lld B", size);
    } else if (size < 1024 * 1024) {
        sprintf(result, "%lld KB", size / 1024);
    } else if (size < 1024 * 1024 * 1024) {
        sprintf(result, "%lld MB", size / (1024 * 1024));
    } else {
        sprintf(result, "%lld GB", size / (1024 * 1024 * 1024));
    }
}

int main() {

    long long total_size = get_directory_size(".");
    if (total_size == -1) {
        printf("Error: Could not open directory.\n");
        return 1;
    }

    char *formatted_size = (char*) malloc(sizeof(char) * 20);
    format_size(total_size, formatted_size);

    printf("Total size of current directory: %s\n", formatted_size);

    free(formatted_size);
    return 0;
}