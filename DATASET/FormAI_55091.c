//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum size (in bytes) of a Wi-Fi signal
#define MAX_SIGNAL_SIZE 100

// Define the maximum number of Wi-Fi signals to analyze
#define MAX_NUM_SIGNALS 10

// Define the minimum acceptable signal strength in dBm
#define MIN_SIGNAL_STRENGTH -80

// Function to calculate the signal strength in dBm from the RSSI value (in dBm)
double calcSignalStrength(int rssi) {
    return 10 * log10(pow(10, (rssi / 10)) * 1000);
}

int main() {
    int num_signals;
    char signals[MAX_NUM_SIGNALS][MAX_SIGNAL_SIZE];
    int rssi[MAX_NUM_SIGNALS];
    double signal_strength[MAX_NUM_SIGNALS];

    // Get the number of Wi-Fi signals to analyze from the user
    printf("Enter the number of Wi-Fi signals to analyze: ");
    scanf("%d", &num_signals);

    // Get the RSSI values and names of the Wi-Fi signals from the user
    for (int i = 0; i < num_signals; i++) {
        printf("\nEnter the name of Wi-Fi signal #%d: ", (i+1));
        scanf("%s", signals[i]);

        printf("Enter the RSSI value (in dBm) for Wi-Fi signal #%d: ", (i+1));
        scanf("%d", &rssi[i]);

        // Calculate the signal strength in dBm
        signal_strength[i] = calcSignalStrength(rssi[i]);
    }

    // Print out the data for each Wi-Fi signal
    printf("\n\n%-40s  %-10s  %-10s\n", "Name", "RSSI (dBm)", "Strength (dBm)");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < num_signals; i++) {
        printf("%-40s  %-10d  %-10.2lf", signals[i], rssi[i], signal_strength[i]);

        // Check if the signal strength is below the minimum acceptable value
        if (signal_strength[i] < MIN_SIGNAL_STRENGTH) {
            printf("  -- WEAK SIGNAL");
        }

        printf("\n");
    }

    return 0;
}