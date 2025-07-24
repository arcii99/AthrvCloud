//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char path[1024];
    char buffer[16];
    int mem_total, mem_free, mem_used, mem_cached, mem_buf;
    float ram_usage;

    // Open the file that contains the memory usage information
    fp = fopen("/proc/meminfo", "r");

    if (fp == NULL) {
        printf("Error: /proc/meminfo file not found\n");
        exit(1);
    }

    // Loop through the lines of the file until the required information is found
    while (fgets(path, sizeof(path), fp) != NULL) {
        // Find the total memory size
        if (strncmp(path, "MemTotal:", 9) == 0) {
            sscanf(path+9, "%s", buffer);
            mem_total = atoi(buffer);
        }

        // Find the free memory size
        if (strncmp(path, "MemFree:", 8) == 0) {
            sscanf(path+8, "%s", buffer);
            mem_free = atoi(buffer);
        }

        // Find the cached memory size
        if (strncmp(path, "Cached:", 7) == 0) {
            sscanf(path+7, "%s", buffer);
            mem_cached = atoi(buffer);
        }

        // Find the buffer memory size
        if (strncmp(path, "Buffers:", 8) == 0) {
            sscanf(path+8, "%s", buffer);
            mem_buf = atoi(buffer);
        }
    }

    // Calculate the used memory size
    mem_used = mem_total - mem_free - mem_cached - mem_buf;

    // Calculate the RAM usage percentage
    ram_usage = ((float)mem_used / mem_total) * 100;

    // Print the RAM usage information
    printf("RAM usage: %.2f%%\n", ram_usage);

    return 0;
}