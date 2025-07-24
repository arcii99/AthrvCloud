//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs vfs;
    char* file_system_path = "/";
    if (statvfs(file_system_path, &vfs) == -1) {
        printf("Could not get file system information\n");
        exit(EXIT_FAILURE);
    }
    unsigned long long total_space = vfs.f_frsize * vfs.f_blocks;
    unsigned long long used_space = vfs.f_frsize * (vfs.f_blocks - vfs.f_bfree);
    unsigned long long free_space = vfs.f_frsize * vfs.f_bfree;

    printf("Welcome to the Disk Space Analyzer!\n");
    printf("----------------------------------\n\n");
    printf("Total Space: %.2lf GB\n", (double)total_space / 1000000000);
    printf("Used Space: %.2lf GB (%.2lf%%)\n", (double)used_space / 1000000000, (double)used_space / total_space * 100);
    printf("Free Space: %.2lf GB (%.2lf%%)\n\n", (double)free_space / 1000000000, (double)free_space / total_space * 100);

    if ((double)used_space / total_space >= 0.9) {
        printf("Warning: Disk almost full!\n");
    } else {
        printf("Everything seems to be in order.\n");
    }
    return 0;
}