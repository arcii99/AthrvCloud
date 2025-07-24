//FormAI DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void print_usage() {
    printf("Usage: ./my_sysadmin_program [-d directory_path]\n");
}

int main(int argc, char *argv[]) {
    // Default path to be used
    char *dir_path = "/var/log";

    // Parse command line arguments
    int opt;
    while ((opt = getopt(argc, argv, "d:")) != -1) {
        switch (opt) {
            case 'd':
                dir_path = optarg;
                break;
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }

    // Open directory and check if it exists
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Error: %s does not exist\n", dir_path);
        exit(EXIT_FAILURE);
    }

    struct dirent *dir_entry;
    while ((dir_entry = readdir(dir)) != NULL) {
        // Exclude hidden files/directories
        if (dir_entry->d_name[0] == '.') {
            continue;
        }

        char current_path[100];
        snprintf(current_path, sizeof current_path, "%s/%s", dir_path, dir_entry->d_name);

        // Check if current entry is a directory
        struct stat file_stat;
        if (stat(current_path, &file_stat) == -1) {
            printf("Error: Unable to get file status for: %s\n", current_path);
            continue;
        }
        if (S_ISDIR(file_stat.st_mode)) {
            printf("Directory: %s\n", current_path);

            // Print contents of directory
            DIR *current_dir = opendir(current_path);
            if (current_dir == NULL) {
                printf("Error: Could not open directory: %s\n", current_path);
                continue;
            }

            struct dirent *current_entry;
            while ((current_entry = readdir(current_dir)) != NULL) {
                // Exclude hidden files/directories
                if (current_entry->d_name[0] == '.') {
                    continue;
                }

                printf("  %s\n", current_entry->d_name);
            }
            closedir(current_dir);
        } else {
            printf("File: %s\n", current_path);
        }
    }
    closedir(dir);

    return EXIT_SUCCESS;
}