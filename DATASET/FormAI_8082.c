//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    //initialize variables
    float totalRAM, freeRAM, usedRAM;
    //get total RAM value
    FILE *meminfo = fopen("/proc/meminfo", "r");
    fscanf(meminfo, "MemTotal: %f", &totalRAM);
    fclose(meminfo);
    //loop to continuously monitor RAM usage
    while (1) {
        //get free RAM value
        meminfo = fopen("/proc/meminfo", "r");
        fscanf(meminfo, "MemFree: %f", &freeRAM);
        fclose(meminfo);
        //calculate used RAM value
        usedRAM = totalRAM - freeRAM;
        //print results
        printf("Total RAM: %f kB\n", totalRAM);
        printf("Used RAM: %f kB\n", usedRAM);
        printf("Free RAM: %f kB\n", freeRAM);
        //sleep for 1 second before checking again
        sleep(1);
    }
    return 0;
}