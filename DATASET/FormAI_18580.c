//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define BLOCK_SIZE 4096

/* function to calculate the disk space used by a file or directory */
long long calculateDiskSpaceUsed(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            DIR *dir = opendir(path);
            if (dir == NULL) {
                fprintf(stderr, "Error: %s - %s\n", path, strerror(errno));
                return 0;
            }
            long long totalSize = 0;
            struct dirent *entry;
            char subPath[1024];
            while ((entry = readdir(dir)) != NULL) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    sprintf(subPath, "%s/%s", path, entry->d_name);
                    totalSize += calculateDiskSpaceUsed(subPath);
                }
            }
            closedir(dir);
            return totalSize;
        } else {
            return st.st_blocks * BLOCK_SIZE;
        }
    } else {
        fprintf(stderr, "Error: %s - %s\n", path, strerror(errno));
        return 0;
    }
}

/* main function */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    long long totalSize = calculateDiskSpaceUsed(argv[1]);
    printf("Disk space used by %s: %.2f MB\n", argv[1], (double)totalSize/(1024*1024));
    return EXIT_SUCCESS;
}