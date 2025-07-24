//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MEMORY_SIZE 1048576 // 1 MB
#define INTERVAL 1 // 1 Second

float toMB(int bytes) {
    return (float) bytes / 1048576.0;
}

void printHeader() {
    printf("%15s%15s%15s\n", "Total Memory", "Free Memory", "RAM Usage");
}

void printProgress(float usage) {
    printf("%15.2fMB%15.2fMB%15.2f%%\n", toMB(MEMORY_SIZE), toMB(MEMORY_SIZE - usage), usage);
}

void showMemoryUsage() {
    int total = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
    int free = sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
    float usage = ((float) (total - free) / (float) total) * 100.0;
    printProgress(usage);
}

int main() {
    printHeader();
    while(1) {
        showMemoryUsage();
        sleep(INTERVAL);
    }
    return 0;
}