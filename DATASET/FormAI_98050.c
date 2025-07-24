//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc != 2 || strcmp(argv[1], "-h") == 0) {
        printf("Usage: %s <dir>\n", argv[0]);
        printf("  <dir>       directory to analyze disk space usage\n");
        return 0;
    }
    char* dir_path = argv[1];

    // Get directory file size
    struct stat dir_stat;
    if (stat(dir_path, &dir_stat) < 0) {
        perror("Error getting directory stat");
        return 1;
    }
    off_t dir_size = dir_stat.st_size;

    // Open directory
    DIR* dir = opendir(dir_path);
    if (!dir) {
        perror("Error opening directory");
        return 1;
    }

    // Iterate through directory contents
    struct dirent* dir_entry;
    while ((dir_entry = readdir(dir)) != NULL) {
        // Skip "." and ".." directories
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
            continue;

        // Get subpath of directory entry
        char subpath[1024];
        snprintf(subpath, sizeof(subpath), "%s/%s", dir_path, dir_entry->d_name);

        // Get file/directory metadata
        struct stat subpath_stat;
        if (lstat(subpath, &subpath_stat) < 0) {
            perror("Error getting subpath stat");
            return 1;
        }

        // Check if subpath is a directory
        if (S_ISDIR(subpath_stat.st_mode)) {
            // Recursively analyze subdirectory
            char* subpath_argv[2] = {argv[0], subpath};
            pid_t subpath_pid = fork();
            if (subpath_pid == 0) {
                execv(argv[0], subpath_argv);
                perror("Error executing subpath program");
                return 1;
            } else if (subpath_pid < 0) {
                perror("Error forking subpath process");
                return 1;
            }
            int subpath_status;
            waitpid(subpath_pid, &subpath_status, 0);

            // Accumulate subdirectory size
            if (!WIFEXITED(subpath_status)) {
                printf("Error analyzing subdirectory %s\n", subpath);
                continue;
            }
            dir_size += WEXITSTATUS(subpath_status);
        } else {
            // Accumulate file size
            dir_size += subpath_stat.st_size;
        }
    }

    // Print directory size
    printf("%-10ld %s\n", dir_size, dir_path);

    // Clean up
    closedir(dir);
    return dir_size;
}