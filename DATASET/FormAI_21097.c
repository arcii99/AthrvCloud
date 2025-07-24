//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
#include <stdio.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs stat;
    char dir[100];

    printf("Enter a directory path: ");
    scanf("%s", dir);

    if(statvfs(dir, &stat) != 0) {
        printf("Error: Unable to get file system statistics.\n");
        return 1;
    }

    unsigned long long total = (unsigned long long)stat.f_blocks * stat.f_frsize;
    unsigned long long free = (unsigned long long)stat.f_bfree * stat.f_frsize;
    unsigned long long used = total - free;
    double percent_free = ((double)free / total) * 100;
    double percent_used = ((double)used / total) * 100;

    printf("Total space: %.2f GB\n", (double)total / (1024 * 1024 * 1024));
    printf("Free space: %.2f GB (%.2f%%)\n", (double)free / (1024 * 1024 * 1024), percent_free);
    printf("Used space: %.2f GB (%.2f%%)\n", (double)used / (1024 * 1024 * 1024), percent_used);

    return 0;
}