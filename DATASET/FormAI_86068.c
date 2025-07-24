//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

int main()
{
    struct sysinfo memInfo;
    time_t start, end;
    time(&start);

    while(1) {
        time(&end);
        if(difftime(end, start) > 10) {
            sysinfo(&memInfo);
            long totalRAM = memInfo.totalram / 1024;
            long freeRAM = memInfo.freeram / 1024;
            long usedRAM = totalRAM - freeRAM;
            double usedRAMPercentage = ((double)usedRAM / (double)totalRAM) * 100;

            printf("Total RAM: %ld KB\n", totalRAM);
            printf("Free RAM: %ld KB\n", freeRAM);
            printf("Used RAM: %ld KB\n", usedRAM);
            printf("RAM Usage: %.2f%%\n", usedRAMPercentage);

            time(&start);
        }
    }

    return 0;
}