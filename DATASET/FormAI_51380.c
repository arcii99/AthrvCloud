//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *f;
    char line[512];
    int total_memory, free_memory, used_memory, cached_memory, buffer_memory;

    while(1) {
        f = fopen("/proc/meminfo", "r");
        if(f == NULL) {
            printf("Error: Could not open /proc/meminfo\n");
            exit(EXIT_FAILURE);
        }

        fgets(line, sizeof(line), f);
        sscanf(line, "MemTotal: %d kB", &total_memory);
        fgets(line, sizeof(line), f);
        sscanf(line, "MemFree: %d kB", &free_memory);
        fgets(line, sizeof(line), f);
        sscanf(line, "Buffers: %d kB", &buffer_memory);
        fgets(line, sizeof(line), f);
        sscanf(line, "Cached: %d kB", &cached_memory);

        used_memory = total_memory - (free_memory + cached_memory + buffer_memory);

        printf("Total RAM: %d kB\n", total_memory);
        printf("Used RAM: %d kB\n", used_memory);
        printf("Free RAM: %d kB\n", free_memory);

        fclose(f);
        sleep(5); // sleep for 5 seconds before checking again
    }

    return 0;
}