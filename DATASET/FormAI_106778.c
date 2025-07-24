//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define NUM_ITERATIONS 1000000

void cpu_usage_monitor() {
    struct rusage usage;
    int i;

    for (i = 0; i < NUM_ITERATIONS; ++i) {
        getrusage(RUSAGE_SELF, &usage);
    }

    long total_ms = ((usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * 1000
                    + (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000);

    printf("CPU usage: %lu milliseconds\n", total_ms);
}

int main() {
    printf("Monitoring CPU usage...\n");

    while (1) {
        cpu_usage_monitor();
        sleep(1);
    }

    return 0;
}