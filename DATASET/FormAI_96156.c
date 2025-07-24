//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <drive>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct statvfs vfs;
    if (statvfs(argv[1], &vfs) == -1) {
        printf("Error: Unable to retrieve file system statistics\n");
        exit(EXIT_FAILURE);
    }

    unsigned long long total_space = (unsigned long long)vfs.f_frsize * vfs.f_blocks;
    unsigned long long free_space = (unsigned long long)vfs.f_frsize * vfs.f_bfree;
    unsigned long long used_space = total_space - free_space;

    printf("File system information for %s:\n", argv[1]);
    printf("Total space: %llu bytes\n", total_space);
    printf("Used space: %llu bytes\n", used_space);
    printf("Free space: %llu bytes\n", free_space);

    return 0;
}