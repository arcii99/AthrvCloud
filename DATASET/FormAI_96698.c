//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fp;
    char buffer[80];
    int total_memory, free_memory, buffer_memory, cached_memory, used_memory;

    while (1) {
        sleep(2);
        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            exit(1);
        }

        // Reading memory statistics from /proc/meminfo
        fgets(buffer, 80, fp);
        sscanf(buffer, "MemTotal: %d kB", &total_memory);

        fgets(buffer, 80, fp);
        sscanf(buffer, "MemFree: %d kB", &free_memory);

        fgets(buffer, 80, fp);
        sscanf(buffer, "Buffers: %d kB", &buffer_memory);

        fgets(buffer, 80, fp);
        sscanf(buffer, "Cached: %d kB", &cached_memory);

        fclose(fp);

        // Calculating used memory
        used_memory = total_memory - free_memory - buffer_memory - cached_memory;

        // Printing memory usage
        printf("\n");
        printf("Total Memory: %d kB\n", total_memory);
        printf("Used Memory: %d kB\n", used_memory);
        printf("Free Memory: %d kB\n", free_memory);
        printf("Buffer Memory: %d kB\n", buffer_memory);
        printf("Cached Memory: %d kB\n", cached_memory);
    }

    return 0;
}