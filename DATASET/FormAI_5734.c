//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define MAX_RAM_USAGE 1024

int main()
{
    int ramUsage = 0;
    int maxRamUsage = 0;
    int peakIndex = 0;
    int counter = 0;
    int ramUsageUpdateFrequency = 1;
    int ramUsageSamples[MAX_RAM_USAGE] = {0};
  
    while (1) {
        ramUsage = getCurrentRamUsage();

        if (ramUsage > maxRamUsage) {
            maxRamUsage = ramUsage;
            peakIndex = counter;
        }
      
        ramUsageSamples[counter % MAX_RAM_USAGE] = ramUsage;
      
        // Print ram usage statistics every ramUsageUpdateFrequency iterations
        if ((counter % ramUsageUpdateFrequency) == 0) {
            printf("Current RAM Usage: %dKB\n", ramUsage);
            printf("Max RAM Usage: %dKB (Peak Index: %d)\n", maxRamUsage, peakIndex);
            printf("Average RAM Usage: %dKB\n", getAverageRamUsage(ramUsageSamples));
            printf("Standard Deviation of RAM Usage: %d\n", getStandardDeviation(ramUsageSamples));
        }

        counter++;
        usleep(1000000); // Sleep for 1 second
    }
  
    return 0;
}

int getCurrentRamUsage()
{
    FILE* fp;
    char path[BUFSIZ];
    char line[BUFSIZ];
    int ramUsage = 0;

    sprintf(path, "/proc/%d/status", getpid());

    if ((fp = fopen(path, "r")) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", path);
        return ramUsage;
    }

    while (fgets(line, sizeof(line), fp) != NULL){
        if (strstr(line, "VmRSS")){
            int i = 0;
            while (line[i] < '0' || line[i] > '9')
                i++;
            line[strlen(line) - 3] = '\0';
            ramUsage = atoi(&line[i]);
            break;
        }
    }

    fclose(fp);
    return ramUsage;
}

int getAverageRamUsage(int ramUsageSamples[])
{
    int i, sum = 0;
    for (i = 0; i < MAX_RAM_USAGE; i++) {
        sum += ramUsageSamples[i];
    }
    return sum / MAX_RAM_USAGE;
}

int getStandardDeviation(int ramUsageSamples[])
{
    int i;
    double sum = 0.0, mean;
    for (i = 0; i < MAX_RAM_USAGE; ++i) {
        sum += ramUsageSamples[i];
    }
    mean = sum / MAX_RAM_USAGE;
    sum = 0.0;
    for (i = 0; i < MAX_RAM_USAGE; ++i) {
        sum += pow(ramUsageSamples[i] - mean, 2);
    }
    return (int)sqrt(sum / MAX_RAM_USAGE);
}