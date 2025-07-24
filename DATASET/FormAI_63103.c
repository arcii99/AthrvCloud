//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

long long total_size = 0;

void analyze_directory(const char *path){
    DIR *dir = opendir(path);
    struct dirent *entry;
    char full_path[MAX_PATH];
    struct stat st;

    while((entry = readdir(dir)) != NULL) {
        if(entry->d_name[0] == '.')
            continue;
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);
        if(lstat(full_path, &st) == -1)
            continue;
        if(S_ISDIR(st.st_mode)) {
            analyze_directory(full_path);
        } else {
            total_size += st.st_size;
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        exit(0);
    }
    analyze_directory(argv[1]);
    printf("Total disk usage: %lld bytes\n", total_size);
    return 0;
}