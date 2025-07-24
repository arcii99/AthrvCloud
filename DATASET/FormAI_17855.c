//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/statfs.h>

#define GB_SIZE (1024 * 1024 * 1024) // 1 GB in bytes
#define MB_SIZE (1024 * 1024) // 1 MB in bytes
#define KB_SIZE (1024) // 1 KB in bytes

int main()
{
    struct statfs disk_info;
    long long int total_disk_space, free_disk_space, used_disk_space;

    if (statfs("C:", &disk_info) == -1)
    {
        printf("Error getting C: drive space information.\n");
        return 0;
    }

    total_disk_space = ((long long int)disk_info.f_blocks * (long long int)disk_info.f_bsize);
    free_disk_space = ((long long int)disk_info.f_bfree * (long long int)disk_info.f_bsize);
    used_disk_space = total_disk_space - free_disk_space;

    printf("\nC: Drive Space Information:\n");
    printf("----------------------------\n");
    printf("Total Disk Space: %.2f GB\n", (float)total_disk_space / GB_SIZE);
    printf("Used Disk Space: %.2f GB\n", (float)used_disk_space / GB_SIZE);
    printf("Free Disk Space: %.2f GB\n", (float)free_disk_space / GB_SIZE);

    if (used_disk_space >= 80 * GB_SIZE)
    {
        printf("\nWARNING: Your C: drive usage has exceeded 80%%\n");
    }
    else if (used_disk_space >= 70 * GB_SIZE)
    {
        printf("\nCAUTION: Your C: drive usage has exceeded 70%%\n");
    }

    return 0;
}