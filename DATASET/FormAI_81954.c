//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to get size of directory
long long get_directory_size(const char *path) {
    struct dirent *direntp = NULL;
    struct stat statbuf;
    DIR *dirp = NULL;
    long long total = 0;

    dirp = opendir(path);

    while ((direntp = readdir(dirp)) != NULL) {
        char *sub_path = NULL;
        asprintf(&sub_path, "%s/%s", path, direntp->d_name);

        if (strcmp(direntp->d_name, ".") == 0 || strcmp(direntp->d_name, "..") == 0) {
            free(sub_path);
            continue;
        }

        if (stat(sub_path, &statbuf) == 0) {
            total += statbuf.st_size;
        }

        free(sub_path);
    }

    closedir(dirp);
    return total;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s directory_name\n", argv[0]);
        return 1;
    }

    long long total_size = get_directory_size(argv[1]);

    printf("Total size of directory %s: %.2f GB\n", argv[1], (double)total_size / (1024 * 1024 * 1024));

    return 0;
}