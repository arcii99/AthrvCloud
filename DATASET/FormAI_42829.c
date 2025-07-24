//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_LEVEL 50

struct Directory {
    char path[MAX_PATH];
    long long size;
    struct Directory *subdirs;
    int num_subdirs;
};

int compare_size_desc(const void *a, const void *b) {
    const struct Directory *dir_a = *(const struct Directory **)a;
    const struct Directory *dir_b = *(const struct Directory **)b;
    return dir_b->size - dir_a->size;
}

void print_usage() {
    printf("Usage: disk-analyzer [path]\n");
    printf("Analyzes disk space usage and displays results in descending order.\n");
    printf("If [path] is not specified, uses current directory.\n");
}

void scan_directory(const char *path, struct Directory *dir, int level) {
    DIR *dp;
    struct dirent *entry;
    struct stat stat_buf;
    char fullpath[MAX_PATH];
    if ((dp = opendir(path)) == NULL) {
        fprintf(stderr, "Cannot open directory %s\n", path);
        return;
    }
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(fullpath, MAX_PATH, "%s/%s", path, entry->d_name);
        if (lstat(fullpath, &stat_buf) != 0) {
            perror(fullpath);
            continue;
        }
        if (S_ISDIR(stat_buf.st_mode)) {
            if (level < MAX_LEVEL) {
                struct Directory *subdir = &dir->subdirs[dir->num_subdirs++];
                strcpy(subdir->path, fullpath);
                subdir->size = 0;
                subdir->num_subdirs = 0;
                subdir->subdirs = calloc(MAX_LEVEL, sizeof(struct Directory));
                scan_directory(fullpath, subdir, level+1);
            }
        } else if (S_ISREG(stat_buf.st_mode)) {
            dir->size += stat_buf.st_size;
        } else {
            // not a regular file or directory, do nothing
        }
    }
    closedir(dp);
}

void print_result(struct Directory *dir) {
    printf("%lld %s\n", dir->size, dir->path);
    if (dir->num_subdirs > 0) {
        qsort(dir->subdirs, dir->num_subdirs, sizeof(struct Directory), compare_size_desc);
        for (int i = 0; i < dir->num_subdirs; i++) {
            print_result(&dir->subdirs[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    char *path;
    if (argc == 1) {
        path = ".";
    } else if (argc == 2) {
        path = argv[1];
    } else {
        print_usage();
        return 1;
    }
    struct Directory root = { .path = {0}, .size = 0, .num_subdirs = 0 };
    root.subdirs = calloc(MAX_LEVEL, sizeof(struct Directory));
    if (realpath(path, root.path) == NULL) {
        perror(path);
        return 1;
    }
    scan_directory(root.path, &root, 0);
    print_result(&root);
    return 0;
}