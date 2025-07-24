//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define signal strength constants
#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 30
#define MAX_NOISE_LEVEL 20

// Define a function to generate random signal strengths
int getRandomSignalStrength() {
    return (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
}

int main() {
    printf("WELCOME TO THE WI-FI SIGNAL STRENGTH ANALYZER\n\n");
    printf("Initializing program, please wait...\n\n");

    // Generate random signal strength
    srand(time(NULL));
    int signalStrength = getRandomSignalStrength();

    // Add random noise to signal strength
    int noise = (rand() % (2 * MAX_NOISE_LEVEL + 1)) - MAX_NOISE_LEVEL;
    signalStrength += noise;

    // Check if signal strength is within range
    if (signalStrength >= MIN_SIGNAL_STRENGTH && signalStrength <= MAX_SIGNAL_STRENGTH) {
        printf("Good news! Your Wi-Fi signal strength is within the acceptable range.\n");
    } else if (signalStrength < MIN_SIGNAL_STRENGTH) {
        printf("Uh oh! Your Wi-Fi signal strength is too weak. Please move closer to your router.\n");
    } else {
        printf("Uh oh! Your Wi-Fi signal strength is too strong. Please move further away from your router.\n");
    }

    printf("Signal strength: %d dBm\n", signalStrength);

    return 0;
}