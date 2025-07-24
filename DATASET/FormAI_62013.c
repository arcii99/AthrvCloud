//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/times.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // Define variables
    struct tms cpu_time;
    clock_t start, end;
    time_t current_time;
    char time_string[25];
    double cpu_clock_ticks = sysconf(_SC_CLK_TCK);
    double cpu_usage = 0.0;
    const int delay = 2; // Delay for 2 seconds before checking CPU usage again

    // Get the current time
    current_time = time(NULL);
    strftime(time_string, 25, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Output time and header
    printf("Time: %s\n", time_string);
    printf("CPU Usage:\n");

    // Loop to check CPU usage every 2 seconds
    while (1) {
        
        start = times(&cpu_time);
        sleep(delay);
        end = times(&cpu_time);

        // Calculate CPU usage as a percentage
        cpu_usage = (double) ((end - start) * 100) / (cpu_clock_ticks * delay);

        // Output CPU usage
        printf("%.1f%%\n", cpu_usage);

    }

    return 0;
}