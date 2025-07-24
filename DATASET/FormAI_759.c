//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    DIR *d;
    struct dirent *dir;
    struct stat buf;
    long long int totalSize = 0;

    d = opendir(".");
    if(d) {
        while((dir = readdir(d)) != NULL) {
            char fileName[256];
            strcpy(fileName, dir->d_name);
            if(stat(fileName, &buf) == -1) {
                printf("Error getting stats for %s\n", fileName);
            }
            else {
                if((buf.st_mode & S_IFMT) == S_IFREG) {
                    totalSize += buf.st_size;
                }
            }
        }
        closedir(d);
    }
    printf("Total size of files in current directory: %lld bytes\n", totalSize);
    return 0;
}