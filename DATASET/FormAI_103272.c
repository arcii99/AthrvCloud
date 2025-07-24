//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

void analyzeDiskSpace(const char* path) {
    struct statvfs fs_stats;
    int err;

    err = statvfs(path, &fs_stats);
    if (err != 0) {
        fprintf(stderr, "Error in statvfs: %s\n", strerror(err));
        return;
    }

    printf("Disk space analysis for path '%s':\n", path);
    printf("Block size: %lu\n", fs_stats.f_bsize);
    printf("Total blocks: %lu\n", fs_stats.f_blocks);
    printf("Free blocks: %lu\n", fs_stats.f_bfree);
    printf("Available blocks: %lu\n", fs_stats.f_bavail);
    printf("Total space: %lu bytes\n", fs_stats.f_blocks * fs_stats.f_bsize);
    printf("Free space: %lu bytes\n", fs_stats.f_bfree * fs_stats.f_bsize);
    printf("Available space: %lu bytes\n", fs_stats.f_bavail * fs_stats.f_bsize);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path-to-analyze>\n", argv[0]);
        return 1;
    }

    analyzeDiskSpace(argv[1]);

    return 0;
}