//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

void monitor_cpu_usage() {
    int seconds = 1;
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        perror("Error: unable to get resource usage");
        return;
    }

    double cpu_percent = ((double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000 + (double) usage.ru_stime.tv_sec + (double) usage.ru_stime.tv_usec / 1000000) * 100.0 / (double) seconds;
    printf("CPU usage: %f%%\n", cpu_percent);

    sleep(seconds);
    monitor_cpu_usage();
}

int main() {
    monitor_cpu_usage();
    return 0;
}