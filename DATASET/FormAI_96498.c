//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void printProgressBar(int progress, int maxProgress);

int main() {
    int prevCpuTotal = 0, prevCpuIdle = 0;
    int currentCpuTotal = 0, currentCpuIdle = 0;
    int cpuUsage = 0;
    char command[50];
    while(1) {
        system("clear"); // clear the console
        FILE *fp = fopen("/proc/stat", "r");
        fscanf(fp, "%*s %d %*d %d %d %*d %*d %*d %*d %*d", 
            &currentCpuIdle, &currentCpuTotal);
        fclose(fp);
        cpuUsage = (currentCpuTotal - prevCpuTotal) - (currentCpuIdle - prevCpuIdle);
        cpuUsage = cpuUsage * 100 / (currentCpuTotal - prevCpuTotal);
        prevCpuTotal = currentCpuTotal;
        prevCpuIdle = currentCpuIdle;
        printProgressBar(cpuUsage, 100);
        sleep(1); // sleep for a second
    }
    return 0;
}

void printProgressBar(int progress, int maxProgress) {
    printf("CPU Usage: %d%%\n[", progress);
    int percentage = progress * 100 / maxProgress;
    int remainingPercentage = 100 - percentage;
    int i;
    for (i = 0; i < percentage / 2; i++) {
        printf("=");
    }
    for (i = 0; i < remainingPercentage / 2; i++) {
        printf(" ");
    }
    printf("]\n");
}