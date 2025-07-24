//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

/* This program analyzes the disk space used by the C drive */
int main()
{
    struct statvfs c_drive;
    if (statvfs("/", &c_drive) == 0)
    {
        unsigned long long block_size = c_drive.f_frsize; // Block size in bytes
        unsigned long long total_blocks = c_drive.f_blocks; // Total number of blocks
        unsigned long long free_blocks = c_drive.f_bfree; // Free blocks
        unsigned long long used_blocks = total_blocks - free_blocks; // Used blocks
        unsigned long long total_size = block_size * total_blocks; // Total size in bytes
        unsigned long long free_size = block_size * free_blocks; // Free size in bytes
        unsigned long long used_size = block_size * used_blocks; // Used size in bytes

        // Display the results to the user
        printf("Disk space analysis for the C drive:\n\n");
        printf("Total space: %llu bytes (%llu MB, %llu GB)\n", total_size, total_size / (1024 * 1024), total_size / (1024 * 1024 * 1024));
        printf("Free space: %llu bytes (%llu MB, %llu GB)\n", free_size, free_size / (1024 * 1024), free_size / (1024 * 1024 * 1024));
        printf("Used space: %llu bytes (%llu MB, %llu GB)\n", used_size, used_size / (1024 * 1024), used_size / (1024 * 1024 * 1024));
    }
    else
    {
        printf("Error: Unable to analyze the C drive.\n");
    }
    return 0;
}