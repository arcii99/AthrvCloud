//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define REFRESH_DELAY_SECONDS 2 // Refresh rate of the monitor

int main() {

    // Initial system information
    struct sysinfo si;
    unsigned long total_mem, free_mem;

    while (1) {

        sleep(REFRESH_DELAY_SECONDS); // Wait for the refresh rate

        // Get updated system information
        if (sysinfo(&si) == -1) {
            printf("Sysinfo Error\n");
            break;
        }

        // Calculate memory usage
        total_mem = si.totalram / 1024;
        free_mem = si.freeram / 1024;
        printf("Total Memory: %lu KB\n", total_mem);
        printf("Free Memory: %lu KB\n", free_mem);
        printf("Memory Usage: %.2f%%\n", ((double) (total_mem - free_mem) / total_mem) * 100);

    }

    return 0;
}