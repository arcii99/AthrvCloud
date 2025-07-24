//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

long long total_size = 0; // variable to hold total size of directory

// function to calculate size recursively
void calculate_size(char *path) {
    DIR *dir = opendir(path); // open directory
    struct dirent *entry; // directory entry
    struct stat file_stats; // file stats
    char next_path[1024]; // path of next directory or file
    
    while ((entry = readdir(dir))) { // loop through entries
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // directory
            sprintf(next_path, "%s/%s", path, entry->d_name); // construct path of next directory
            calculate_size(next_path); // recursively call function for next directory
        }
        else { // file
            sprintf(next_path, "%s/%s", path, entry->d_name); // construct path of file
            stat(next_path, &file_stats); // get file stats
            total_size += file_stats.st_size; // add file size to total size
        }
    }
    
    closedir(dir); // close directory
}

int main(int argc, char **argv) {
    if (argc != 2) { // check if directory path is provided as argument
        printf("Please provide the directory path as argument.\n");
        return 1;
    }
    
    calculate_size(argv[1]); // calculate size recursively
    
    printf("Total size of directory %s is %lld bytes.\n", argv[1], total_size); // print total size
    
    return 0;
}