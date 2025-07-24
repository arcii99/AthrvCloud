//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    double total_cpu_secs = 0;  // Variable to hold total CPU time (user + system) consumed by the process
    double user_cpu_secs = 0;  // Variable to hold user CPU time consumed by the process
    double sys_cpu_secs = 0;   // Variable to hold system CPU time consumed by the process
    int cpu_perc = 0;          // Variable to hold CPU usage percentage

    while(1)
    {
        // Get CPU usage statistics
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);

        // Calculate total CPU time (user + system)
        total_cpu_secs = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec + (double)(usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000;

        // Calculate user CPU time
        user_cpu_secs = usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000;

        // Calculate system CPU time
        sys_cpu_secs = usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000;

        // Calculate CPU usage percentage
        cpu_perc = (int)(total_cpu_secs * 100 / (double)sysconf(_SC_CLK_TCK));

        // Print CPU usage statistics
        printf("Total CPU time: %.2f seconds\n", total_cpu_secs);
        printf("User CPU time: %.2f seconds\n", user_cpu_secs);
        printf("System CPU time: %.2f seconds\n", sys_cpu_secs);
        printf("CPU usage: %d%%\n", cpu_perc);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}