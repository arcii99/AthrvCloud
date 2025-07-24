//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <dirent.h>
#include <sys/statvfs.h>

int main() {
    DIR *dir;
    struct dirent *ent;
    struct statvfs fsstat;
    long long total_space = 0, used_space = 0;

    if ((dir = opendir("/")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            char path[1024];
            snprintf(path, sizeof(path), "/%s", ent->d_name);
            if (statvfs(path, &fsstat) == -1) {
                printf("Error: Cannot get file system statistics for %s\n", path);
                continue;
            }

            long long block_size = fsstat.f_frsize;
            long long total_blocks = fsstat.f_blocks;
            long long free_blocks = fsstat.f_bfree;
            long long used_blocks = total_blocks - free_blocks;

            long long total_size = total_blocks * block_size;
            long long used_size = used_blocks * block_size;

            total_space += total_size;
            used_space += used_size;
        }
        closedir(dir);
    } else {
        printf("Error: Cannot open root directory\n");
        return -1;
    }

    double used_percentage = (used_space * 100.0) / total_space;
    double free_percentage = 100.0 - used_percentage;

    printf("Total space: %lld bytes\n", total_space);
    printf("Used space: %lld bytes (%.2lf%%)\n", used_space, used_percentage);
    printf("Free space: %lld bytes (%.2lf%%)\n", total_space - used_space, free_percentage);

    return 0;
}