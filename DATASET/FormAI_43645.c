//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* file;
    char path[100];
    char line[256];
    int totalRAM, usedRAM, freeRAM;
    float ramUsage;

    file = fopen("/proc/meminfo", "r");

    if (file == NULL) {
        printf("Error: couldn't open the file.");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %d kB", &totalRAM) == 1) {
            // Got the total RAM size
        }
        else if (sscanf(line, "MemFree: %d kB", &freeRAM) == 1) {
            // Got the amount of free RAM
        }
    }

    fclose(file);

    usedRAM = totalRAM - freeRAM;
    ramUsage = (float)usedRAM / (float)totalRAM * 100;

    printf("Total RAM: %d kB\n", totalRAM);
    printf("Used RAM: %d kB\n", usedRAM);
    printf("Free RAM: %d kB\n", freeRAM);
    printf("RAM Usage: %.2f%%\n", ramUsage);

    return 0;
}