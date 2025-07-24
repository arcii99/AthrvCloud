//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CPU 32
#define BUFFER_SIZE 1024

int main() {
    int cpu_count;
    char cpu_info[BUFFER_SIZE];
    long long prev_total_ticks[MAX_CPU], prev_idle_ticks[MAX_CPU];
    long long curr_total_ticks[MAX_CPU], curr_idle_ticks[MAX_CPU];
    float cpu_usage[MAX_CPU];

    // Read in the number of CPUs available
    FILE* fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL) {
        perror("Error reading CPU info file");
        exit(1);
    }
    while (fgets(cpu_info, BUFFER_SIZE, fp)) {
        if (strncmp(cpu_info, "processor", strlen("processor")) == 0)
            cpu_count++;
    }
    fclose(fp);

    while (1) {
        // Read in the current CPU usage for each CPU
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("Error reading CPU stat file");
            exit(1);
        }
        for (int i = 0; i < cpu_count; i++) {
            fscanf(fp, "cpu%d %lld %lld %*lld %*lld %*lld %*lld %*lld %*lld %*lld %*lld", 
                    i, &curr_idle_ticks[i], &curr_total_ticks[i]);
            cpu_usage[i] = (float)(curr_total_ticks[i] - prev_total_ticks[i] -
                            (curr_idle_ticks[i] - prev_idle_ticks[i])) / 
                            (curr_total_ticks[i] - prev_total_ticks[i]) * 100;
            prev_total_ticks[i] = curr_total_ticks[i];
            prev_idle_ticks[i] = curr_idle_ticks[i];
        }
        fclose(fp);

        // Output the CPU usage for each CPU
        printf("CPU Usage:\n");
        for (int i = 0; i < cpu_count; i++) {
            printf("CPU %d: %.2f%%\n", i, cpu_usage[i]);
        }
        printf("\n");

        // Wait for one second before polling again
        sleep(1);
    }

    return 0;
}