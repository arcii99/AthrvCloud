//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int threshold = 90; // set warning threshold to 90%
    float usage;
    FILE *meminfo;
    char buffer[256];
    int total_mem, free_mem, cached_mem, buff_mem;

    while(1) {
        // open file containing system memory info
        meminfo = fopen("/proc/meminfo", "r");
        
        // read file and store necessary memory info into respective variables
        if (meminfo != NULL) {
            fgets(buffer, sizeof(buffer), meminfo);
            sscanf(buffer, "MemTotal: %d kB", &total_mem);
            fgets(buffer, sizeof(buffer), meminfo);
            sscanf(buffer, "MemFree: %d kB", &free_mem);
            fgets(buffer, sizeof(buffer), meminfo);
            sscanf(buffer, "Cached: %d kB", &cached_mem);
            fgets(buffer, sizeof(buffer), meminfo);
            sscanf(buffer, "Buffers: %d kB", &buff_mem);
            fclose(meminfo);
        } else {
            printf("Error: could not read /proc/meminfo\n");
            exit(1);
        }

        // calculate memory usage
        usage = (total_mem - (free_mem + cached_mem + buff_mem)) * 100.0 / total_mem;

        if (usage >= threshold) {
            // if RAM usage exceeds threshold, print warning message
            printf("WARNING: RAM usage is at %.2f%%\n", usage);
        }

        sleep(10); // check again after 10 seconds
    }

    return 0;
}