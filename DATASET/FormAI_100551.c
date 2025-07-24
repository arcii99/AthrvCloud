//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(){
    for(;;){
        struct sysinfo memInfo;
        sysinfo (&memInfo);
        long long totalRAM = (long long)memInfo.totalram * memInfo.mem_unit;
        long long freeRAM = (long long)memInfo.freeram * memInfo.mem_unit;
        long long usedRAM = totalRAM - freeRAM;
        float usedPercentage = (float)usedRAM / (float)totalRAM * 100;

        printf("Total RAM: %lld Bytes\n", totalRAM);
        printf("Used RAM: %lld Bytes\n", usedRAM);
        printf("Free RAM: %lld Bytes\n", freeRAM);
        printf("RAM Usage: %.2f%%\n", usedPercentage);

        sleep(1);
        system("clear");
    }
    return 0;
}