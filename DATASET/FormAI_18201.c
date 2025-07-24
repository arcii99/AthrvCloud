//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    float current_cpu_usage, total_cpu_usage;
    FILE *stat_fp;
    char stat_buffer[1024];

    while (1) {
        stat_fp = fopen("/proc/stat", "r");
        if (stat_fp == NULL) {
            printf("Error opening stat file\n");
            return -1;
        }

        fgets(stat_buffer, sizeof(stat_buffer), stat_fp);
        fclose(stat_fp);

        sscanf(stat_buffer, "cpu %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %f", &total_cpu_usage);
        usleep(500000);

        stat_fp = fopen("/proc/stat", "r");
        if (stat_fp == NULL) {
            printf("Error opening stat file\n");
            return -1;
        }

        fgets(stat_buffer, sizeof(stat_buffer), stat_fp);
        fclose(stat_fp);

        sscanf(stat_buffer, "cpu %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %f", &current_cpu_usage);

        printf("Current CPU usage: %.2f%%\n", (current_cpu_usage - total_cpu_usage) * 100 / (sysconf(_SC_CLK_TCK) * 0.5));
    }

    return 0;
}