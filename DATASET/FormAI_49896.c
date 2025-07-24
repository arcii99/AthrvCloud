//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

/* Define the structure of a single CPU usage data */
typedef struct CPUData {
    unsigned long long int user, nice, system, idle;
} CPUData;

/* Function that measures and returns the current CPU utilization */
float getCPUUtilization() {
    static unsigned long long int prev_idle_time = 0;
    static unsigned long long int prev_total_time = 0;
    unsigned long long int idle_time, total_time;
    CPUData cpu_data;
    FILE *fp;

    fp = fopen("/proc/stat", "r");
    fscanf(fp, "cpu %llu %llu %llu %llu", &cpu_data.user, &cpu_data.nice, &cpu_data.system, &cpu_data.idle);
    fclose(fp);

    idle_time = cpu_data.idle;
    total_time = cpu_data.user + cpu_data.nice + cpu_data.system + cpu_data.idle;

    float utilization = ((float) (total_time - prev_total_time) - (float)(idle_time - prev_idle_time)) / (float) (total_time - prev_total_time);

    prev_idle_time = idle_time;
    prev_total_time = total_time;

    return utilization * 100.0;
}

int main() {
    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);

    for (int i = 0; i < 1000000000; i++) {
        /* some dummy operation to generate CPU usage */
        int a = i + 10;
        int b = a * 2;
    }

    gettimeofday(&tval_after, NULL);

    /* Calculate the elapsed time */
    timersub(&tval_after, &tval_before, &tval_result);
    printf("Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

    /* Get the CPU utilization and print the result */
    float utilization = getCPUUtilization();
    printf("CPU Utilization: %.2f%%\n", utilization);

    return 0;
}