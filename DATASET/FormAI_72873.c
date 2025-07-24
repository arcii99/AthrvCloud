//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

// Function to calculate RAM usage
void getRAMUsage(int* totalRAM, int* usedRAM) {
    struct sysinfo si;
    sysinfo(&si);
    *totalRAM = (int)si.totalram / (1024*1024);
    *usedRAM = (int)(si.totalram - si.freeram) / (1024*1024);
}

int main() {
    int totalRAM, usedRAM;
    while (1) {
        getRAMUsage(&totalRAM, &usedRAM);
        printf("Total RAM: %d MB | Used RAM: %d MB\n", totalRAM, usedRAM);
        sleep(5);
    }
    return 0;
}