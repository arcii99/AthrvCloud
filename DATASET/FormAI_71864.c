//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MEMINFO_PATH "/proc/meminfo"

unsigned long get_memory_usage_in_kb() {
    FILE *file = fopen(MEMINFO_PATH, "r");
    char line[256];
    unsigned long mem_total_kb = 0, mem_free_kb = 0, mem_avail_kb = 0, buffers_kb = 0, cached_kb = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %lu kB", &mem_total_kb) == 1) continue;
        if (sscanf(line, "MemFree: %lu kB", &mem_free_kb) == 1) continue;
        if (sscanf(line, "MemAvailable: %lu kB", &mem_avail_kb) == 1) continue;
        if (sscanf(line, "Buffers: %lu kB", &buffers_kb) == 1) continue;
        if (sscanf(line, "Cached: %lu kB", &cached_kb) == 1) continue;
    }

    fclose(file);
    return mem_total_kb - mem_free_kb - buffers_kb - cached_kb;
}

int main() {
    printf("Starting C RAM Usage Monitor!\n");

    while (1) {
        unsigned long mem_usage_kb = get_memory_usage_in_kb();
        printf("Memory usage: %lu kB\n", mem_usage_kb);
        sleep(1);
    }

    return 0;
}