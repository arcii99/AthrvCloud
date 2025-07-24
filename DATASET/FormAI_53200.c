//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void getCpuUsage(char *cpuUsage) {
    FILE *fp;
    char buffer[1024];
    fp = fopen("/proc/stat", "r");
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buffer, "cpu %d %d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    int totalCpuTime = user + nice + system + idle + iowait + irq + softirq + steal;
    static int lastTotalCpuTime = 0;
    static int lastIdleCpuTime = 0;
    if (lastTotalCpuTime != 0) {
        int diffIdleCpuTime = idle - lastIdleCpuTime;
        int diffTotalCpuTime = totalCpuTime - lastTotalCpuTime;
        float cpuPercentage = ((float) (diffTotalCpuTime - diffIdleCpuTime) / diffTotalCpuTime) * 100;
        sprintf(cpuUsage, "%.2f %%", cpuPercentage);
    }
    lastTotalCpuTime = totalCpuTime;
    lastIdleCpuTime = idle;
}

int main() {
    char cpuUsage[10];
    while (1) {
        getCpuUsage(cpuUsage);
        printf("\rCPU Usage: %s", cpuUsage);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}