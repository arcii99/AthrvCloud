//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fptr;
    char line[512]; // buffer to store the read line
    int total_memory, free_memory, used_memory, cache_memory;

    /* Read the total memory from /proc/meminfo */
    fptr = fopen("/proc/meminfo","r");
    fgets(line, sizeof(line), fptr);
    sscanf(line, "MemTotal: %d kB", &total_memory);
    fclose(fptr);

    while(1) {
        fptr = fopen("/proc/meminfo","r");
        /* Read the free, used and cached memory from /proc/meminfo */
        fgets(line, sizeof(line), fptr); // MemTotal
        fgets(line, sizeof(line), fptr); // MemFree
        sscanf(line, "MemFree: %d kB", &free_memory);
        fgets(line, sizeof(line), fptr); // MemAvailable
        fgets(line, sizeof(line), fptr); // Buffers
        fgets(line, sizeof(line), fptr); // Cached
        sscanf(line, "Cached: %d kB", &cache_memory);
        fclose(fptr);

        used_memory = total_memory - free_memory - cache_memory;

        printf("Total Memory : %d kB\n", total_memory);
        printf("Used Memory : %d kB\n", used_memory);
        printf("Free Memory : %d kB\n", free_memory);
        printf("Cache Memory : %d kB\n\n", cache_memory);

        sleep(1); // Sleep for 1 second
    }
    return 0;
}