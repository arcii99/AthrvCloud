//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

long long int getFolderSize(char *path) {
    long long int size = 0;
    DIR *dir = opendir(path);
    if(dir == NULL) {
        return size;
    }
    struct dirent *entry;
    char full_path[1024];
    struct stat file_stats;
    while((entry=readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        sprintf(full_path, "%s/%s", path, entry->d_name);
        if(stat(full_path, &file_stats) == -1) {
            continue;
        }
        if(S_ISDIR(file_stats.st_mode)) {
            size += getFolderSize(full_path);
        } else {
            size += file_stats.st_size;
        }
    }
    closedir(dir);
    return size;
}

int main() {
    char path[1024];
    printf("Enter the path to analyze the disk space: ");
    scanf("%s", path);
    printf("Calculating the disk space used by %s...\n", path);
    long long int size = getFolderSize(path);
    printf("Total disk space used by %s is %lld bytes.\n", path, size);
    return 0;
}