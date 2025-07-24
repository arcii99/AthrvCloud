//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    long int pagesize = sysconf(_SC_PAGESIZE);
    FILE *fp = NULL;
    char buffer[BUFFER_SIZE];

    while (1) {
        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            printf("Error! Can't open /proc/meminfo.\n");
            exit(1);
        }

        long int total_memory, free_memory, available_memory, buffers_memory, cached_memory, used_memory;
        while (fgets(buffer, BUFFER_SIZE, fp)) {
            if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {}
            else if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {}
            else if (sscanf(buffer, "MemAvailable: %ld kB", &available_memory) == 1) {}
            else if (sscanf(buffer, "Buffers: %ld kB", &buffers_memory) == 1) {}
            else if (sscanf(buffer, "Cached: %ld kB", &cached_memory) == 1) {}
        }
        fclose(fp);

        used_memory = total_memory - free_memory;
        float usage = ((float)used_memory / (float)total_memory) * 100.0;
        if (usage >= 90) {
            printf("WARNING: CRITICAL MEMORY USAGE! Current usage: %.2f%%\n", usage);
        } else {
            printf("Current memory usage: %.2f%%\n", usage);
        }

        sleep(5); // wait 5 seconds before checking again
    }

    return 0;
}