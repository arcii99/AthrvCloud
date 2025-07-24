//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define KB 1024
#define MB (KB*KB)

int main() {
    
    FILE *fp = fopen("/proc/meminfo", "r");
    
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }
    
    char buffer[512]; 
    int total_mem, free_mem, available_mem;
    
    while (fgets(buffer, sizeof(buffer), fp)) {
    
        if (sscanf(buffer, "MemTotal: %d kB", &total_mem) == 1) {
            printf("Total memory: %d MB\n", total_mem/KB);
        }
    
        if (sscanf(buffer, "MemFree: %d kB", &free_mem) == 1) {
            printf("Free memory: %d MB\n", free_mem/KB);
        }
    
        if (sscanf(buffer, "MemAvailable: %d kB", &available_mem) == 1) {
            printf("Available memory: %d MB\n", available_mem/KB);
        }
    }
    
    float used_mem = (total_mem - free_mem - available_mem)/ (float) total_mem * 100;
    printf("Used memory: %.2f %%\n", used_mem);
    
    fclose(fp);
    return 0;
}