//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Declare file to read system CPU usage from
#define CPU_PROC_FILE "/proc/stat"

// Variables to store previous CPU usage values
static unsigned long long prev_total_ticks = 0;
static unsigned long long prev_idle_ticks = 0;

// Function to read system CPU usage from CPU_PROC_FILE
unsigned long long* get_cpu_usage() {
    // Open the CPU usage file for reading
    int fd = open(CPU_PROC_FILE, O_RDONLY);
    if (fd == -1) {
        printf("Error opening CPU usage file.\n");
        exit(1);
    }

    // Buffer to store CPU usage data
    char buf[1024];
    read(fd, buf, sizeof(buf));

    // Parse the CPU usage data
    unsigned long long cpu_ticks[10];
    sscanf(buf, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
        &cpu_ticks[0], &cpu_ticks[1], &cpu_ticks[2], &cpu_ticks[3],
        &cpu_ticks[4], &cpu_ticks[5], &cpu_ticks[6], &cpu_ticks[7],
        &cpu_ticks[8], &cpu_ticks[9]);

    // Close the CPU usage file
    close(fd);

    // Return the CPU usage data array
    return cpu_ticks;
}

int main() {
    // Loop forever
    while (1) {
        // Read the current CPU usage
        unsigned long long* cpu_usage = get_cpu_usage();

        // Calculate the total and idle CPU ticks
        unsigned long long total_ticks = 0, idle_ticks = 0;
        for (int i = 0; i < 10; i++) {
            total_ticks += cpu_usage[i];
            if (i == 3) {
                idle_ticks = cpu_usage[i];
            }
        }

        // Calculate the CPU usage percentage
        double cpu_usage_percent = 0;
        if (prev_total_ticks != 0) {
            unsigned long long delta_total = total_ticks - prev_total_ticks;
            unsigned long long delta_idle = idle_ticks - prev_idle_ticks;
            cpu_usage_percent = (delta_total - delta_idle) * 100.0 / delta_total;
        }

        // Store the current CPU usage values as previous for next iteration
        prev_total_ticks = total_ticks;
        prev_idle_ticks = idle_ticks;

        // Print the CPU usage percentage
        printf("CPU Usage: %.2f%%\n", cpu_usage_percent);

        // Wait for 1 second before next iteration
        sleep(1);
    }

    // Exit
    return 0;
}