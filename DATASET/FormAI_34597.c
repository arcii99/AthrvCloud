//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void countFile(char *path, long *size) {
    struct dirent *dp;
    DIR *dir = opendir(path);
    struct stat buff;
    char filePath[1024];
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            sprintf(filePath, "%s/%s", path, dp->d_name);
            if (stat(filePath, &buff) != -1 && S_ISREG(buff.st_mode)) {
                *size += buff.st_size;
            } else if (stat(filePath, &buff) != -1 && S_ISDIR(buff.st_mode)) {
                countFile(filePath, size);
            }
        }
    }
    closedir(dir);
}

int main() {
    char path[1024];
    printf("Enter the path to analyze:\n");
    scanf("%s", path);

    long totalSize = 0;
    countFile(path, &totalSize);

    printf("The total disk space used by files in %s is: %ld bytes", path, totalSize);
    return 0;
}