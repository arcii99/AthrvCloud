//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shape shifting
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CPU_STATES 10

void get_cpu_usage(unsigned long long int *previous_cpu_stats, unsigned long long int *previous_total_cpu_time, int *num_cpus, int *cpu_states) {
    char buffer[1024];
    int cpuid;

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Cannot open /proc/stat file. Check if this file exists.\n");
        exit(1);
    }

    fgets(buffer, 1024, fp);

    // Split first line with cpu details
    char *token = strtok(buffer, " ");
    token = strtok(NULL, " ");   // skip first token (cpu)

    int i = 0;
    while (token != NULL && i < MAX_CPU_STATES) {
        cpu_states[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    *num_cpus = i;

    fclose(fp);

    unsigned long long int total_cpu_time = 0;
    for (cpuid = 0; cpuid < *num_cpus; cpuid++) {
        total_cpu_time += cpu_states[cpuid];
    }

    unsigned long long int interval_cpu_time = total_cpu_time - *previous_total_cpu_time;
    double usage = (double)(interval_cpu_time) / ((double)total_cpu_time)*100;

    memcpy(previous_cpu_stats, cpu_states, MAX_CPU_STATES * sizeof(int));
    *previous_total_cpu_time = total_cpu_time;

    printf("CPU Usage: %.2f%%\n", usage);
}

int main(void) {
    unsigned long long int previous_cpu_stats[MAX_CPU_STATES];
    unsigned long long int previous_total_cpu_time = 0;
    int cpu_states[MAX_CPU_STATES];
    int num_cpus = 0;

    memset(cpu_states, 0, MAX_CPU_STATES * sizeof(int));

    while (1) {
        get_cpu_usage(previous_cpu_stats, &previous_total_cpu_time, &num_cpus, cpu_states);
        sleep(3);
    }
}