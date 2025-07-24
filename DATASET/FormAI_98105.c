//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/times.h>

int main(int argc, char **argv)
{
    double total_cpu_time, total_user_time, total_system_time;
    struct tms cpu_usage;
    clock_t start_cpu;

    start_cpu = times(&cpu_usage); // Record the start time

    while(1) {
        // Sleep for 1 second to allow CPU usage to be calculated
        sleep(1); 

        // Calculate CPU usage
        total_cpu_time = ((double) (times(&cpu_usage) - start_cpu)) / sysconf(_SC_CLK_TCK);
        total_user_time = ((double) cpu_usage.tms_utime) / sysconf(_SC_CLK_TCK);
        total_system_time = ((double) cpu_usage.tms_stime) / sysconf(_SC_CLK_TCK);

        // Print CPU usage statistics
        printf("\nCPU Usage Statistics:\n");
        printf("Total CPU Time: %lf seconds\n", total_cpu_time);
        printf("Total User Time: %lf seconds\n", total_user_time);
        printf("Total System Time: %lf seconds\n", total_system_time);
    }

    return 0;
}