//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate signal strength in dBm
double calculateSignalStrength(int dBm, double frequency, double distance) {
    double wavelength = 3e8 / frequency;
    double gain = 1;
    double power = pow(wavelength / (4 * M_PI * distance), 2);
    return 10 * log10(power * gain * 1000) + dBm;
}

int main() {
    int dBm = -65; // Input from Wi-Fi adapter
    double frequency = 2.4e9; // 2.4 GHz frequency
    double distance = 0; // Default distance
    char input[50];

    while (1) {
        printf("Enter distance in meters (0 for exit): ");
        fgets(input, sizeof(input), stdin);
        distance = atof(input);
        
        if (distance == 0) { // Exit if distance is 0
            break;
        }

        double signalStrength = calculateSignalStrength(dBm, frequency, distance);
        printf("Signal strength at distance %.2f meters: %.2f dBm\n\n", distance, signalStrength);
    }

    return 0;
}