//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

// function to calculate disk space in a relaxed style
void disk_space_analyzer(char* path)
{
    struct statvfs stat;
    unsigned long long free_space, total_space, used_space, percent_used;
    
    if (statvfs(path, &stat) != 0) 
    {
        fprintf(stderr, "Error: Cannot calculate disk space\n");
        exit(EXIT_FAILURE);
    }
    
    // calculate total disk space
    total_space = (unsigned long long)stat.f_frsize * (unsigned long long)stat.f_blocks;
    
    // calculate free disk space
    free_space = (unsigned long long)stat.f_frsize * (unsigned long long)stat.f_bfree;
    
    // calculate used disk space
    used_space = total_space - free_space;
    
    // calculate percentage of used disk space
    percent_used = ((double)used_space / (double)total_space) * 100;
    
    // print results
    printf("Total space: %llu bytes\n", total_space);
    printf("Free space: %llu bytes\n", free_space);
    printf("Used space: %llu bytes\n", used_space);
    printf("Percentage used: %llu%%\n", percent_used);
}

int main()
{
    // call function to analyze disk space of C drive
    disk_space_analyzer("/");

    return 0;
}