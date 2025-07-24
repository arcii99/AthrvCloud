//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char** argv) {
    DIR* dirp;
    struct dirent* dp;
    struct stat buf;
    char path[1024];
    int total_size = 0;

    if(argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if((dirp = opendir(argv[1])) == NULL) {
        printf("Error: Couldn't open directory %s\n", argv[1]);
        return 1;
    }

    while((dp = readdir(dirp)) != NULL) {
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", argv[1], dp->d_name);

        if(stat(path, &buf) == -1) {
            printf("Error: Couldn't stat file %s\n", path);
            continue;
        }

        total_size += buf.st_size;
    }

    printf("Total size of directory %s is: %d bytes\n", argv[1], total_size);

    closedir(dirp);
    return 0;
}