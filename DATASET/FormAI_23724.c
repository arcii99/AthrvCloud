//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define INTERVAL 1 // in seconds

void print_cpu_usage(double cpu_usage) {
    printf("CPU Usage: %0.2lf%%\n", cpu_usage);
}

double calculate_cpu_usage(struct rusage *start, struct rusage *end) {
    double user_time = (((double)end->ru_utime.tv_sec + (double)end->ru_utime.tv_usec/1000000) 
                        - ((double)start->ru_utime.tv_sec + (double)start->ru_utime.tv_usec/1000000));
    double system_time = (((double)end->ru_stime.tv_sec + (double)end->ru_stime.tv_usec/1000000) 
                          - ((double)start->ru_stime.tv_sec + (double)start->ru_stime.tv_usec/1000000));
    double total_cpu_time = user_time + system_time;
    double total_elapsed_time = INTERVAL;
    double cpu_usage = (total_cpu_time / total_elapsed_time) * 100;
    return cpu_usage;
}

void monitor_cpu_usage() {
    struct rusage start, end;
    getrusage(RUSAGE_SELF, &start);
    sleep(INTERVAL);
    getrusage(RUSAGE_SELF, &end);
    double cpu_usage = calculate_cpu_usage(&start, &end);
    print_cpu_usage(cpu_usage);
    monitor_cpu_usage(); // Recursive call to continue monitoring
}

int main() {
    printf("Starting CPU usage monitor...\n");
    monitor_cpu_usage();
    return 0;
}