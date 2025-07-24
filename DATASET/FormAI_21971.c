//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Constants for signal strength calculation
#define REFERENCE_DISTANCE 1
#define REFERENCE_SIGNAL_STRENGTH -30
#define SIGNAL_DECAY_EXPONENT 2

// Function to calculate signal strength for given distance
double calculateSignalStrength(double distance) {
    return REFERENCE_SIGNAL_STRENGTH - (10 * SIGNAL_DECAY_EXPONENT * log10(distance / REFERENCE_DISTANCE));
}

int main() {
    double distance;
    printf("Enter distance from WiFi router in meters: ");
    scanf("%lf", &distance);

    double signalStrength = calculateSignalStrength(distance);
    printf("Signal strength at %lf meters from router: %lf dBm\n", distance, signalStrength);

    return 0;
}