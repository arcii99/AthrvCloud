//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

// Define constants
#define MB 1048576
#define GB 1073741824

// Main function
int main() {

    // Declare variables
    struct statvfs stat;
    double total_space, free_space, used_space;
    char path[100];

    // Ask user for disk path
    printf("Enter disk path: ");
    scanf("%s", path);

    // Check if path is valid
    if (statvfs(path, &stat) == -1) {
        printf("Invalid path!\n");
        exit(1);
    }

    // Calculate disk space
    total_space = (double)stat.f_blocks * (double)stat.f_frsize / GB;
    free_space = (double)stat.f_bfree * (double)stat.f_frsize / GB;
    used_space = total_space - free_space;

    // Display results
    printf("\nTotal space: %.2lf GB\n", total_space);
    printf("Used space: %.2lf GB\n", used_space);
    printf("Free space: %.2lf GB\n\n", free_space);

    return 0;
}