//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate the size of a directory
long long calculateSize(char *path) {
    DIR *dir = opendir(path);
    if(!dir) {
        perror("Directory does not exist");
        exit(EXIT_FAILURE);
    }
    
    long long size = 0;
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {
        struct stat entry_stat;
        char entry_path[1024];
        sprintf(entry_path, "%s/%s", path, entry->d_name);
        
        if(stat(entry_path, &entry_stat) < 0) {
            perror("Cannot get file/directory size");
            exit(EXIT_FAILURE);
        }
        
        if(S_ISREG(entry_stat.st_mode)) {
            size += entry_stat.st_size;
        } else if(S_ISDIR(entry_stat.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            size += calculateSize(entry_path);
        }
    }
    
    closedir(dir);
    return size;
}

int main() {
    char *path = "/"; // Change this to the path you want to analyze
    long long size = calculateSize(path);
    
    printf("Size of %s: %lld bytes\n", path, size);
    
    return 0;
}