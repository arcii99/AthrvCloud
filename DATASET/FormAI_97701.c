//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INTERVAL 1

void print_usage(size_t total, size_t free) {
    printf("Total Memory: %lu bytes\n", total);
    printf("Free Memory: %lu bytes\n", free);
    double percentage = ((double)free / (double)total) * 100;
    printf("Memory Usage: %0.2f%%\n", 100 - percentage);
}

int main() {
    size_t free_memory, total_memory;
    char *buffer;
    while (1) {
        FILE *meminfo_file = fopen("/proc/meminfo", "r");
        if (meminfo_file == NULL) {
            fprintf(stderr, "Failed to open /proc/meminfo file\n");
            return EXIT_FAILURE;
        }

        if (getline(&buffer, &total_memory, meminfo_file) == -1 ||
            getline(&buffer, &total_memory, meminfo_file) == -1 ||
            getline(&buffer, &total_memory, meminfo_file) == -1) {
            fprintf(stderr, "Failed to read /proc/meminfo file\n");
            fclose(meminfo_file);
            return EXIT_FAILURE;
        }
        sscanf(buffer, "MemTotal: %lu", &total_memory);

        if (getline(&buffer, &free_memory, meminfo_file) == -1) {
            fprintf(stderr, "Failed to read /proc/meminfo file\n");
            fclose(meminfo_file);
            return EXIT_FAILURE;
        }
        sscanf(buffer, "MemFree: %lu", &free_memory);

        fclose(meminfo_file);

        print_usage(total_memory, free_memory);

        sleep(INTERVAL);
    }

    return EXIT_SUCCESS;
}