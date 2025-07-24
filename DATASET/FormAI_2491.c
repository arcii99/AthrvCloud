//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

// This function prints the current CPU usage on Linux systems
void printCpuUsage() {
    struct rusage usage;
    if(getrusage(RUSAGE_SELF, &usage) != 0) {
        printf("Error: Unable to retrieve CPU usage\n");
        return;
    }

    // Calculating the CPU usage in seconds
    double cpuUsage = usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000;
    printf("CPU Usage: %.2f seconds\n", cpuUsage);
}

int main() {
    // Print the initial CPU usage
    printCpuUsage();

    // This is an infinite loop to demonstrate the CPU usage monitor
    int i = 0;
    while(1) {
        i++;
    }
    
    return 0;
}