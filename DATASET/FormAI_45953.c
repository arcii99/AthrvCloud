//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main() {
    int cpuInfo;
    char cpuInfobuf[1024];
    float cpuIdleProcTick1, cpuIdleProcTick2, cpuTotalProcTick1, cpuTotalProcTick2, cpuIdlePercent, cpuUsagePercent;
    cpuInfo = open("/proc/stat", O_RDONLY);
    read(cpuInfo, cpuInfobuf, 1024);
    sscanf(cpuInfobuf, "cpu %f %f %f %f", &cpuIdleProcTick1, &cpuTotalProcTick1, &cpuIdlePercent, &cpuUsagePercent);
    close(cpuInfo);
    while(1) {
        cpuInfo = open("/proc/stat", O_RDONLY);
        read(cpuInfo, cpuInfobuf, 1024);
        sscanf(cpuInfobuf, "cpu %f %f %f %f", &cpuIdleProcTick2, &cpuTotalProcTick2, &cpuIdlePercent, &cpuUsagePercent);
        close(cpuInfo);
        float cpuTotalDiff = cpuTotalProcTick2 - cpuTotalProcTick1;
        float cpuIdleDiff = cpuIdleProcTick2 - cpuIdleProcTick1;
        float cpuUsageDiff = cpuTotalDiff - cpuIdleDiff;
        float cpuIdlePercent = (cpuIdleDiff/cpuTotalDiff) * 100;
        float cpuUsagePercent = 100 - cpuIdlePercent;
        printf("CPU Usage is: %.2f %%\n", cpuUsagePercent);
        printf("CPU Idle is: %.2f %%\n", cpuIdlePercent);
        cpuIdleProcTick1 = cpuIdleProcTick2;
        cpuTotalProcTick1 = cpuTotalProcTick2;
        sleep(1);
    }
    return 0;
}