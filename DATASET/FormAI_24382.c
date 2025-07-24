//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

void printUsage(double memTotal, double memFree, double memUsed) {
    printf("\n\n*** HAPPY RAM USAGE MONITOR ***\n");
    printf("Total Memory:\t\t%.2lf GB\n", memTotal);
    printf("Free Memory:\t\t%.2lf GB\n", memFree);
    printf("Used Memory:\t\t%.2lf GB\n", memUsed);
    printf("*********************************\n\n");
}

int main(int argc, char* argv[]) {
    while (1) {
        struct sysinfo sys_info;
        sysinfo(&sys_info);
        double memTotal = (double)sys_info.totalram / (1024 * 1024 * 1024);
        double memFree = (double)sys_info.freeram / (1024 * 1024 * 1024);
        double memUsed = memTotal - memFree;
        printUsage(memTotal, memFree, memUsed);
        sleep(2);
    }
    return 0;
}