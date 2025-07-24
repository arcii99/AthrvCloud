//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void calculateDiskUsage(char *path, int depth, long *diskUsage);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];
    long diskUsage = 0;
    calculateDiskUsage(path, 0, &diskUsage);
    printf("Total disk usage of \"%s\": %ld bytes\n", path, diskUsage);

    exit(EXIT_SUCCESS);
}

void calculateDiskUsage(char *path, int depth, long *diskUsage) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    if ((dir = opendir(path)) == NULL) { // couldn't open directory
        return;
    }

    chdir(path);
    while ((entry = readdir(dir)) != NULL) {
        // get information about file/directory
        stat(entry->d_name, &info);

        if (entry->d_type == DT_DIR) { // current entry is a directory
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            // recursively call the function for the subdirectory
            calculateDiskUsage(entry->d_name, depth + 1, diskUsage);
        } else {
            *diskUsage += info.st_size; // add size of file to diskUsage
        }
    }
    chdir("..");
    closedir(dir);
}