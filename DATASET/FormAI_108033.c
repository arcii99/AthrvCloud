//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: single-threaded
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int getRandomSignalStrength() {
    return rand() % (MAX_SIGNAL_STRENGTH + 1 - MIN_SIGNAL_STRENGTH) + MIN_SIGNAL_STRENGTH;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Simulate Wi-Fi signal strength measurements for 10 seconds
    time_t startTime = time(NULL);
    int signalStrengths[11];

    for (int i = 0; i <= 10; i++) {
        int signalStrength = getRandomSignalStrength();
        signalStrengths[i] = signalStrength;
        printf("%d seconds: %d%%\n", i, signalStrength);
        sleep(1);
    }

    // Calculate average signal strength
    int sum = 0;
    for (int i = 0; i < 11; i++) {
        sum += signalStrengths[i];
    }
    int averageSignalStrength = sum / 11;

    // Determine signal quality based on average signal strength
    char* signalQuality;
    if (averageSignalStrength < 20) {
        signalQuality = "Poor";
    } else if (averageSignalStrength < 40) {
        signalQuality = "Fair";
    } else if (averageSignalStrength < 60) {
        signalQuality = "Good";
    } else {
        signalQuality = "Excellent";
    }

    // Print final result
    printf("Wi-Fi Signal Quality: %s (%d%%)\n", signalQuality, averageSignalStrength);

    return 0;
}