//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo memInfo;
    long long totalVirtualMem, usedVirtualMem, totalPhysMem, freePhysMem;

    while (1) {
        sysinfo(&memInfo);

        // calculate the total and free physical memory
        totalPhysMem = memInfo.totalram;
        freePhysMem = memInfo.freeram;
        totalPhysMem *= memInfo.mem_unit;
        freePhysMem *= memInfo.mem_unit;

        // calculate the total and used virtual memory
        totalVirtualMem = memInfo.totalram + memInfo.totalswap;
        totalVirtualMem *= memInfo.mem_unit;
        usedVirtualMem = memInfo.totalram - memInfo.freeram + memInfo.totalswap - memInfo.freeswap;
        usedVirtualMem *= memInfo.mem_unit;

        printf("Total physical memory: %lld bytes\n", totalPhysMem);
        printf("Free physical memory: %lld bytes\n", freePhysMem);
        printf("Total virtual memory: %lld bytes\n", totalVirtualMem);
        printf("Used virtual memory: %lld bytes\n", usedVirtualMem);

        sleep(1); // delay for 1 second
        system("clear"); // clear the console
    }

    return 0;
}