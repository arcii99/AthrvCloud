//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    long ram_total, ram_free, ram_used;
    int usage_percentage;
    while (1) {
        sleep(1);
        if (sysinfo(&info) == -1) {
            fprintf(stderr, "Error: Failed to get system info.\n");
            exit(EXIT_FAILURE);
        }

        ram_total = info.totalram * info.mem_unit;
        ram_free = info.freeram * info.mem_unit;
        ram_used = ram_total - ram_free;
        usage_percentage = ((double) ram_used / ram_total) * 100;

        printf("RAM Total: %ld\n", ram_total);
        printf("RAM Used: %ld\n", ram_used);
        printf("RAM Free: %ld\n", ram_free);
        printf("RAM Usage Percentage: %d%%\n", usage_percentage);
    }
    return 0;
}