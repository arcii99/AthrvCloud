//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate Wi-Fi signal strength
double calculateSignalStrength(double distance, double frequency, double txPower, double nValue) {
    double signalStrength = txPower - (20 * log10(distance) + 20 * log10(frequency) + 20 * log10(1.0 / sqrt(nValue)));
    return signalStrength;
}

int main() {
    double distance, frequency, txPower, nValue;
    double signalStrength;

    // prompt user for input values
    printf("Enter distance from Wi-Fi access point in meters: ");
    scanf("%lf", &distance);

    printf("Enter Wi-Fi frequency in GHz: ");
    scanf("%lf", &frequency);

    printf("Enter transmitter power in dBm: ");
    scanf("%lf", &txPower);

    printf("Enter n-value for the environment: ");
    scanf("%lf", &nValue);

    // calculate signal strength and print result
    signalStrength = calculateSignalStrength(distance, frequency, txPower, nValue);
    printf("Wi-Fi signal strength is: %.2f dBm\n", signalStrength);

    return 0;
}