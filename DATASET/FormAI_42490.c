//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(void) {
    struct sysinfo si;
    unsigned long long totalRam, freeRam, usedRam, usedPercentage;
    while(1) {
        if(sysinfo(&si) != 0) {
            printf("Error: Unable to get system information\n");
            exit(EXIT_FAILURE);
        }
        totalRam = si.totalram;
        freeRam = si.freeram;
        usedRam = totalRam - freeRam;
        usedPercentage = (usedRam / (double)totalRam) * 100;
        printf("CPU usage: %llu%%\n", usedPercentage);
        sleep(1);
    }
    return 0;
}