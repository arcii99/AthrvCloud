//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

const int SLEEP_INTERVAL = 1;

int main() {
    while (1) {
        struct rusage cpu_usage;
        getrusage(RUSAGE_SELF, &cpu_usage);
        double cpu_time = (double)cpu_usage.ru_utime.tv_sec + 
                          (double)cpu_usage.ru_utime.tv_usec / 1000000.0;
        printf("CPU Usage: %.2f\n", cpu_time);
        sleep(SLEEP_INTERVAL);
    }
    return 0;
}