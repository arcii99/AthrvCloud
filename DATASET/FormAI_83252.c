//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MEMORY_THRESHOLD 70

double getMemUsage() {
    struct sysinfo memInfo;
    sysinfo (&memInfo);

    double totalMem = (double) memInfo.totalram / (1024 * 1024);
    double freeMem = (double) memInfo.freeram / (1024 * 1024);
    double usedMem = totalMem - freeMem;
    double memUsage = usedMem / totalMem * 100;

    return memUsage;
}

int main() {
    while(1) {
        double memUsage = getMemUsage();
        printf("Memory usage: %.2lf%%\n", memUsage);

        if(memUsage >= MEMORY_THRESHOLD) {
            printf("WARNING: Memory usage is above %d%%\n", MEMORY_THRESHOLD);
            // add your custom code to handle high memory usage
        }

        sleep(5);
    }

    return EXIT_SUCCESS;
}