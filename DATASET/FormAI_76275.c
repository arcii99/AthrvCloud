//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB (KB * KB)
#define GB (MB * KB)

typedef struct {
    char name[256];
    unsigned long long size;
} FileInfo;

void analyzeDirectory(char *dirPath, FileInfo *fileList, int *count, int *size, int printDetails) {
    DIR *dir = opendir(dirPath);
    struct dirent *dp;
    int i;

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        char filePath[512];
        sprintf(filePath, "%s/%s", dirPath, dp->d_name);

        struct stat st;
        if (lstat(filePath, &st) == -1)
            continue;

        if (S_ISDIR(st.st_mode)) {
            analyzeDirectory(filePath, fileList, count, size, printDetails);
        } else {
            if (*count % 10 == 0)
                fileList = (FileInfo*)realloc(fileList, (*count + 10) * sizeof(FileInfo));

            strcpy(fileList[*count].name, dp->d_name);
            fileList[*count].size = st.st_size;
            (*count)++;
            *size += st.st_size;
        }
    }

    closedir(dir);

    if (printDetails) {
        printf("\nDirectory: %s\n", dirPath);
        printf("Total Size: %dMB\n", *size / MB);

        for (i = 0; i < *count; i++) {
            printf("%s - %dKB\n", fileList[i].name, fileList[i].size / KB);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    FileInfo *fileList = NULL;
    int count = 0, size = 0;
    analyzeDirectory(argv[1], fileList, &count, &size, 1);

    if (fileList)
        free(fileList);

    return 0;
}