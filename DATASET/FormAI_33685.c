//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

void print_space_details(char *path) {
    struct statvfs buf;
    if (statvfs(path, &buf) != 0) {
        perror("Error while accessing file system status: ");
        exit(EXIT_FAILURE);
    }
    printf("Total Space: %lu\n", (unsigned long)buf.f_blocks * buf.f_frsize);
    printf("Free Space: %lu\n", (unsigned long)buf.f_bfree * buf.f_frsize);
    printf("Available Space: %lu\n", (unsigned long)buf.f_bavail * buf.f_frsize);
}

// Main Function
int main(int argc, char* argv[]) {
    char *disk_path = "/";
    // Accept disk path as command line argument
    if (argc > 1)
        disk_path = argv[1];
    printf("Details for %s:\n", disk_path);
    print_space_details(disk_path);
    return 0;
}