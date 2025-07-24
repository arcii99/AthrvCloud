//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define NUM_WIFI_NETWORKS 10

int main() {
    // Seed a random number generator with the current time
    srand((unsigned int) time(NULL));

    // Declare variables for Wi-Fi signal strengths and network names
    int signalStrengths[NUM_WIFI_NETWORKS];
    char networkNames[NUM_WIFI_NETWORKS][25];

    // Generate random Wi-Fi network names and signal strengths
    for (int i = 0; i < NUM_WIFI_NETWORKS; i++) {
        int randomStrength = rand() % MAX_SIGNAL_STRENGTH;
        sprintf(networkNames[i], "Network %d", i+1);
        signalStrengths[i] = randomStrength;
    }

    // Print out all Wi-Fi network names and signal strengths
    printf("Wi-Fi Networks:\n");
    for (int i = 0; i < NUM_WIFI_NETWORKS; i++) {
        printf("%s\t\tSignal Strength: %d\n", networkNames[i], signalStrengths[i]);
    }

    // Calculate the average signal strength
    int totalStrength = 0;
    for (int i = 0; i < NUM_WIFI_NETWORKS; i++) {
        totalStrength += signalStrengths[i];
    }
    int averageStrength = totalStrength / NUM_WIFI_NETWORKS;

    // Print out the average signal strength
    printf("\n\nAverage Signal Strength: %d\n", averageStrength);

    return 0;
}