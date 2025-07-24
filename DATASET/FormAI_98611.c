//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random signal strength values between -100 and 0
int getSignalStrength() {
    return (rand() % 101) * -1;  // returns a negative integer between -100 and 0 
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare and initialize signal strength arrays for 3 different Wi-Fi networks
    int network1SignalStrength[10] = {0};
    int network2SignalStrength[10] = {0};
    int network3SignalStrength[10] = {0};

    // Get signal strength values for each network and store in arrays
    for (int i = 0; i < 10; i++) {
        network1SignalStrength[i] = getSignalStrength();
        network2SignalStrength[i] = getSignalStrength();
        network3SignalStrength[i] = getSignalStrength();
    }

    // Display the signal strength values for each network
    printf("\nSignal Strength Values:\n");
    printf("------------------------\n");
    printf("Network 1:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", network1SignalStrength[i]);
    }
    printf("\n");

    printf("Network 2:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", network2SignalStrength[i]);
    }
    printf("\n");

    printf("Network 3:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", network3SignalStrength[i]);
    }
    printf("\n");

    // Calculate average signal strength for each network
    float network1AvgStrength = 0.0, network2AvgStrength = 0.0, network3AvgStrength = 0.0;
    for (int i = 0; i < 10; i++) {
        network1AvgStrength += network1SignalStrength[i];
        network2AvgStrength += network2SignalStrength[i];
        network3AvgStrength += network3SignalStrength[i];
    }
    network1AvgStrength /= 10;
    network2AvgStrength /= 10;
    network3AvgStrength /= 10;

    // Display the average signal strength for each network
    printf("\nAverage Signal Strength:\n");
    printf("------------------------\n");
    printf("Network 1: %.1f\n", network1AvgStrength);
    printf("Network 2: %.1f\n", network2AvgStrength);
    printf("Network 3: %.1f\n", network3AvgStrength);

    // Determine which network has the highest average signal strength and display the result
    float maxAvgStrength = network1AvgStrength;
    int maxNetwork = 1;
    if (network2AvgStrength > maxAvgStrength) {
        maxAvgStrength = network2AvgStrength;
        maxNetwork = 2;
    }
    if (network3AvgStrength > maxAvgStrength) {
        maxAvgStrength = network3AvgStrength;
        maxNetwork = 3;
    }
    printf("\nNetwork %d has the highest average signal strength: %.1f\n", maxNetwork, maxAvgStrength);

    return 0;
}