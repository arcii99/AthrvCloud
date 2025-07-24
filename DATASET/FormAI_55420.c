//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define KB_DIVISOR 1024
#define MB_DIVISOR 1048576
#define GB_DIVISOR 1073741824

void monitor_memory_usage() {
    struct sysinfo info;
    int usage_percentage;
    long free_memory;
    long total_memory;
    long used_memory;
    long long total_swap;
    long long free_swap;

    for(;;) { // Loop infinitely
        // Get system info
        if(sysinfo(&info) == -1) {
            printf("Error getting system info.\n");
            exit(EXIT_FAILURE);
        }
        
        // Calculate memory usage in percentage
        free_memory = info.freeram / KB_DIVISOR;
        total_memory = info.totalram / KB_DIVISOR;
        used_memory = total_memory - free_memory;
        usage_percentage = used_memory * 100 / total_memory;

        // Calculate swap memory usage
        total_swap = info.totalswap / MB_DIVISOR;
        free_swap = info.freeswap / MB_DIVISOR;

        printf("Memory Usage: %d%%\n", usage_percentage);
        printf("Swap Memory: Total=%lldMB Free=%lldMB\n", total_swap, free_swap);

        sleep(5); // Sleep/Wait for 5 seconds before next monitoring cycle
    }
}

int main() {
    monitor_memory_usage(); // Start monitoring memory usage
    return 0;
}