//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define INTERVAL 1

int main()
{
    struct sysinfo memInfo;
    long long totalPhysMem = 0;
    long long freePhysMem = 0;
    long long usedPhysMem = 0;
    double memUsage = 0.0;

    while (1) {
        sysinfo(&memInfo);
        totalPhysMem = memInfo.totalram;
        freePhysMem = memInfo.freeram;
        usedPhysMem = totalPhysMem - freePhysMem;
        memUsage = (double)usedPhysMem / (double)totalPhysMem * 100.0;

        printf("Total Memory: %lld MB, Free Memory: %lld MB, Used Memory: %lld MB, Memory Usage: %.2f%%\n",
            totalPhysMem / 1024 / 1024, freePhysMem / 1024 / 1024, usedPhysMem / 1024 / 1024, memUsage);

        sleep(INTERVAL);
    }

    return 0;
}