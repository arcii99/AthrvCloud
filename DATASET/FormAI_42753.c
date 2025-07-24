//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[]) {
    struct statvfs diskInfo;

    if (argc != 2) {
        printf("Please provide a directory path to analyze disk space usage.\n");
        return 1;
    }

    if (statvfs(argv[1], &diskInfo) == -1) {
        perror("Failed to get disk space usage information");
        return 1;
    }

    unsigned long long totalSpace = diskInfo.f_blocks * diskInfo.f_frsize;
    unsigned long long freeSpace = diskInfo.f_bfree * diskInfo.f_frsize;
    unsigned long long usedSpace = totalSpace - freeSpace;
    double usedPercentage = ((double)usedSpace / (double)totalSpace) * 100;

    printf("Disk space usage for directory %s\n", argv[1]);
    printf("Total space available: %llu bytes\n", totalSpace);
    printf("Used space: %llu bytes (%.2f%% of total)\n", usedSpace, usedPercentage);
    printf("Free space: %llu bytes\n", freeSpace);

    return 0;
}