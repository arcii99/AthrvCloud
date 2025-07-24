//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int read_cpu_usage(float *usage) {
    static long prev_idle_time = 0;
    static long prev_total_time = 0;
    char line[MAX_LINE_LENGTH];
    long user, nice, system, idle, iowait, irq, softirq, steal, total;

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open /proc/stat\n");
        return 0;
    }

    fgets(line, MAX_LINE_LENGTH, fp);
    fclose(fp);

    sscanf(line, "cpu %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    total = user + nice + system + idle + iowait + irq + softirq + steal;
    if (prev_idle_time > 0) {
        float idle_time_delta = idle - prev_idle_time;
        float total_time_delta = total - prev_total_time;
        *usage = 100.0 * (1.0 - (idle_time_delta / total_time_delta));
    }
    prev_idle_time = idle;
    prev_total_time = total;

    return 1;
}

int main() {
    float usage = 0.0;

    while (1) {
        if (read_cpu_usage(&usage)) {
            printf("CPU Usage: %.2f%%\n", usage);
        } else {
            fprintf(stderr, "Failed to read CPU usage\n");
        }
        sleep(1);
    }

    return 0;
}