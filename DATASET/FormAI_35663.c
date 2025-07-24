//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    FILE *meminfo;
    char buffer[256];
    int total_mem_kb, free_mem_kb, used_mem_kb;
    const int refresh_rate_sec = 2;

    while(1) {
        meminfo = fopen("/proc/meminfo", "r");
        if(meminfo == NULL) {
            printf("Error: Could not open /proc/meminfo file.\n");
            exit(1);
        }

        // Parse memory info
        fgets(buffer, sizeof(buffer), meminfo);
        sscanf(buffer, "MemTotal: %d kB", &total_mem_kb);

        fgets(buffer, sizeof(buffer), meminfo);
        sscanf(buffer, "MemFree: %d kB", &free_mem_kb);

        used_mem_kb = total_mem_kb - free_mem_kb;

        fclose(meminfo);

        // Output info to console
        printf("Total Memory: %d kB\n", total_mem_kb);
        printf("Free Memory: %d kB\n", free_mem_kb);
        printf("Used Memory: %d kB\n", used_mem_kb);

        sleep(refresh_rate_sec);
    }

    return 0;
}