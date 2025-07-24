//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIGNAL 100

// Function to calculate signal strength
int calculateSignalStrength(int signalValue) {
    return (int)(10 * log10((double) signalValue / MAX_SIGNAL));
}

int main() {
    int signalValue, signalStrength;

    // Prompt user to enter signal value
    printf("Enter the signal value (0-100): ");
    scanf("%d", &signalValue);

    // Check input validity
    if(signalValue < 0 || signalValue > 100) {
        printf("Invalid signal value entered!\n");
        return 0;
    }

    // Calculate signal strength
    signalStrength = calculateSignalStrength(signalValue);

    // Print the signal strength
    printf("Signal Strength: %d dBm\n", signalStrength);

    // Determine the quality of the signal based on signal strength
    if(signalStrength >= -50) {
        printf("Excellent signal quality!");
    } else if(signalStrength >= -60) {
        printf("Good signal quality.");
    } else if(signalStrength >= -70) {
        printf("Average signal quality.");
    } else if(signalStrength >= -80) {
        printf("Poor signal quality.");
    } else {
        printf("Very poor signal quality!");
    }

    return 0;
}