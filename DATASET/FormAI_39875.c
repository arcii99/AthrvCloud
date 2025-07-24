//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define ONE_MB 1048576

int main()
{    
    struct sysinfo memInfo;
    long long totalPhysMem;
    long long freePhysMem;
    long long usedPhysMem;

    while(1) {
        sysinfo (&memInfo);
        totalPhysMem = memInfo.totalram / ONE_MB;
        freePhysMem = memInfo.freeram / ONE_MB;
        usedPhysMem = (memInfo.totalram - memInfo.freeram) / ONE_MB;

        printf("Total Memory: %lld MB\n", totalPhysMem);
        printf("Memory Used: %lld MB\n", usedPhysMem);
        printf("Memory Free: %lld MB\n", freePhysMem);

        sleep(1); // waits for 1 second
        printf("\033[2J"); // clears screen
        printf("\033[H");  // moves cursor to the top-left corner
    }
    
    return 0;
}