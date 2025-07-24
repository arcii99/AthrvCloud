//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate total size of a directory
long long calculate_size(char *dir) {
    DIR *dp = opendir(dir);
    struct dirent *entry;
    struct stat statbuf;
    long long total = 0;
    
    while((entry = readdir(dp)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            // Skip current and parent directory
            continue;
        }
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);
        if(lstat(path, &statbuf) == -1) {
            perror("lstat error");
            exit(EXIT_FAILURE);
        }
        if(S_ISDIR(statbuf.st_mode)) {
            total += calculate_size(path); // Recursively traverse directory
        } else {
            total += statbuf.st_size; // Add size of file
        }
    }
    closedir(dp);
    return total;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *dir = argv[1];
    long long total_size = calculate_size(dir);
    printf("Total size of \"%s\" directory: %lld bytes (%.2f GB)\n", dir, total_size, (double)total_size / (1024 * 1024 * 1024));
    return 0;
}