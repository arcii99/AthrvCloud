//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: accurate
// C Disk Space Analyzer
// By [Your Name Here]

#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs stat;

    if (statvfs("/", &stat) < 0) {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }

    long block_size = stat.f_frsize;
    long total_blocks = stat.f_blocks;
    long free_blocks = stat.f_bfree;
    long available_blocks = stat.f_bavail;

    long total_space = block_size * total_blocks;
    long free_space = block_size * free_blocks;
    long available_space = block_size * available_blocks;

    printf("Disk Space Analysis for /:\n");
    printf("Total Space: %ld bytes\n", total_space);
    printf("Free Space: %ld bytes\n", free_space);
    printf("Available Space: %ld bytes\n", available_space);
    printf("Used Space: %ld bytes\n", total_space - free_space);
    printf("Used Percentage: %.2f%%\n", ((double)(total_space - free_space) / total_space) * 100);

    return 0;
}