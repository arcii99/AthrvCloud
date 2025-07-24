//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

const int NANO_TO_MILLI = 1000000;

void print_cpu_usage(int sleep_duration) {
    struct rusage usage;
    struct timeval start_time, end_time;

    getrusage(RUSAGE_SELF, &usage);
    start_time = usage.ru_utime;

    usleep(sleep_duration * NANO_TO_MILLI);

    getrusage(RUSAGE_SELF, &usage);
    end_time = usage.ru_utime;

    double total_time = (double) (end_time.tv_sec - start_time.tv_sec) 
                      + (double) (end_time.tv_usec - start_time.tv_usec) / 1000000;
    double cpu_usage = total_time / (double) sleep_duration;

    printf("CPU usage: %f%%\n", cpu_usage * 100);
}

int main(int argc, char *argv[]) {
    int sleep_duration = 1000; // 1 second

    if (argc == 2) {
        int arg = atoi(argv[1]);
        if (arg > 0) {
            sleep_duration = arg;
        }
    }

    while (1) {
        print_cpu_usage(sleep_duration);
    }

    return 0;
}