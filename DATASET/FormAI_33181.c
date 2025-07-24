//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

double cpu_time_diff(clock_t start_clock, clock_t end_clock) {
    return ((double)(end_clock - start_clock)) / sysconf(_SC_CLK_TCK);
}

double get_cpu_usage() {
    static clock_t last_clock_ticks = 0;
    static struct tms last_process_times;
    clock_t clock_ticks = times(&last_process_times);

    double cpu_percentage = 0.0;
    if (last_clock_ticks != 0) {
        double total_cpu_time_diff = cpu_time_diff(last_process_times.tms_utime + last_process_times.tms_stime,
                                                    last_clock_ticks);
        double process_cpu_time_diff = cpu_time_diff(last_process_times.tms_utime, last_clock_ticks);
        cpu_percentage = (process_cpu_time_diff / total_cpu_time_diff) * 100.0;
    }

    last_clock_ticks = clock_ticks;
    last_process_times = (struct tms){0};
    return cpu_percentage;
}

int main() {
    for (int i = 0; i < 10; i++) {
        printf("CPU usage: %.2f%%\n", get_cpu_usage());
        sleep(1);
    }

    return 0;
}