//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_CPU_USAGE 90
#define MIN_CPU_USAGE 10
#define PARANOID_INTERVAL 5

int main() {
    srand(time(NULL));
    int cpu_usage = 0, time_elapsed = 0;
    printf("Starting CPU usage monitor...\n");

    while (1) {
        sleep(PARANOID_INTERVAL);
        time_elapsed += PARANOID_INTERVAL;
        
        if (time_elapsed % 60 == 0)  // check every minute
            cpu_usage = rand() % (MAX_CPU_USAGE - MIN_CPU_USAGE + 1) + MIN_CPU_USAGE;

        if (cpu_usage >= MAX_CPU_USAGE) {
            printf("ALERT! CPU usage too high: %d%%\n", cpu_usage);
            system("kill -9 $(pidof my_program)");  // kill the program
            return 0;
        }
        else
            printf("CPU usage is normal: %d%%\n", cpu_usage);
    }
    return 0;
}