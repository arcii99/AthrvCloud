//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

void print_usage(double total, double used, double free) {
    printf("Total disk space: %0.2f GB\n", total / (1024*1024*1024));
    printf("Disk space used: %0.2f GB\n", used / (1024*1024*1024));
    printf("Disk space free: %0.2f GB\n", free / (1024*1024*1024));
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return -1;
    }

    const char* path = argv[1];
    struct statvfs vfs;
    if (statvfs(path, &vfs) != 0) {
        fprintf(stderr, "Unable to get disk usage for %s. Are you sure it exists?\n", path);
        return -1;
    }

    double block_size = vfs.f_frsize;
    double total_blocks = vfs.f_blocks;
    double free_blocks = vfs.f_bfree;
    double used_blocks = total_blocks - free_blocks;
    double total_space = total_blocks * block_size;
    double free_space = free_blocks * block_size;
    double used_space = used_blocks * block_size;

    print_usage(total_space, used_space, free_space);

    return 0;
}