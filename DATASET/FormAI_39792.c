//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_dir(char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent* de;
    while ((de = readdir(dir)) != NULL) {
        if (de->d_name[0] == '.') {
            continue; // skip hidden files/folders
        }
        char fullpath[PATH_MAX];
        sprintf(fullpath, "%s/%s", path, de->d_name);
        struct stat st;
        if (stat(fullpath, &st) != 0) {
            perror("stat");
            continue;
        }
        if (S_ISDIR(st.st_mode)) {
            printf("%s/ \t%ld\n", fullpath, st.st_size);
            analyze_dir(fullpath);
        } else {
            printf("%s \t%ld\n", fullpath, st.st_size);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }
    analyze_dir(argv[1]);
    return 0;
}