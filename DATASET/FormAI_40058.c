//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize program variables
    int signal_strength = 0;
    char* signal_quality = "";

    // Loop through 10 iterations to simulate data readings
    for (int i = 0; i < 10; i++) {
        // Generate random signal strength between 0 and 100
        signal_strength = rand() % 101;

        // Determine signal quality based on signal strength
        if (signal_strength <= 20) {
            signal_quality = "Poor";
        } else if (signal_strength <= 40) {
            signal_quality = "Fair";
        } else if (signal_strength <= 60) {
            signal_quality = "Good";
        } else if (signal_strength <= 80) {
            signal_quality = "Very Good";
        } else {
            signal_quality = "Excellent";
        }

        // Print out current signal strength and quality
        printf("Signal Strength: %d%%\tSignal Quality: %s\n", signal_strength, signal_quality);
    }

    return 0;
}