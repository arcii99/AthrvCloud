//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MB_TO_BYTES 1048576 // Conversion factor from MB to bytes

int main() {
    struct sysinfo info; // struct to hold system memory information
    
    while (1) { // loop continuously to monitor RAM usage
        
        // Get system memory information
        if (sysinfo(&info) != 0) {
            printf("Error: failed to get system memory information\n");
            exit(EXIT_FAILURE);
        }
        
        // Calculate RAM usage statistics
        long total_mem = (info.totalram * info.mem_unit) / MB_TO_BYTES;
        long free_mem = (info.freeram * info.mem_unit) / MB_TO_BYTES;
        long used_mem = total_mem - free_mem;
        float used_percent = ((float) used_mem / (float) total_mem) * 100;
        
        // Display RAM usage statistics
        printf("Total memory: %ld MB\n", total_mem);
        printf("Used memory: %ld MB (%.2f%%)\n", used_mem, used_percent);
        printf("Free memory: %ld MB\n", free_mem);
        printf("---------------------------------------\n");
        
        sleep(1); // wait for 1 second before checking RAM usage again
    }
    
    return 0;
}