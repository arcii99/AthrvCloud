//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define SAMPLE_TIME 1 // In seconds
#define WARNING_THRESHOLD 80.0 // In percentage
#define CRITICAL_THRESHOLD 90.0 // In percentage

double get_cpu_usage() {
    struct rusage usage;
    double cpu_usage;
    getrusage(RUSAGE_SELF, &usage);
    cpu_usage = ((double) usage.ru_utime.tv_sec) + ((double) usage.ru_utime.tv_usec) / 1000000.0;
    cpu_usage += ((double) usage.ru_stime.tv_sec) + ((double) usage.ru_stime.tv_usec) / 1000000.0;
    return cpu_usage;
}

int main() {
    double cpu_usage;
    while(1) {
        cpu_usage = get_cpu_usage();
        printf("Current CPU usage: %.2f%%\n", cpu_usage);
        if(cpu_usage >= CRITICAL_THRESHOLD) {
            printf("CPU usage is critical: %.2f%%\n", cpu_usage);
            // Do something to handle the critical condition
        } else if(cpu_usage >= WARNING_THRESHOLD) {
            printf("CPU usage is warning: %.2f%%\n", cpu_usage);
            // Do something to handle the warning condition
        }
        sleep(SAMPLE_TIME);
    }
    return 0;
}