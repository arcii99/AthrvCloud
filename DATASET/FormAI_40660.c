//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int signal_strength[5] = {-60, -70, -80, -90, -100}; // Array containing signal strengths
    int num_signals = sizeof(signal_strength) / sizeof(signal_strength[0]); // Number of signals in array
    int average_strength = 0; // Holds the average signal strength
    bool wifi_connected = false; // Boolean value to indicate if the device is connected to Wi-Fi

    for (int i = 0; i < num_signals; i++) {
        average_strength += signal_strength[i];
    }
    average_strength /= num_signals; // Calculate average signal strength

    if (average_strength >= -70) {
        wifi_connected = true;
    }

    if (wifi_connected) {
        printf("Device is connected to Wi-Fi network\n");
    }
    else {
        printf("Device is not connected to Wi-Fi network\n");
    }

    return 0;
}