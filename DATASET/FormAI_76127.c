//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int get_cpu_usage() {
    double idle_time, total_time, prev_idle_time = 0, prev_total_time = 0;
    FILE *stat_file = fopen("/proc/stat", "r");
    fscanf(stat_file, "%*s %lf %lf %lf %lf %*s", &total_time, &total_time, &total_time, &idle_time);
    fclose(stat_file);
    int cpu_usage = (100 * (1 - ((idle_time - prev_idle_time) / (total_time - prev_total_time))));
    prev_idle_time = idle_time;
    prev_total_time = total_time;
    return cpu_usage;
}

int main() {
    while (1) {
        int cpu_usage = get_cpu_usage();
        printf("CPU Usage: %d%%\n", cpu_usage);
        sleep(1);
    }
    return 0;
}