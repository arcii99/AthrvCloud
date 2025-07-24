//FormAI DATASET v1.0 Category: System administration ; Style: mathematical
/* A program to calculate disk space usage on a Linux system */
#include <stdio.h>
#include <sys/statvfs.h>

// Function to convert bytes to GB
double to_gb(unsigned long long bytes) {
    return (double) bytes / 1000000000.0;
}

int main() {
    char path[100];
    printf("Enter the path of the directory to check disk usage: ");
    scanf("%s", path);

    struct statvfs stat;

    // Getting disk space information
    if (statvfs(path, &stat) != 0) {
        printf("Error: Unable to access disk information.\n");
        return 1;
    }

    double total_space = to_gb(stat.f_frsize * stat.f_blocks);
    double free_space = to_gb(stat.f_frsize * stat.f_bfree);
    double used_space = total_space - free_space;
    double used_percentage = (used_space / total_space) * 100;

    printf("Disk Space Usage for %s\n", path);
    printf("Total space: %.2lfGB\n", total_space);
    printf("Used space: %.2lfGB (%.2lf%%)\n", used_space, used_percentage);
    printf("Free space: %.2lfGB\n", free_space);

    return 0;
}