//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: brave
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

unsigned long long int total_size = 0;  // Declare a variable to hold the total size

void getSize(char *path) {  // Function to calculate the size of files and directories
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat info;

    while ((entry = readdir(dir)) != NULL) {
        char subpath[256];
        snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (lstat(subpath, &info) == 0) {
            if (S_ISDIR(info.st_mode)) {
                getSize(subpath);
            }
            else {
                total_size += info.st_size;
            }
        }
    }

    closedir(dir);
}

int main() {
    char path[256];
    printf("Enter the path to analyze: ");
    scanf("%s", path);

    getSize(path);
    
    printf("Total disk space used by %s: %llu bytes\n", path, total_size);
    
    return 0;
}