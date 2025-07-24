//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

// This program monitors the CPU usage on a Linux machine and prints the percentage of CPU usage every second

int main() {
    FILE* file = fopen("/proc/stat", "r"); // open stat file
    if (file == NULL) {
        printf("Error: Cannot open /proc/stat file");
        return 1;
    }
    long double old_total_cpu_time = 0.0, old_idle_cpu_time = 0.0;
    while (1) {
        // Read CPU usage from /proc/stat file
        fseek(file, 0, SEEK_SET);
        long double user_time = 0.0, nice_time = 0.0, system_time = 0.0, idle_time = 0.0, io_wait_time = 0.0, irq_time = 0.0, softirq_time = 0.0, steal_time = 0.0;
        fscanf(file, "cpu %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &user_time, &nice_time, &system_time, &idle_time, &io_wait_time, &irq_time, &softirq_time, &steal_time);

        // Calculate CPU usage percentage
        long double total_cpu_time = user_time + nice_time + system_time + idle_time + io_wait_time + irq_time + softirq_time + steal_time;
        long double cpu_percent = ((total_cpu_time - old_total_cpu_time) - (idle_time - old_idle_cpu_time)) / (total_cpu_time - old_total_cpu_time) * 100.0;

        // Print CPU usage percentage
        printf("CPU Usage: %.2Lf %%\n", cpu_percent);

        old_total_cpu_time = total_cpu_time;
        old_idle_cpu_time = idle_time;

        sleep(1); // wait for 1 second
    }
    fclose(file);
    return 0;
}