//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: inquisitive
// Welcome to the Wi-Fi Signal Strength Analyzer!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate distance from signal strength
double calculateDistance(int signalStrength, int frequency) {
    double exp = (27.55 - (20 * log10(frequency)) + fabs(signalStrength)) / 20.0;
    return pow(10.0, exp);
}

int main() {
    // Prompt user for signal strength and frequency
    int signalStrength;
    printf("Enter the signal strength in dBm (decibel-milliwatts): ");
    scanf("%d", &signalStrength);
    if (signalStrength < -100 || signalStrength > 0) {
        printf("Signal strength must be between -100 and 0 dBm.\n");
        exit(1);
    }
    int frequency;
    printf("Enter the frequency in MHz (megahertz): ");
    scanf("%d", &frequency);

    // Calculate distance from signal strength
    double distance = calculateDistance(signalStrength, frequency);

    // Display result to user
    printf("At a signal strength of %d dBm and a frequency of %d MHz, the distance to the Wi-Fi access point is %.2f meters.\n", signalStrength, frequency, distance);

    return 0;
}