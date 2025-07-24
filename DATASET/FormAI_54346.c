//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

// function to calculate disk usage in human readable format
void calculate_disk_usage(char* path) {
    struct statvfs vfs;
    if (statvfs(path, &vfs) < 0) {
        printf("Error: Could not calculate disk usage for %s\n", path);
        return;
    }

    unsigned long long blocks = vfs.f_blocks;
    unsigned long long bsize = vfs.f_frsize;
    unsigned long long disk_usage_bytes = (blocks * bsize);
    unsigned long long disk_usage_kb = (disk_usage_bytes / 1024);
    unsigned long long disk_usage_mb = (disk_usage_kb / 1024);
    unsigned long long disk_usage_gb = (disk_usage_mb / 1024);

    printf("Disk usage for %s:\n", path);
    printf("Total size: %llu GB\n", disk_usage_gb);
    printf("Total size: %llu MB\n", disk_usage_mb % 1024);
    printf("Total size: %llu KB\n", disk_usage_kb % 1024);
    printf("Total size: %llu Bytes\n", disk_usage_bytes % 1024);
}

int main() {
    char path[128];
    printf("Enter path to analyze: ");
    scanf("%s", path);

    calculate_disk_usage(path);
    
    return 0;
}