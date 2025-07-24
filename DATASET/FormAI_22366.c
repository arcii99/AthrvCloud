//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int analyze_dir(char *dir_path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    analyze_dir(argv[1]);
    return 0;
}

int analyze_dir(char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        printf("Error: Could not open directory %s\n", dir_path);
        return 1;
    }

    struct dirent *entry;
    char path[512];
    long long total_size = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            struct stat file_stat;
            if (stat(path, &file_stat) != -1) {
                printf("%lld kB\t%s\n", file_stat.st_size / 1024, path);
                total_size += file_stat.st_size;
            }
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            long long dir_size = analyze_dir(path);
            printf("%lld kB\t%s/\n", dir_size / 1024, path);
            total_size += dir_size;
        }
    }

    closedir(dir);

    printf("\nTotal size of %s: %lld kB\n", dir_path, total_size / 1024);
    return total_size;
}