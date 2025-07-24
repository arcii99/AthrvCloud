//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <string.h>

#define MEM_SIZE 1024

void printCPUUsage() {
    long double percentage;
    FILE* file;
    char line[MEM_SIZE], cpu[MEM_SIZE];
    double user, nice, system, idle, iowait, irq, softirq;
    double totalCPUUsageTime = 0;
    double idleCPUUsageTime = 0;

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        return;
    }

    fgets(line, MEM_SIZE, file);
    sscanf(line, "%s %Lf %Lf %Lf %Lf %Lf %Lf %Lf", cpu, &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    fclose(file);

    totalCPUUsageTime = user + nice + system + idle + iowait + irq + softirq;
    idleCPUUsageTime = idle + iowait;

    percentage = (100.0 * (totalCPUUsageTime - idleCPUUsageTime) / totalCPUUsageTime);

    printf("CPU Usage: %.2Lf%%\n", percentage);
}

int main() {
    printf("Starting CPU Usage Monitor...\n");

    while (1) {
        printCPUUsage();
        sleep(1);
    }

    return 0;
}