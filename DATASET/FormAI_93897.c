//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CPU_USAGE 100

int main(int argc, char *argv[]) {
    int interval = 1; // default interval is 1 second
    if (argc == 2) {
        interval = atoi(argv[1]);
    }

    long double prev_idle_time = 0, prev_total_time = 0, idle_time = 0, total_time = 0;
    char cpu[20];

    while (1) {
        FILE *fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("Error in opening /proc/stat");
            exit(EXIT_FAILURE);
        }

        fgets(cpu, 20, fp); // read only the first line from /proc/stat, which contains overall statistics for all CPUs
        fclose(fp);

        char *token = strtok(cpu, " "); // get first token, which is "cpu"
        token = strtok(NULL, " "); // get idle time, which is next token after "cpu"
        idle_time = atof(token);
        token = strtok(NULL, " "); // get first non-idle time, which is next token after idle time
        total_time = idle_time + atof(token);
        long double idle_time_delta = idle_time - prev_idle_time;
        long double total_time_delta = total_time - prev_total_time;
        prev_idle_time = idle_time;
        prev_total_time = total_time;

        float cpu_usage = (100.0 * (total_time_delta - idle_time_delta) / total_time_delta);
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        if (cpu_usage >= MAX_CPU_USAGE) {
            printf("WARNING: CPU usage is above %d%%\n", MAX_CPU_USAGE);
            // here, you can trigger an alert or take other actions, e.g. stop a process that's consuming too much CPU
        }

        sleep(interval); // sleep for the specified interval
    }

    return 0;
}