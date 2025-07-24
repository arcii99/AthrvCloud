//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getRAMUsage() {
    FILE *file = fopen("/proc/meminfo", "r");
    char line[256];
    int totalMem, freeMem, usedMem;
    totalMem = freeMem = usedMem = 0;
    while(fgets(line, sizeof(line), file)) {
        if(sscanf(line, "MemTotal: %d kB", &totalMem) == 1) { }
        else if(sscanf(line, "MemFree: %d kB", &freeMem) == 1) { }
    }
    fclose(file);
    usedMem = totalMem - freeMem;
    return usedMem;
}

int main() {
    printf("Welcome to the RAM usage monitor program!\n");
    printf("This program will print the current RAM usage of your system.\n");
    printf("Press 'q' to quit at any time.\n\n");

    char userInput[20];
    int ramUsed = 0;
    while(1) {
        ramUsed = getRAMUsage();
        printf("Current RAM usage: %d kB\n", ramUsed);
        printf("Press any key to refresh the usage or press 'q' to quit.\n");

        fgets(userInput, 20, stdin);
        if(userInput[0] == 'q') {
            break;
        }
    }

    printf("Thank you for using the RAM usage monitor program!\n");
    return 0;
}