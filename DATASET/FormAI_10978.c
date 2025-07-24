//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
/** 
* This program extracts metadata information from a given file.
* The metadata information extracted includes file name and size,
* date of creation and last modification, owner and group, and file permissions.
**/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
    
    const char* file_path = argv[1];
    struct stat file_stats;
    int status = stat(file_path, &file_stats);
    if (status != 0) {
        fprintf(stderr, "Failed to get file stats for %s\n", file_path);
        return 1;
    }
    
    printf("-----FILE METADATA INFO-----\n");
    
    // File name and size
    printf("File Name: %s\n", file_path);
    printf("File Size: %ld bytes\n", file_stats.st_size);
    
    // Date of creation and last modification
    printf("Date of Creation: %s", ctime(&file_stats.st_ctime));
    printf("Last Modified: %s", ctime(&file_stats.st_mtime));
    
    // Owner and group
    printf("Owner ID: %d\n", file_stats.st_uid);
    printf("Group ID: %d\n", file_stats.st_gid);
    
    // File permissions
    printf("File Permissions: ");
    printf((S_ISDIR(file_stats.st_mode)) ? "d" : "-");
    printf((file_stats.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stats.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stats.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stats.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stats.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stats.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stats.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stats.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stats.st_mode & S_IXOTH) ? "x\n" : "-\n");
    
    return 0;
}