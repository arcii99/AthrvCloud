//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Welcome! Let's monitor your RAM usage...\n");

    // Get the total amount of RAM in the system
    long total_ram = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);

    while (1) {
        // Get the current RAM usage
        FILE* file = fopen("/proc/meminfo", "r");
        char buffer[256], unit[3];
        long mem_total, mem_free, mem_available;
        fscanf(file, "%s %ld %s", buffer, &mem_total, unit);
        fscanf(file, "%s %ld %s", buffer, &mem_free, unit);
        fscanf(file, "%s %ld %s", buffer, &mem_available, unit);
        fclose(file);

        // Calculate RAM usage percentage
        int ram_usage = ((mem_total - mem_available) * 100) / total_ram;

        // Print RAM usage info
        printf("RAM usage: %d%% (%ld MB used out of %ld MB)\n", ram_usage, (mem_total - mem_available) / 1024, mem_total / 1024);

        // Wait for 5 seconds before checking RAM usage again
        sleep(5);
    }

    return 0;
}