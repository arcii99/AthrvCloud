//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

void print_cpu_usage() {
    struct rusage usage;
    double user_time, system_time, total_time;

    getrusage(RUSAGE_SELF, &usage);
    user_time = (double)usage.ru_utime.tv_sec + ((double)usage.ru_utime.tv_usec / 1000000);
    system_time = (double)usage.ru_stime.tv_sec + ((double)usage.ru_stime.tv_usec / 1000000);
    total_time = user_time + system_time;

    printf("\n--- CPU USAGE ---\n");
    printf("User time: %.2f seconds\n", user_time);
    printf("System time: %.2f seconds\n", system_time);
    printf("Total time: %.2f seconds\n", total_time);
    printf("------------------\n");
}

int main() {
    printf("Starting CPU usage monitor...\n");

    while (1) {
        print_cpu_usage();
        sleep(1);
    }

    return 0;
}