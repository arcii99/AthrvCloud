//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int mem_total, mem_free, mem_used, buffers, cached;
    char line[256];
    const char* meminfo_path = "/proc/meminfo"; // path to the meminfo file
    FILE* fp = fopen(meminfo_path, "r"); 

    if (fp == NULL) {
        printf("Error opening %s\n", meminfo_path);
        exit(EXIT_FAILURE);
    }

    // Read through the file line by line and parse the values
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %d kB", &mem_total) == 1) {}
        if (sscanf(line, "MemFree: %d kB", &mem_free) == 1) {}
        if (sscanf(line, "Buffers: %d kB", &buffers) == 1) {}
        if (sscanf(line, "Cached: %d kB", &cached) == 1) {}
    }

    fclose(fp);

    // Calculate the memory usage
    mem_used = mem_total - mem_free - buffers - cached;

    // Output the results
    printf("Total Memory: %d KB\n", mem_total);
    printf("Memory Used: %d KB\n", mem_used);
    printf("Memory Free: %d KB\n", mem_free);
    printf("Buffers: %d KB\n", buffers);
    printf("Cached: %d KB\n", cached);
    
    // Calculate and output the RAM usage percentage
    float ram_usage = (float)mem_used / mem_total * 100;
    printf("RAM Usage: %.2f%%\n", ram_usage);

    return 0;
}