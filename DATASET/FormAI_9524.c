//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <sys/statvfs.h>

void print_disk_space_info() {
    struct statvfs stat;
    if (statvfs("/", &stat) == -1) {
        perror("statvfs error");
        return;
    }

    unsigned long long total_space = stat.f_frsize * stat.f_blocks;
    unsigned long long free_space = stat.f_frsize * stat.f_bfree;
    unsigned long long used_space = total_space - free_space;

    int percentage_used_space = (int) ((double) used_space / (double) total_space * 100);

    printf("Disk space usage information:\n");
    printf("Total space: %lld bytes\n", total_space);
    printf("Used space: %lld bytes (%d%%)\n", used_space, percentage_used_space);
    printf("Free space: %lld bytes\n", free_space);
}

int main() {
    print_disk_space_info();
    return 0;
}