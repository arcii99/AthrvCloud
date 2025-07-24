//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fp;
    char str[1000];
    const char* filename = "/proc/meminfo";
    long total_memory, free_memory, used_memory;
    float percent_used;
    
    while (1) {
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error opening file. Exiting...\n");
            exit(1);
        }
        
        // Read the first line of /proc/meminfo to get the total memory
        fgets(str, 1000, fp);
        sscanf(str, "MemTotal: %ld", &total_memory);
        
        // Read the second line of /proc/meminfo to get the free memory
        fgets(str, 1000, fp);
        sscanf(str, "MemFree: %ld", &free_memory);
        
        // Calculate the used memory and percent used
        used_memory = total_memory - free_memory;
        percent_used = (float) used_memory / total_memory * 100.0;
        
        printf("RAM Usage: %.1f%%\n", percent_used);
        fclose(fp);
        
        // Wait for 1 second before checking /proc/meminfo again
        sleep(1);
    }
    
    return 0;
}