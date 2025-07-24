//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 256
#define MAX_DIRS 1024

typedef struct {
    char path[MAX_PATH];
    size_t size;
} dir_info_t;

int get_dir_size(const char *path, dir_info_t *info);
void print_dir_tree(dir_info_t *dirs, int count);
void print_size(size_t size);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dir_info_t dirs[MAX_DIRS];
    memset(dirs, 0, sizeof(dir_info_t) * MAX_DIRS);
    int count = get_dir_size(argv[1], dirs);

    if (count > 0) {
        print_dir_tree(dirs, count);
    } else {
        printf("No directories found in %s\n", argv[1]);
    }

    return 0;
}

int get_dir_size(const char *path, dir_info_t *info) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    int count = 0;

    if (dir == NULL) {
        fprintf(stderr, "Cannot open directory %s\n", path);
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Ignore . and .. directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char subpath[MAX_PATH];
            snprintf(subpath, MAX_PATH, "%s/%s", path, entry->d_name);
            size_t size = 0;
            int subdir_count = get_dir_size(subpath, info + count);

            if (subdir_count > 0) {
                for (int i = 0; i < subdir_count; i++) {
                    size += (info + count + i)->size;
                }
            }

            struct stat st;
            if (stat(subpath, &st) >= 0) {
                size += st.st_size;
            }

            strncpy((info + count)->path, subpath, MAX_PATH - 1);
            (info + count)->size = size;
            count += subdir_count + 1;

            if (count >= MAX_DIRS) {
                break;
            }
        }
    }

    closedir(dir);

    return count;
}

void print_dir_tree(dir_info_t *dirs, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s", dirs[i].path);
        print_size(dirs[i].size);
        printf("\n");
    }
}

void print_size(size_t size) {
    if (size >= (1ULL << 30)) {
        printf("\t%.2f GiB", (double)size / (1ULL << 30));
    } else if (size >= (1ULL << 20)) {
        printf("\t%.2f MiB", (double)size / (1ULL << 20));
    } else if (size >= (1ULL << 10)) {
        printf("\t%.2f KiB", (double)size / (1ULL << 10));
    } else {
        printf("\t%zu B", size);
    }
}