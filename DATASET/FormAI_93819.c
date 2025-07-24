//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int getTotalSize(char *dir);

int main() {
    char dirName[100];
    printf("Enter the name of your desired directory: ");
    scanf("%s", dirName);
    
    int totalSize = getTotalSize(dirName);
    
    printf("\nTotal size of %s: %d bytes\n", dirName, totalSize);
    
    return 0;
}

int getTotalSize(char *dir) {
    int total = 0;
    DIR *d;
    struct dirent *dirEntry;
    d = opendir(dir);
    struct stat s;
    if (d) {
        while ((dirEntry = readdir(d)) != NULL) {
            if (strcmp(dirEntry->d_name, "..") == 0 || strcmp(dirEntry->d_name, ".") == 0)
                continue;
            char path[100];
            strcpy(path, dir);
            strcat(path, "/");
            strcat(path, dirEntry->d_name);
            if (stat(path, &s) == 0) {
                if (s.st_mode & S_IFDIR) {
                    total += getTotalSize(path);
                }
                else {
                    total += s.st_size;
                }
            }
        }
        closedir(d);
    }
    return total;
}