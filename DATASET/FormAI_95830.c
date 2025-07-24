//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[]) {

    // Check for command line argument
    if (argc != 2) {
        printf("Invalid argument count! Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    // Check if directory exists
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error opening directory! Please make sure the directory exists.\n");
        exit(1);
    }

    // Traverse directory and calculate disk space usage
    struct dirent *entry;
    struct stat st;
    unsigned long long total_size = 0;
    while ((entry = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
        if (stat(path, &st) == 0) {
            total_size += st.st_size;
        }
    }

    // Output results
    printf("Total disk space used by %s: %llu bytes (%.2f GB)\n", argv[1], total_size, (float)total_size / (1024 * 1024 * 1024));

    // Close directory
    closedir(dir);

    return 0;
}