//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>

int main(int argc, char *argv[]) {
    double total_space, free_space, used_space;
    struct statvfs buf;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    if (statvfs(argv[1], &buf) == -1) {
        fprintf(stderr, "Error: Unable to get disk space information.\n");
        exit(1);
    }

    total_space = (double)buf.f_frsize * (double)buf.f_blocks;
    free_space = (double)buf.f_frsize * (double)buf.f_bfree;
    used_space = total_space - free_space;

    printf("Total Space: %.2lf GB\n", (total_space / (1024 * 1024 * 1024)));
    printf("Free Space: %.2lf GB\n", (free_space / (1024 * 1024 * 1024)));
    printf("Used Space: %.2lf GB\n", (used_space / (1024 * 1024 * 1024)));

    return 0;
}