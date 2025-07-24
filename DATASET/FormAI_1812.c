//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define KB 1024
#define MB KB * 1024
#define GB MB * 1024

int main(int argc, char *argv[]) {
    char *dirPath = ".";
    int depth = 0;

    if (argc > 1) {
        dirPath = argv[1];
        if (argc > 2) {
            depth = atoi(argv[2]);
        }
    }

    struct stat pathStat;
    if (stat(dirPath, &pathStat) < 0) {
        printf("Unable to get stats of %s\n", dirPath);
        exit(1);
    }

    if (!S_ISDIR(pathStat.st_mode)) {
        printf("%s is not a directory\n", dirPath);
        exit(1);
    }

    printf("%s:\n", dirPath);
    analyzeDirectory(dirPath, depth, 0);

    return 0;
}

void analyzeDirectory(char *dirPath, int depth, int curDepth) {
    if (curDepth > depth && depth > 0) {
        return;
    }

    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        printf("Unable to open directory %s\n", dirPath);
        exit(1);
    }

    struct dirent *dirEntry;
    char filePath[256];
    struct stat pathStat;
    long long int dirSize = 0;

    while ((dirEntry = readdir(dir))) {
        if (strcmp(".", dirEntry->d_name) == 0 || strcmp("..", dirEntry->d_name) == 0) {
            continue;
        }

        sprintf(filePath, "%s/%s", dirPath, dirEntry->d_name);
        if (stat(filePath, &pathStat) < 0) {
            printf("Unable to get stats of %s\n", filePath);
            exit(1);
        }

        if (S_ISDIR(pathStat.st_mode)) {
            analyzeDirectory(filePath, depth, curDepth + 1);
        } else {
            printf("\t%s (%lld bytes)\n", filePath, pathStat.st_size);
            dirSize += pathStat.st_size;
        }
    }

    closedir(dir);

    printf("\n%s (%lld bytes):\n", dirPath, dirSize);
    printSizeInfo(dirSize);
}

void printSizeInfo(long long int size) {
    if (size >= GB) {
        printf("\t%.2f GB\n", (float) size / GB);
    } else if (size >= MB) {
        printf("\t%.2f MB\n", (float) size / MB);
    } else if (size >= KB) {
        printf("\t%.2f KB\n", (float) size / KB);
    } else {
        printf("\t%lld bytes\n", size);
    }
}