//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void print_usage() {
    printf("Usage: ./diskanalyzer <directory>\n");
}

int is_dot_dir(const char *name) {
    if (strncmp(name, ".", 1) == 0 || strncmp(name, "..", 2) == 0)
        return 1;
    return 0;
}

void print_entry(const char *path, long size) {
    char display_size[20];
    if (size < 1024)
        sprintf(display_size, "%ld B", size);
    else if (size < 1024 * 1024)
        sprintf(display_size, "%.2f KB", size / 1024.0);
    else if (size < 1024 * 1024 * 1024)
        sprintf(display_size, "%.2f MB", size / (1024.0 * 1024));
    else
        sprintf(display_size, "%.2f GB", size / (1024.0 * 1024 * 1024));
    printf("%-60s %20s\n", path, display_size);
}

long get_dir_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1)
        return -1;
    if (!S_ISDIR(statbuf.st_mode))
        return -1;

    long total_size = 0;
    DIR *dirp = opendir(path);
    if (!dirp)
        return -1;
    struct dirent *direntp;
    while ((direntp = readdir(dirp))) {
        if (is_dot_dir(direntp->d_name))
            continue;
        char new_path[512];
        sprintf(new_path, "%s/%s", path, direntp->d_name);
        long size;
        if (direntp->d_type == DT_DIR)
            size = get_dir_size(new_path);
        else // file
            size = statbuf.st_size;
        if (size == -1) {
            closedir(dirp);
            return -1;
        }
        total_size += size;
        print_entry(new_path, size);
    }
    closedir(dirp);
    return total_size;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }
    long total_size = get_dir_size(argv[1]);
    if (total_size == -1) {
        printf("Error while computing directory size.\n");
        return 1;
    }
    printf("Total size: %ld B\n", total_size);
    return 0;
}