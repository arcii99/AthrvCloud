//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/times.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <interval>\n", argv[0]);
        printf("\t<interval>: Interval between measurements in seconds.\n");
        return -1;
    }

    int interval = atoi(argv[1]);
    struct tms start_time, end_time;
    clock_t start_clock, end_clock;
    double total_time = 0.0, user_time = 0.0, system_time = 0.0;
    double delta_total_time = 0.0, delta_user_time = 0.0, delta_system_time = 0.0;

    printf("Time\t\tCPU Usage\n");

    while (1) {
        // Get starting time and clock for interval
        start_clock = times(&start_time);
        sleep(interval);
        // Get ending time and clock for interval
        end_clock = times(&end_time);

        // Calculate time spent in interval and total time
        delta_total_time = (double)(end_clock - start_clock) / sysconf(_SC_CLK_TCK);
        delta_user_time = (double)(end_time.tms_utime - start_time.tms_utime) / sysconf(_SC_CLK_TCK);
        delta_system_time = (double)(end_time.tms_stime - start_time.tms_stime) / sysconf(_SC_CLK_TCK);
        total_time += delta_total_time;
        user_time += delta_user_time;
        system_time += delta_system_time;

        // Calculate and print CPU usage percentage
        double cpu_usage = ((delta_user_time + delta_system_time) / delta_total_time) * 100.0;
        printf("%s\t%.2f%%\n", asctime(localtime(&(end_time.tms_utime))), cpu_usage);
    }

    return 0;
}