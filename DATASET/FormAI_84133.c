//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
    while(1) {
        struct sysinfo memInfo;
        sysinfo (&memInfo);
        long long totalRAM = (long long)memInfo.totalram * memInfo.mem_unit / 1024;
        long long freeRAM = (long long)memInfo.freeram * memInfo.mem_unit / 1024;
        long long usedRAM = totalRAM - freeRAM;
        double usedPercentage = (double)usedRAM / totalRAM * 100;

        printf("Total RAM: %lldKB\tFree RAM: %lldKB\tUsed RAM: %lldKB\tUsed Percentage: %.2f%%\n", totalRAM, freeRAM, usedRAM, usedPercentage);

        sleep(1);
    }

    return 0;
}