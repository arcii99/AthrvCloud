//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[])
{
    struct statvfs vfs;
    int block_size, total_blocks, free_blocks, percent_free;

    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(statvfs(argv[1], &vfs) == -1)
    {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }

    block_size = vfs.f_frsize;
    total_blocks = vfs.f_blocks;
    free_blocks = vfs.f_bfree;

    percent_free = ((double)free_blocks / (double)total_blocks) * 100;

    printf("Total space: %ld bytes\n", (long)(total_blocks * block_size));
    printf("Free space: %ld bytes\n", (long)(free_blocks * block_size));
    printf("Percentage free: %d%%\n", percent_free);

    return 0;
}