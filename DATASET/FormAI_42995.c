//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct File {
    char *name;
    long long size;
};

typedef struct File File;

int compare(File *a, File *b) {
    if (a->size > b->size) return -1;
    else if (a->size < b->size) return 1;
    else return 0;
}

void analyzeDirectory(char *path, File *directoryFiles, int *fileCount, int *dirCount) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileInfo;

    char fullPath[PATH_MAX];

    if ((dir = opendir(path)) == NULL) {
        fprintf(stderr, "\nCannot open directory %s", path);
        exit(1);
    }

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR) { // If directory
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            sprintf(fullPath, "%s/%s", path, entry->d_name);
            (*dirCount)++;
            analyzeDirectory(fullPath, directoryFiles, fileCount, dirCount);
        } else { // If file
            (*fileCount)++;
            sprintf(fullPath, "%s/%s", path, entry->d_name);
            if (lstat(fullPath, &fileInfo)) {
                fprintf(stderr, "\nFailed to get file stats for %s\n", fullPath); 
                continue;
            }
            directoryFiles[*fileCount-1].name = (char*) malloc(strlen(entry->d_name));
            strcpy(directoryFiles[*fileCount-1].name, entry->d_name);
            directoryFiles[*fileCount-1].size = fileInfo.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    char *directoryPath;

    if (argc == 2) {
        directoryPath = argv[1];
    } else {
        fprintf(stderr, "\nPlease provide directory path\n");
        exit(1);
    }

    File directoryFiles[200000];
    int fileCount = 0, directoryCount = 0;

    analyzeDirectory(directoryPath, directoryFiles, &fileCount, &directoryCount);

    qsort(directoryFiles, fileCount, sizeof(File), (__compar_fn_t) compare);

    printf("\nTotal files: %d\nTotal directories: %d\n", fileCount, directoryCount);
    
    long long totalSize = 0;

    printf("\nLargest files:\n");
    for (int i=0; i < 10 && i < fileCount; i++) {
        printf("File: %s (%lld bytes)\n", directoryFiles[i].name, directoryFiles[i].size);
        totalSize += directoryFiles[i].size;
    }
    printf("Total size of largest files: %lld bytes\n", totalSize);

    return 0;
}