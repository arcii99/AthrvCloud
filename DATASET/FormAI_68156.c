//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Define Constants */
#define SIGNAL_LEVELS 100
#define MAX_SIGNAL_STRENGTH 200
#define MIN_SIGNAL_STRENGTH 0

/* Function to calculate signal strength level */
int calcSignalStrengthLevel(int signalStrength) {
    int signalLevel = SIGNAL_LEVELS * (signalStrength - MIN_SIGNAL_STRENGTH) / (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH);
    return signalLevel;
}

/* Main function */
int main() {
    /* Initialize variables */
    int signalStrength, signalLevel, i, j, k, maxSignalLevelCount, maxSignalLevels[SIGNAL_LEVELS];
    int signalLevelCounts[SIGNAL_LEVELS];
    double meanSignalStrength = 0, varianceSignalStrength = 0, standardDeviationSignalStrength = 0;

    /* Initialize signalStrengthCounts array to zero */
    for(i = 0; i < SIGNAL_LEVELS; i++) {
        signalLevelCounts[i] = 0;
    }

    /* Read signal strengths from user */
    printf("Enter the signal strengths (enter -999 to stop):\n");
    i = 0;
    while(1) {
        scanf("%d", &signalStrength);
        if(signalStrength == -999) {
            break;
        }
        signalLevel = calcSignalStrengthLevel(signalStrength);
        signalLevelCounts[signalLevel]++;
        meanSignalStrength += signalStrength;
        i++;
    }

    /* Calculate mean signal strength */
    meanSignalStrength /= i;

    /* Calculate variance and standard deviation of signal strength */
    for(j = 0; j < SIGNAL_LEVELS; j++) {
        varianceSignalStrength += pow((j * (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH) / SIGNAL_LEVELS) - meanSignalStrength, 2) * signalLevelCounts[j];
    }
    varianceSignalStrength /= i;
    standardDeviationSignalStrength = sqrt(varianceSignalStrength);

    /* Find maximum signal levels */
    maxSignalLevelCount = 0;
    for(k = 0; k < SIGNAL_LEVELS; k++) {
        if(signalLevelCounts[k] > maxSignalLevelCount) {
            maxSignalLevelCount = signalLevelCounts[k];
        }
    }

    /* Display histogram */
    printf("\nSignal Strength Histogram:\n");
    for(k = 0; k < SIGNAL_LEVELS; k++) {
        printf("%3d - %3d: ", k * (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH) / SIGNAL_LEVELS, (k + 1) * (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH) / SIGNAL_LEVELS - 1);
        for(j = 0; j < signalLevelCounts[k]; j++) {
            printf("*");
        }
        printf("\n");
        if(signalLevelCounts[k] == maxSignalLevelCount) {
            maxSignalLevels[k] = 1;
        }
        else {
            maxSignalLevels[k] = 0;
        }
    }

    /* Display mean and standard deviation */
    printf("\nMean signal strength: %.2f\n", meanSignalStrength);
    printf("Standard deviation of signal strength: %.2f\n", standardDeviationSignalStrength);

    /* Display signal levels with maximum count */
    printf("\nSignal levels with maximum count:\n");
    for(k = 0; k < SIGNAL_LEVELS; k++) {
        if(maxSignalLevels[k] == 1) {
            printf("%3d - %3d\n", k * (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH) / SIGNAL_LEVELS, (k + 1) * (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH) / SIGNAL_LEVELS - 1);
        }
    }

    return 0;
}