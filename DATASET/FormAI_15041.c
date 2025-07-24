//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    long prev_utime, prev_stime;
    int cpu_usage, i;
    
    // Get initial CPU usage
    getrusage(RUSAGE_SELF, &usage);
    prev_utime = usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;
    prev_stime = usage.ru_stime.tv_sec * 1000000 + usage.ru_stime.tv_usec;
    
    // Use CPU for 1 second
    for (i = 0; i < 1000000000; i++);
    
    // Get updated CPU usage
    getrusage(RUSAGE_SELF, &usage);
    long curr_utime = usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;
    long curr_stime = usage.ru_stime.tv_sec * 1000000 + usage.ru_stime.tv_usec;
    
    // Calculate CPU usage percentage
    cpu_usage = 100 * ((curr_utime + curr_stime) - (prev_utime + prev_stime)) / 1000000;
    
    // Display CPU usage percentage
    printf("CPU usage: %d%%\n", cpu_usage);
    
    return 0;
}