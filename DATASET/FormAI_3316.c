//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random signal strength values between -100 and 0
int generateRandomSignalStrength() {
    return (rand() % 101) * -1;
}

// function to calculate average signal strength from an array of signal strengths
float calculateAverageSignalStrength(int signalStrengths[], int numOfSignals) {
    float sum = 0;
    for (int i = 0; i < numOfSignals; i++) {
        sum += signalStrengths[i];
    }
    return sum / (float)numOfSignals;
}

int main() {
    srand(time(0)); // seed random number generator with current time
    
    int numOfSignals = 10;
    int signalStrengths[numOfSignals];
    
    // generate random signal strengths for each of the 10 signals
    for (int i = 0; i < numOfSignals; i++) {
        signalStrengths[i] = generateRandomSignalStrength();
    }
    
    // print out each signal strength
    printf("The signal strengths are:\n");
    for (int i = 0; i < numOfSignals; i++) {
        printf("%d\n", signalStrengths[i]);
    }
    
    // calculate and print average signal strength
    float avgSignalStrength = calculateAverageSignalStrength(signalStrengths, numOfSignals);
    printf("\nThe average signal strength is: %.2f\n", avgSignalStrength);
    
    // determine number of signals with signal strength below -80 dBm
    int numOfWeakSignals = 0;
    for (int i = 0; i < numOfSignals; i++) {
        if (signalStrengths[i] < -80)
            numOfWeakSignals++;
    }
    
    // print out number of weak signals
    printf("\nThere are %d signals with a signal strength below -80 dBm.\n", numOfWeakSignals);
    
    return 0;
}