//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_directory(char* directory_path, long* total_size);

void main() {
    char* starting_directory = "/";

    long total_size = 0;

    analyze_directory(starting_directory, &total_size);

    printf("Total disk space used: %ld bytes\n", total_size);
}

void analyze_directory(char* directory_path, long* total_size) {
    DIR* directory = opendir(directory_path);

    if (directory) {
        struct dirent* directory_entry;

        while ((directory_entry = readdir(directory)) != NULL) {
            if (strcmp(directory_entry->d_name, ".") == 0 || strcmp(directory_entry->d_name, "..") == 0) {
                continue;
            }

            char entity_path[256];
            sprintf(entity_path, "%s/%s", directory_path, directory_entry->d_name);

            struct stat entity_stats;
            if (stat(entity_path, &entity_stats) != -1) {
                if (S_ISDIR(entity_stats.st_mode)) {
                    analyze_directory(entity_path, total_size);
                } else {
                     *total_size += entity_stats.st_size;
                }
            }
        }

        closedir(directory);
    }
}