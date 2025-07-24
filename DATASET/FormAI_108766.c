//FormAI DATASET v1.0 Category: Digital signal processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if the digital signal is positive or negative
int isPositive(int signal) {
    if (signal < 0) {
        return 0;
    } else {
        return 1;
    }
}

// Function to add noise to the digital signal
int addNoise(int signal, int noiseLevel) {
    srand(time(NULL));
    int noise = rand() % (2 * noiseLevel) - noiseLevel; // Generate random noise within the noise level
    return signal + noise;
}

int main() {
    int signal = 10;
    int noiseLevel = 5;
    int processedSignal;

    printf("Original signal: %d\n", signal);

    if (isPositive(signal)) {
        printf("The digital signal is positive.\n");
    } else {
        printf("The digital signal is negative.\n");
    }

    processedSignal = addNoise(signal, noiseLevel);
    printf("Signal after adding noise: %d\n", processedSignal);

    if (isPositive(processedSignal)) {
        printf("The digital signal is still positive.\n");
    } else {
        printf("Oops! The digital signal is negative now.\n");
    }

    return 0;
}