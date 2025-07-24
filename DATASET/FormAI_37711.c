//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int getTotalFileSize(char* path);

int main() {

    char* path = "/"; // the root directory of the C drive
    int totalSize = getTotalFileSize(path);
    
    printf("Total size of C drive: %d bytes\n", totalSize);
    
    return 0;
}

int getTotalFileSize(char* path) {
    DIR* dir = opendir(path);
    struct dirent* directoryEntry;
    struct stat fileStat;
    int totalSize = 0;

    if (dir == NULL) { // error handling
        printf("Error opening directory.\n");
        exit(EXIT_FAILURE);
    }

    while ((directoryEntry = readdir(dir)) != NULL) { // loop through the directory
        char* fileName = directoryEntry->d_name;

        char childPath[strlen(path) + strlen(fileName) + 2];
        strcpy(childPath, path);
        strcat(childPath, "/");
        strcat(childPath, fileName);

        if (stat(childPath, &fileStat) == -1) { // error handling
            printf("Error getting file size of %s\n", fileName);
            exit(EXIT_FAILURE);
        }

        if (S_ISREG(fileStat.st_mode)) { // if it's a regular file
            totalSize += fileStat.st_size;
        } else if (S_ISDIR(fileStat.st_mode)) { // if it's a directory
            if (strcmp(".", fileName) != 0 && strcmp("..", fileName) != 0) { // ignore . and .. directories to prevent infinite loop
                totalSize += getTotalFileSize(childPath);
            }
        }
    }

    closedir(dir);
    return totalSize;
}