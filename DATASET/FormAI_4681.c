//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/statvfs.h>

int main()
{
    FILE *mem;
    char buff[100];
    int totalMem, freeMem, usedMem, percentUsed;

    while(1) {
        mem = fopen("/proc/meminfo", "r");
        fgets(buff, 100, mem);
        sscanf(buff, "MemTotal: %d", &totalMem);
        fgets(buff, 100, mem);
        sscanf(buff, "MemFree: %d", &freeMem);
        fclose(mem);

        usedMem = totalMem - freeMem;
        percentUsed = (usedMem * 100) / totalMem;

        printf("\n**********************************\n");
        printf("**** SYSTEM MEMORY USAGE STATS ****\n");
        printf("**********************************\n");
        printf("\nTotal Memory: %d KB\n", totalMem);
        printf("Used Memory: %d KB\n", usedMem);
        printf("Free Memory: %d KB\n", freeMem);
        printf("Memory Usage: %d%%\n", percentUsed);

        // Code to monitor C RAM usage
        struct statvfs fiData;
        statvfs("/", &fiData);
        long long cRam = (long long)fiData.f_frsize * fiData.f_blocks;
        printf("\n******************************\n");
        printf("** C RAM USAGE STATS **\n");
        printf("******************************\n");
        printf("\nTotal C RAM: %lld bytes\n", cRam);
        printf("C RAM Usage: %lld bytes\n", cRam - (long long)fiData.f_bfree * fiData.f_frsize);

        sleep(5);
    }

    return 0;
}