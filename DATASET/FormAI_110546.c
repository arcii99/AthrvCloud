//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<sys/statvfs.h>

//Function to convert bytes to GB, MB, KB or bytes
void convert_size(unsigned long size, char *converted_size) {
    float converted_size_value = size;
    int unit_count = 0;
    char* units[] = {"Bytes", "KB", "MB", "GB"};
    while (converted_size_value > 1024 && unit_count < 3) {
        converted_size_value = converted_size_value / 1024;
        unit_count++;
    }
    sprintf(converted_size, "%.2f %s", converted_size_value, units[unit_count]);
}

int main() {
    struct statvfs disk_statistics; 

    //Get file system statistics for the root directory
    if(statvfs("/", &disk_statistics) == -1)
    {
        printf("Error occurred while getting file system statistics\n");
        exit(1);
    }

    //Calculate disk space information
    unsigned long block_size = disk_statistics.f_frsize; 
    unsigned long total_blocks = disk_statistics.f_blocks; 
    unsigned long free_blocks = disk_statistics.f_bfree; 
    unsigned long available_blocks = disk_statistics.f_bavail; 

    //Convert block size to bytes
    unsigned long total_space = total_blocks * block_size;
    unsigned long free_space = free_blocks * block_size;
    unsigned long available_space = available_blocks * block_size;

    //Convert space to human readable format
    char total_space_string[30]; 
    char free_space_string[30];
    char available_space_string[30]; 

    convert_size(total_space, total_space_string);
    convert_size(free_space, free_space_string);
    convert_size(available_space, available_space_string);

    //Print disk space information in a formatted manner
    printf("Total space: %s\n", total_space_string);
    printf("Free space: %s\n", free_space_string);
    printf("Available space: %s\n", available_space_string);

    return 0;
}