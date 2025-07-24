//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    
    if(argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return -1;
    }

    dir = opendir(argv[1]);
    if(dir == NULL) {
        printf("Unable to access directory %s\n", argv[1]);
        return -1;
    }
    
    // Code to analyze disk space goes here

    closedir(dir);
    return 0;
}