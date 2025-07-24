//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIGNAL_STRENGTH 100

// Function to calculate signal-to-noise ratio
float calculateSNR(int signal_strength, int noise_strength) {
    return (float)signal_strength/noise_strength;
}

// Function to calculate signal strength in dBm
float calculateSignalStrength(int signal_strength) {
    return 10 * log10(signal_strength);
}

// Function to calculate signal quality in percentage
float calculateSignalQuality(int signal_strength) {
    return ((float)signal_strength/MAX_SIGNAL_STRENGTH)*100;
}

int main() {
    int signal_strength;
    int noise_strength;

    // Get input from user
    printf("Enter signal strength (out of 100): ");
    scanf("%d",&signal_strength);
    printf("Enter noise strength (out of 100): ");
    scanf("%d",&noise_strength);

    // Calculate SNR, signal strength and signal quality
    float snr = calculateSNR(signal_strength, noise_strength);
    float signal_strength_dbm = calculateSignalStrength(signal_strength);
    float signal_quality = calculateSignalQuality(signal_strength);

    // Display results
    printf("\nSignal to Noise Ratio: %.2f\n", snr);
    printf("Signal Strength (in dBm): %.2f dBm\n", signal_strength_dbm);
    printf("Signal Quality: %.2f %%\n", signal_quality);

    return 0;
}