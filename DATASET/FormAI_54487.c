//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#define INTERVAL 1 // Refresh interval in seconds

void get_ram_usage(unsigned long *total_mem, unsigned long *free_mem) {
    struct sysinfo mem_info;
    if (sysinfo(&mem_info) != 0) {
        printf("Error: Failed to obtain system memory information.\n");
        exit(1);
    }
    *total_mem = mem_info.totalram * mem_info.mem_unit;
    *free_mem = mem_info.freeram * mem_info.mem_unit;
}

int main() {
    unsigned long total_mem, free_mem;
    while (1) {
        get_ram_usage(&total_mem, &free_mem);
        printf("Total Memory: %lu bytes | Free Memory: %lu bytes | Used Memory: %lu bytes\n", 
            total_mem, free_mem, total_mem - free_mem);
        sleep(INTERVAL);
    }
    return 0;
}