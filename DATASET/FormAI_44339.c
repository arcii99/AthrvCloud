//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
// Unique C RAM Usage Monitor

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    FILE *fp = fopen("/proc/meminfo","r"); // Opening the meminfo file
    if(fp == NULL) // Checking if file is opened successfully
        exit(EXIT_FAILURE);
    
    long totalRAM, freeRAM;
    char buf[100];
    
    // Reading the meminfo file
    while(fgets(buf, 100, fp) != NULL) 
    {
        if(sscanf(buf, "MemTotal: %ld", &totalRAM) == 1)
            printf("Total RAM: %ld kB\n", totalRAM);
        if(sscanf(buf, "MemFree: %ld", &freeRAM) == 1)
            printf("Free RAM: %ld kB\n", freeRAM);
    }
    
    fclose(fp); // Closing the meminfo file
    
    // Calculating the RAM usage percentage
    int RAMUsage = 100 - (freeRAM * 100 / totalRAM);
    printf("RAM Usage: %d%%\n", RAMUsage);

    return 0; // End of the program
}