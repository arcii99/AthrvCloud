//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_CPU_TIME 60 // Maximum CPU time (seconds) before the program terminates

int main() {
    struct rusage usage;
    struct timeval start, end; // Start and end time for CPU usage calculation
    double elapsed_time, cpu_time; // Elapsed time and CPU time used by program

    // Get the current time and CPU usage of the program
    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_utime;

    // Perform some dummy operations to consume CPU resources
    int x = 0;
    while (x < 1000000000) {
        x++;
    }

    // Get the elapsed time and CPU time used by the program
    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;
    elapsed_time = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / 1000000.0);
    cpu_time = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) + ((usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000.0);

    // Print the CPU usage stats to the console
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("CPU time: %.2f seconds\n", cpu_time);

    // Check if CPU time limit has been exceeded and terminate if necessary
    if (cpu_time > MAX_CPU_TIME) {
        printf("CPU time limit exceeded, program terminated.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}