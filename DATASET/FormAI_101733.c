//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Function to calculate disk space recursively
long long calculateDiskSpace(char *path) {
    struct dirent *de; // Pointer for directory entry
    struct stat st; // Struct for file stats
    DIR *dir = opendir(path); // opendir() returns a pointer of DIR type.

    if (dir == NULL) { // opendir returns NULL if couldn't open directory
        printf("Unable to open directory %s\n", path);
        return 0;
    }

    long long totalSize = 0;
    while ((de = readdir(dir)) != NULL) {
        char currentFile[1000];
        strcpy(currentFile, path);
        strcat(currentFile, "/");
        strcat(currentFile, de->d_name);
        // Make sure we don't process parent and current directory links
        if (strcmp(de->d_name, "..") == 0 || strcmp(de->d_name, ".") == 0) {
            continue;
        }
        if (stat(currentFile, &st) == -1) {
            printf("Unable to get file stats for %s\n", currentFile);
            continue;
        }
        if (S_ISDIR(st.st_mode)) {
            totalSize += calculateDiskSpace(currentFile);
        } else {
            totalSize += st.st_size;
        }
    }
    closedir(dir);
    return totalSize;
}

// Main function to parse arguments and call disk space calculator
int main(int argc, char *argv[]) {
    char *path = argv[1];
    printf("Calculating disk space usage for %s...\n", path);
    long long diskSpace = calculateDiskSpace(path);
    printf("Total disk space usage: %lld bytes\n", diskSpace);
    return 0;
}