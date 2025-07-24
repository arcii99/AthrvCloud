//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <time.h>

void displaySize(long size) {
    if (size < 1024) {
        printf("%ldB", size);
    } else if (size < 1024 * 1024) {
        printf("%.1fKB", size / 1024.0);
    } else if (size < 1024 * 1024 * 1024) {
        printf("%.1fMB", size / 1024.0 / 1024.0);
    } else {
        printf("%.1fGB", size / 1024.0 / 1024.0 / 1024.0);
    }
}

void displayRAMUsage() {
    struct sysinfo info;
    sysinfo(&info);
    long totalRAM = info.totalram * info.mem_unit;
    long freeRAM = info.freeram * info.mem_unit;
    long usedRAM = totalRAM - freeRAM;

    printf("RAM USAGE:\n");
    printf("Total RAM:\t");
    displaySize(totalRAM);
    printf("\nFree RAM:\t");
    displaySize(freeRAM);
    printf("\nUsed RAM:\t");
    displaySize(usedRAM);
    printf("\n");
}

int main() {
    while (1) {
        displayRAMUsage();
        sleep(1);
        system("clear");  // clear console output for better display
    }

    return 0;
}