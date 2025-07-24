//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/statvfs.h>

#define BLOCK_SIZE 512 //bytes

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: disk_analyzer <path>\n");
        exit(EXIT_FAILURE);
    }

    const char *path = argv[1];

    struct statvfs stat;
    if (statvfs(path, &stat) != 0) {
        perror("Failed to stat file system");
        exit(EXIT_FAILURE);
    }

    long fs_block_size = stat.f_frsize;
    long total_blocks = stat.f_blocks;
    long free_blocks = stat.f_bfree;
    long avail_blocks = stat.f_bavail;

    printf("File system block size: %ld bytes (%ld blocks of %d bytes each)\n", fs_block_size, total_blocks, BLOCK_SIZE);
    printf("Total disk space: %ld bytes (%ld KB)\n", total_blocks * fs_block_size, total_blocks * fs_block_size / 1024);
    printf("Free disk space: %ld bytes (%ld KB)\n", free_blocks * fs_block_size, free_blocks * fs_block_size / 1024);
    printf("Available disk space: %ld bytes (%ld KB)\n", avail_blocks * fs_block_size, avail_blocks * fs_block_size / 1024);

    double used_percent = 100.0 * (total_blocks - free_blocks) / total_blocks;
    printf("Used disk space: %.2f%%\n", used_percent);

    return 0;
}