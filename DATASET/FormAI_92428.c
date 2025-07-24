//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define CPU_FILE "/proc/stat"

int main() {
    FILE* fp;
    char line[512];
    unsigned long long int utime, ntime, stime, idle, iowait, irq, softirq, steal, guest, guest_nice;
    unsigned long long int previous_usage = 0, current_usage = 0, total_usage;

    while(1) {
        fp = fopen(CPU_FILE, "r");
        if(fp == NULL) {
            printf("Error opening CPU stats file!\n");
            exit(EXIT_FAILURE);
        }

        fgets(line, sizeof(line), fp);
        sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &utime, &ntime, &stime, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

        current_usage = utime + ntime + stime + irq + softirq + guest + guest_nice;
        total_usage = current_usage - previous_usage;
        previous_usage = current_usage;

        float cpu_utilization = (((float)total_usage / (float)sysconf(_SC_CLK_TCK)) / (float)get_nprocs()) * 100.0; // Get CPU utilization in percentage
        if(cpu_utilization >= 80.0) { // If CPU usage is more than or equal to 80%, display warning message
            printf("WARNING! CPU usage is above 80%%. Current utilization: %.2f%%\n", cpu_utilization);
        } else {
            printf("Current CPU utilization: %.2f%%\n", cpu_utilization);
        }

        fclose(fp);
        sleep(1); // Update CPU usage stats after each second
    }

    return 0;
}