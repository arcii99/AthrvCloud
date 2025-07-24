//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <time.h>

int main() {
    printf("Welcome to CPU usage monitor program.\n");
    printf("This program will print the current CPU usage every second.\n");

    // Getting the system ticks per second
    long int ticks_per_second = sysconf(_SC_CLK_TCK);

    struct tms cpu;
    clock_t start;
    clock_t end;
    double cpu_time;

    while (1) {
        // Starting timer
        start = times(&cpu);

        // Delaying for 1 second
        sleep(1);

        // Ending timer
        end = times(&cpu);

        // Calculating CPU time
        cpu_time = (double) (end - start) / ticks_per_second;

        // Printing CPU usage
        printf("Current CPU usage: %.2f%%\n", cpu_time * 100);
    }

    return 0;
}