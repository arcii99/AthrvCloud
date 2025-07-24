//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void analyzeDir(const char *dir_path, long long *total_size) {
    struct dirent *entry = NULL;
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyzeDir(path, total_size);
        } else if (S_ISREG(statbuf.st_mode)) {
            *total_size += statbuf.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return -1;
    }

    const char *dir_path = argv[1];
    long long total_size = 0;
    
    analyzeDir(dir_path, &total_size);

    printf("Total size of files in %s: %lld bytes\n", dir_path, total_size);

    return 0;
}