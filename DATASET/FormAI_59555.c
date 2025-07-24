//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESS_NAME 50
#define MAX_RAM_USAGE 10000.0 // in MB
#define READ_PROCESS_INTERVAL 2 // in seconds

void readProcessInfo(char *processName, float *ramUsage) {
    // generate random RAM usage between 0 and MAX_RAM_USAGE for example purposes
    *ramUsage = ((float)rand()/(float)(RAND_MAX)) * MAX_RAM_USAGE;
}

void updateRAMUsageStats(float ramUsage, float *maxRAMUsage, float *avgRAMUsage, int *numSamples) {
    // calculate running average
    *avgRAMUsage += (ramUsage - *avgRAMUsage) / ++(*numSamples);
    
    // update max usage
    if (ramUsage > *maxRAMUsage) {
        *maxRAMUsage = ramUsage;
    }
}

int main() {
    char processName[MAX_PROCESS_NAME];
    float ramUsage, maxRAMUsage = 0.0, avgRAMUsage = 0.0;
    int numSamples = 0, i = 0;
    
    // seed random number generator with current time
    srand(time(NULL));
    
    printf("Monitoring RAM usage...\n");
    
    // continuously read process info and update stats
    while (1) {
        readProcessInfo(processName, &ramUsage);
        updateRAMUsageStats(ramUsage, &maxRAMUsage, &avgRAMUsage, &numSamples);
        
        printf("Sample %d: %s RAM usage = %.2f MB\n", ++i, processName, ramUsage);
        printf("Running average RAM usage: %.2f MB\n", avgRAMUsage);
        printf("Max RAM usage: %.2f MB\n\n", maxRAMUsage);
        
        sleep(READ_PROCESS_INTERVAL); // wait for next reading
    }
    
    return 0;
}