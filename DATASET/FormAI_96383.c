//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

// Function to calculate the total and free disk space of a directory
void calculateDiskSpace(char *path)
{
    struct statvfs stat;
    int total_space, free_space, used_space;

    if(statvfs(path, &stat) != 0){
        printf("Error: could not read file system information.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the total disk space in GB        
    total_space = (stat.f_blocks * stat.f_bsize) / (1024*1024*1024);
 
    // Calculate the free disk space in GB
    free_space = (stat.f_bfree * stat.f_bsize) / (1024*1024*1024);

    // Calculate the used disk space in GB
    used_space = total_space - free_space;

    // Print the disk space information
    printf("Directory: %s\n", path);
    printf("Total Disk Space: %d GB\n", total_space);
    printf("Used Disk Space: %d GB\n", used_space);
    printf("Free Disk Space: %d GB\n", free_space);
}

int main(int argc, char **argv)
{
    if(argc < 2){
        printf("Usage: %s <directory path name>\n", argv[0]);
        return 1;
    }

    calculateDiskSpace(argv[1]);

    return 0;
}