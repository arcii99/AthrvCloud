//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

void analyze_disk_space(char *path) {
    DIR *dir;
    struct dirent *ent;
    struct stat fileStat;
    long long size = 0;

    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                char file_path[1024];
                snprintf(file_path, sizeof(file_path), "%s/%s", path, ent->d_name);
                if (stat(file_path, &fileStat) == 0) {
                    if (S_ISDIR(fileStat.st_mode)) {
                        analyze_disk_space(file_path);
                    } else {
                        size += fileStat.st_size;
                    }
                }
            }
        }
        closedir(dir);
        if (size > GB) {
            printf("%s : %.2f GB\n", path, (double)size / GB);
        } else if (size > MB) {
            printf("%s : %.2f MB\n", path, (double)size / MB);
        } else if (size > KB) {
            printf("%s : %.2f KB\n", path, (double)size / KB);
        } else {
            printf("%s : %lld bytes\n", path, size);
        }
    } else {
        printf("Error opening directory %s\n", path);
    }
}

int main() {
    analyze_disk_space(".");
    return 0;
}