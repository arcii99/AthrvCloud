//FormAI DATASET v1.0 Category: Browser Plugin ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void listFiles(char *path) {
    struct dirent *dp;
    DIR *dir = opendir(path);

    if (!dir) {
        printf("Could not open directory\n");
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            printf("%s\n", dp->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Please provide a directory path\n");
        return 1;
    }

    char *path = argv[1];

    listFiles(path);

    return 0;
}