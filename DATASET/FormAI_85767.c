//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void analyzeSpace(char* path, int level);

int main() {
    char path[100];
    printf("Enter the path to analyze: ");
    scanf("%s", path);
    analyzeSpace(path, 0);
    return 0;
}

void analyzeSpace(char* path, int level) {
    DIR* directory = opendir(path);
    struct dirent* directoryEntry;
    struct stat fileStat;
    long long int totalSize = 0;
    while ((directoryEntry = readdir(directory)) != NULL) {
        char nextPath[100];
        sprintf(nextPath, "%s/%s", path, directoryEntry->d_name);
        if (stat(nextPath, &fileStat) == -1) {
            printf("Error: Could not get file stats for %s\n", directoryEntry->d_name);
            continue;
        }
        if (S_ISDIR(fileStat.st_mode) && strcmp(directoryEntry->d_name, ".") != 0 && strcmp(directoryEntry->d_name, "..") != 0) {
            printf("%*s%s/\n", level*4, "", directoryEntry->d_name);
            analyzeSpace(nextPath, level+1);
        }
        else {
            totalSize += fileStat.st_size;
        }
    }
    printf("%*sTotal Size: %.2f MB\n", level*4, "", (float)totalSize/(1024*1024));
    closedir(directory);
}