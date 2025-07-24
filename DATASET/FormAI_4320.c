//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

void
analyze_disk_space(const char *path)
{
    struct statvfs stats;
    if (statvfs(path, &stats) < 0) {
        printf("Could not analyze space for %s\n", path);
        return;
    }

    printf("Disk usage statistics for %s:\n", path);
    printf("Block size: %ld bytes\n", stats.f_bsize);
    printf("Total blocks: %ld\n", stats.f_blocks);
    printf("Free blocks: %ld\n", stats.f_bfree);
    
    double total_size = (double)stats.f_bsize * stats.f_blocks;
    double free_size = (double)stats.f_bsize * stats.f_bfree;
    double used_size = total_size - free_size;
    double percent_used = used_size / total_size * 100.0;

    printf("\nSummary:\n");
    printf("Total disk space: %.2lf MB\n", total_size / (1024.0 * 1024.0));
    printf("Free disk space: %.2lf MB\n", free_size / (1024.0 * 1024.0));
    printf("Used disk space: %.2lf MB\n", used_size / (1024.0 * 1024.0));
    printf("Percent used: %.2lf%%\n", percent_used);
}

int
main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);
    return 0;
}