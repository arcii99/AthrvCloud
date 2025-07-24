//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs vfs;

    if (statvfs("/", &vfs) == -1) {
        fprintf(stderr, "Error: could not stat the file system.\n");
        return EXIT_FAILURE;
    }

    long long block_size = vfs.f_frsize;
    long long total_size = block_size * vfs.f_blocks;
    long long available_size = block_size * vfs.f_bfree;
    long long used_size = total_size - available_size;

    printf("Total Disk Space: %lld bytes\n", total_size);
    printf("Used Disk Space: %lld bytes\n", used_size);
    printf("Available Disk Space: %lld bytes\n", available_size);

    return EXIT_SUCCESS;
}