//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>

int main() {

    // Set the process priority to lowest
    setpriority(PRIO_PROCESS, 0, 15);

    // Define a struct to hold the CPU usage information
    struct rusage usage;
    int cpuUsage;

    // Get the starting CPU time
    getrusage(RUSAGE_SELF, &usage);
    long startCPUTime = usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;

    while (1) {
        // Sleep for one second
        sleep(1);

        // Get the current CPU usage
        getrusage(RUSAGE_SELF, &usage);
        long currentCPUTime = usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;

        // Calculate the CPU usage for the past second
        cpuUsage = (currentCPUTime - startCPUTime) * 100 / 1000000;

        // Print the CPU usage percentage
        printf("CPU Usage: %d%%\n", cpuUsage);

        // Reset the start CPU time
        startCPUTime = currentCPUTime;
    }

    return 0;
}