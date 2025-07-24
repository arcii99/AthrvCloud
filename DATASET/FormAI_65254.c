//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int limit = 75; // Percentage threshold
    while(1) {
        FILE *file;
        file = fopen("/proc/meminfo", "r");
        char buffer[256];
        int total_mem, free_mem, buffer_mem, cached_mem, used_mem, usage_percent;

        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "MemTotal: %d kB", &total_mem);
        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "MemFree: %d kB", &free_mem);
        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "Buffers: %d kB", &buffer_mem);
        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "Cached: %d kB", &cached_mem);

        used_mem = total_mem - free_mem - buffer_mem - cached_mem;
        usage_percent = used_mem * 100 / total_mem;

        fclose(file);
        if(usage_percent >= limit) {
            printf("Memory usage crossed %d%%, Current Usage: %d%%\n", limit, usage_percent);
        } else {
            printf("Memory usage is below %d%%, Current Usage: %d%%\n", limit, usage_percent);
        }
        sleep(1); // Sleep for 1 second before checking again
    }
    return 0;
}