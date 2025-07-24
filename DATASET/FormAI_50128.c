//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program simulates a Wi-Fi signal strength analyzer */

int main() {
    float signalStrength, distance;
    int bars;

    printf("Enter signal strength (in dBm): ");
    scanf("%f", &signalStrength);

    // Convert signal strength to milliwatts
    float milliwatts = pow(10, signalStrength/10);

    // Calculate distance based on signal propagation model
    distance = pow(milliwatts/20.0, 0.5);

    // Determine number of bars based on distance
    if (distance <= 1) {
        bars = 4;
    }
    else if (distance <= 5) {
        bars = 3;
    }
    else if (distance <= 20) {
        bars = 2;
    }
    else {
        bars = 1;
    }

    printf("Distance: %.2f meters\n", distance);
    printf("Number of bars: %d\n", bars);

    return 0;
}