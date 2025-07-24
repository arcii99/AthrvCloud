//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to calculate RAM usage
// Returns the percentage of RAM used
float calculate_ram_usage() {
    FILE *fp;
    char buffer[1024];
    float ram_total, ram_free, ram_used;

    fp = fopen("/proc/meminfo", "r");
    fgets(buffer, 1024, fp);
    sscanf(buffer, "MemTotal: %f kB", &ram_total);

    fgets(buffer, 1024, fp);
    sscanf(buffer, "MemFree: %f kB", &ram_free);

    ram_used = ram_total - ram_free;

    fclose(fp);

    return (ram_used / ram_total) * 100;
}

// Main function
int main() {
    float ram_usage;
    while (1) {
        ram_usage = calculate_ram_usage();
        printf("RAM usage: %.2f%%\n", ram_usage);
        sleep(1);  // Sleep for 1 second before checking RAM usage again
    }

    return 0;
}