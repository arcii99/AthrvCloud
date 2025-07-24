//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_disk_space(char* path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat file_stat;
    char new_path[1024];

    int total_size = 0;

    while ((entry = readdir(dir)) != NULL) {
        strcpy(new_path, path);
        strcat(new_path, "/");
        strcat(new_path, entry->d_name);

        if (strcmp(entry->d_name, ".") !=0 && strcmp(entry->d_name, "..") != 0) {
            if (stat(new_path, &file_stat) == 0) {
                if (S_ISDIR(file_stat.st_mode)) {
                    analyze_disk_space(new_path);
                } else {
                    total_size += (int)file_stat.st_size;
                }
            }
        }
    }

    printf("Total size of %s: %d bytes\n", path, total_size);

    closedir(dir);
}

int main() {
    printf("--- Welcome to Disk Space Analyzer ---\n");
    printf("Enter the path to analyze: ");
    char path[1024];
    scanf("%s", path);

    analyze_disk_space(path);

    return 0;
}