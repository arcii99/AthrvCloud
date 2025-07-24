//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_directory(const char* path, const long long int min_size) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Cannot open directory %s\n", path);
        return;
    }
    
    char next_path[1024];
    struct dirent* ent;
    struct stat st;
    long long int total_size = 0;
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        snprintf(next_path, sizeof(next_path), "%s/%s", path, ent->d_name);
        if (lstat(next_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                analyze_directory(next_path, min_size);
            } else if (S_ISREG(st.st_mode)) {
                if ((long long int)st.st_size >= min_size) {
                    printf("%lld %s\n", (long long int)st.st_size, next_path);
                    total_size += (long long int)st.st_size;
                }
            }
        }
    }
    printf("%lld %s\n", total_size, path);
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: disk_analyzer starting_folder min_file_size\n");
        return 1;
    }
    const char* starting_folder = argv[1];
    const long long int min_size = atoll(argv[2]);
    analyze_directory(starting_folder, min_size);
    return 0;
}