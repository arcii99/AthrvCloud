//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    long long int total_memory, free_memory, buffer_memory, cached_memory, active_memory, inactive_memory, used_memory;
    char unit;
    
    FILE *fp;
    fp = fopen("/proc/meminfo", "r"); //opening the file that contains the memory information
    
    /*Extracting the required data from the file*/
    fscanf(fp, "MemTotal: %lld %cB\n", &total_memory, &unit);
    fscanf(fp, "MemFree: %lld %cB\n", &free_memory, &unit);
    fscanf(fp, "Buffers: %lld %cB\n", &buffer_memory, &unit);
    fscanf(fp, "Cached: %lld %cB\n", &cached_memory, &unit);
    fscanf(fp, "Active: %lld %cB\n", &active_memory, &unit);
    fscanf(fp, "Inactive: %lld %cB\n", &inactive_memory, &unit);

    fclose(fp); //closing the file
    
    /*Calculating the used memory*/
    used_memory = total_memory - free_memory - buffer_memory - cached_memory - active_memory - inactive_memory;
    
    /*Printing the data*/
    printf("Total Memory: %lld %cB\n", total_memory, unit);
    printf("Used Memory: %lld %cB\n", used_memory, unit);
    printf("Free Memory: %lld %cB\n", free_memory, unit);
    printf("Buffer Memory: %lld %cB\n", buffer_memory, unit);
    printf("Cached Memory: %lld %cB\n", cached_memory, unit);
    printf("Active Memory: %lld %cB\n", active_memory, unit);
    printf("Inactive Memory: %lld %cB\n", inactive_memory, unit);
    
    return 0;
}