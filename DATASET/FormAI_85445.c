//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    char *folder_path = "/";

    dir = opendir(folder_path);
    if(dir == NULL) {
        printf("Error: Unable to open directory.\n");
        exit(EXIT_FAILURE);
    }

    while((entry = readdir(dir)) != NULL) {
        char file_path[1024];
        sprintf(file_path, "%s/%s", folder_path, entry->d_name);

        if(stat(file_path, &file_stat) == -1) {
            printf("Error: Unable to get file status.\n");
            continue;
        }

        if(S_ISDIR(file_stat.st_mode)) {
            printf("Folder: %s\n", entry->d_name);
        } else if(S_ISREG(file_stat.st_mode)) {
            printf("File: %s (%ld bytes)\n", entry->d_name, file_stat.st_size);
        } else {
            printf("Unknown file type for: %s\n", entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}