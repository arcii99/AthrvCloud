//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define CPU_USAGE_REFRESH_TIME 2 // Time in seconds to refresh CPU usage data

int main() {
    long double previous_total_time = 0.0;
    long double previous_idle_time = 0.0;
    struct sysinfo system_info;
    time_t refresh_time = time(NULL) + CPU_USAGE_REFRESH_TIME;

    while (1) {
        if (time(NULL) >= refresh_time) {
            if (sysinfo(&system_info) != 0) {
                fprintf(stderr, "Failed to get system info!\n");
                exit(EXIT_FAILURE);
            }

            long double total_time = (long double)(system_info.totalram - system_info.freeram) / (long double)system_info.totalram * 100.0;
            long double idle_time = (long double)system_info.freeram / (long double)system_info.totalram * 100.0;

            printf("CPU Usage: %.2Lf%%\t Idle: %.2Lf%%\n", (total_time - previous_total_time), (idle_time - previous_idle_time));

            previous_total_time = total_time;
            previous_idle_time = idle_time;
            refresh_time = time(NULL) + CPU_USAGE_REFRESH_TIME;
        }
        
        // Sleeping for 100 milliseconds to avoid overusing CPU
        usleep(100000);
    }

    return 0;
}