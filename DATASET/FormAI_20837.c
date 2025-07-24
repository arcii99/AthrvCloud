//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

int main() {
    clock_t start, end;
    struct tms t_start, t_end;
    double cpu_time_used;

    long clock_ticks = sysconf(_SC_CLK_TCK);
    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN);

    int num_samples = 10;
    double cpu_usage[num_samples];

    for(int i = 0; i < num_samples; i++) {
        start = times(&t_start);
        sleep(1);
        end = times(&t_end);

        double ticks = end - start;
        double seconds = ticks / clock_ticks;
        double cpu_utilization = (t_end.tms_utime - t_start.tms_utime) / ticks;
        cpu_usage[i] = cpu_utilization * num_cpus;
    }

    double avg_cpu_usage = 0.0;
    for(int i = 0; i < num_samples; i++) {
        avg_cpu_usage += cpu_usage[i];
    }
    avg_cpu_usage /= num_samples;

    printf("Average CPU Usage: %.2f\n", avg_cpu_usage);
    return 0;
}