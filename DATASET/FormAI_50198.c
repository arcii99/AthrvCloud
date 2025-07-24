//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    
    int cpuUsage;
    int numOfSamples = 100;
    int samples[numOfSamples];
    int total = 0;
    
    printf("Running CPU Usage Monitor...\n");
    
    for (int i = 0; i < numOfSamples; i++) {
        cpuUsage = rand() % 101;
        samples[i] = cpuUsage;
        total += cpuUsage;
    }
    
    float average = (float) total / (float) numOfSamples;
    
    int minUsage = samples[0];
    int maxUsage = samples[0];
    
    for (int i = 0; i < numOfSamples; i++) {
        if (samples[i] < minUsage) {
            minUsage = samples[i];
        }
        if (samples[i] > maxUsage) {
            maxUsage = samples[i];
        }
    }
    
    printf("CPU Usage Monitor Results:\n");
    printf("Number of samples: %d\n", numOfSamples);
    printf("Average CPU Usage: %.2f%%\n", average);
    printf("Minimum CPU Usage: %d%%\n", minUsage);
    printf("Maximum CPU Usage: %d%%\n", maxUsage);
    
    return 0;
}