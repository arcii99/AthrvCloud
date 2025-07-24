//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/statvfs.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s /path/to/directory\n", argv[0]);
        return 1;
    }

    struct statvfs fs_stats;
    if (statvfs(argv[1], &fs_stats) == -1) {
        printf("Unable to read filesystem stats for %s\n", argv[1]);
        return 1;
    }

    printf("Filesystem: %s\n", argv[1]);
    printf("Block size: %lu bytes\n", fs_stats.f_bsize);
    printf("Total blocks: %lu\n", fs_stats.f_blocks);
    printf("Free blocks: %lu\n", fs_stats.f_bfree);
    printf("Available blocks: %lu\n", fs_stats.f_bavail);
    printf("Total space: %lu bytes\n", fs_stats.f_blocks * fs_stats.f_bsize);
    printf("Free space: %lu bytes\n", fs_stats.f_bfree * fs_stats.f_bsize);
    printf("Available space: %lu bytes\n", fs_stats.f_bavail * fs_stats.f_bsize);

    return 0;
}