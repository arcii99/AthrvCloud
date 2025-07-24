//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    while(1) {
        struct sysinfo memInfo;
        sysinfo(&memInfo);

        long long usedRAM = memInfo.totalram - memInfo.freeram;
        long long totalRAM = memInfo.totalram;

        int usedPercentage = (int)((float)usedRAM / totalRAM * 100);

        printf("Used RAM: %lld MB / Total RAM: %lld MB (%d%%)\n", usedRAM / 1024 / 1024, totalRAM / 1024 / 1024, usedPercentage);

        sleep(1);
    }

    return 0;
}