//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

int main() {
    struct dirent *de;  // Pointer for directory entry
    struct statvfs stats;  // Structure to store file system statistics
    long long int total = 0, used = 0, available = 0;  // Variables to store disk space information
        
    DIR *dr = opendir("."); // opendir() returns a pointer of DIR type.
        
    if (dr == NULL) {  // opendir returns NULL if couldn't open directory
        printf("Could not open current directory" );
        return 0;
    }
        
    printf("\n%-50s %15s %15s %15s\n\n", "Directory Name", "Total Space", "Used Space", "Available Space");
        
    while ((de = readdir(dr)) != NULL) {  // Iterate through all the files and directories
            
        if (de->d_type == DT_DIR && strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {  // Check if it is a directory and not . or ..
                
            if (statvfs(de->d_name, &stats) != -1) {  // Get file system statistics
                
                total = (long long int) stats.f_blocks * (long long int) stats.f_frsize;  // Calculate total space
                available = (long long int) stats.f_bavail * (long long int) stats.f_frsize;  // Calculate available space
                used = total - available;  // Calculate used space
                        
                printf("%-50s %15lld %15lld %15lld\n", de->d_name, total, used, available);  // Print directory name and disk space information
            }
        }
    }

    closedir(dr);  // Close directory pointer
    return 0;
}