//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
#include <stdio.h>

// function to calculate signal strength
double calculateSignalStrength(int signal_power, int noise_power) {
    return 10.0 * log10((signal_power * 1.0) / noise_power);
}

int main() {
    // array to store the signal and noise power levels
    int signal_power[5] = {20, 22, 18, 24, 23};
    int noise_power[5] = {5, 4, 8, 3, 6};

    // loop through the array and calculate signal strength for each point
    for (int i=0; i<5; i++) {
        double signal_strength = calculateSignalStrength(signal_power[i], noise_power[i]);
        printf("Signal strength at point %d: %.2f dBm\n", i+1, signal_strength);
    }

    return 0;
}