//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>

int main() {
    struct statvfs buf;

    if (statvfs(".", &buf) != 0) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    long block_size = buf.f_bsize;
    long total_blocks = buf.f_blocks;
    long free_blocks = buf.f_bfree;
    long used_blocks = total_blocks - free_blocks;
    float total_space = block_size * total_blocks / (1024.0 * 1024.0);
    float free_space = block_size * free_blocks / (1024.0 * 1024.0);
    float used_space = block_size * used_blocks / (1024.0 * 1024.0);
    float used_percentage = (used_space / total_space) * 100;

    printf("Disk space analysis...\n");
    printf("Total space: %.2f MB\n", total_space);
    printf("Free space: %.2f MB\n", free_space);
    printf("Used space: %.2f MB (%.2f%%)\n", used_space, used_percentage);

    return 0;
}