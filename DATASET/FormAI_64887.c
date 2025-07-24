//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    int alert = 0;
    while (1) {
        // Getting system information
        if (sysinfo(&info) != 0) {
            fprintf(stderr, "Failed to get system information\n");
            return 1;
        }

        // Getting RAM information
        long long total_ram = (long long) info.totalram * info.mem_unit;
        long long free_ram = (long long) info.freeram * info.mem_unit;
        long long used_ram = total_ram - free_ram;
        double usage_percent = (double) used_ram / total_ram * 100;

        // Displaying RAM usage information
        printf("---RAM USAGE MONITOR---\n");
        printf("Total RAM:\t%lld MB\n", total_ram / 1024 / 1024);
        printf("Used RAM:\t%lld MB\n", used_ram / 1024 / 1024);
        printf("Free RAM:\t%lld MB\n", free_ram / 1024 / 1024);
        printf("Usage:\t\t%.1f%%\n", usage_percent);

        // Checking if RAM usage is above 90%
        if (usage_percent >= 90) {
            if (!alert) {
                printf("RAM usage is critical! Please free up some memory.\n");
                alert = 1;
            }
        } else {
            if (alert) {
                printf("RAM usage is normal now.\n");
                alert = 0;
            }
        }

        // Waiting for 5 seconds before checking again
        sleep(5);
    }
    return 0;
}