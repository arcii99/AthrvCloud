//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_dir(char *path, int *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char filename[1024];

    dir = opendir(path);
    if (!dir) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;

        snprintf(filename, sizeof(filename), "%s/%s", path, entry->d_name);

        if (!stat(filename, &file_stat)) {
            if (S_ISDIR(file_stat.st_mode)) {
                analyze_dir(filename, total_size);
            } else {
                *total_size += (int) file_stat.st_size;
            }
        }
    }

    closedir(dir);
}

int main() {
    int total_size = 0;

    analyze_dir("C:", &total_size);

    printf("Total size of C drive: %d bytes\n", total_size);

    return 0;
}