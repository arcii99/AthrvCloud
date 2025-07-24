//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CPU_USAGE 100

// Function to calculate current CPU usage percentage
int calculate_cpu_usage() {
    int cpu_usage = 0;

    // Open and read the CPU stats file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp != NULL) {
        char buffer[256];
        fgets(buffer, sizeof(buffer), fp);

        // Extract the CPU times from the first line of the stats file
        unsigned long long user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
        int count = sscanf(buffer, "%*s %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice,
                           &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        if (count == 10) {
            // Calculate the total time spent on the CPU
            unsigned long long total_time = user + nice + sys + idle + iowait + irq + softirq + steal;

            // Calculate the total time spent on non-idle tasks
            unsigned long long non_idle_time = user + nice + sys + irq + softirq + steal;

            // Calculate the current CPU usage percentage
            if (total_time > 0) {
                cpu_usage = (int)((non_idle_time * 100)/total_time);
            }
        }

        fclose(fp);
    }

    return cpu_usage;
}

int main() {
    int cpu_usage = 0;

    // Loop indefinitely
    while (1) {
        // Get the current CPU usage percentage
        cpu_usage = calculate_cpu_usage();

        // Display the CPU usage percentage
        printf("Current CPU usage: %d%%\n", cpu_usage);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}