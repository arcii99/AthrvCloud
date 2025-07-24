//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to calculate the signal strength
int calculateSignalStrength(int rssi) {
    int signalStrength = 0;

    if (rssi <= -100) {
        signalStrength = 0;
    } else if (rssi >= -50) {
        signalStrength = 100;
    } else {
        signalStrength = 2 * (rssi + 100);
    }

    return signalStrength;
}

int main() {
    char command[MAX_SIZE];
    int rssi = 0;

    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");

    while (1) {
        printf("Enter the received signal strength (or type 'q' to quit): ");
        fgets(command, MAX_SIZE, stdin);

        if (strcmp(command, "q\n") == 0 || strcmp(command, "Q\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        rssi = atoi(command);
        int signalStrength = calculateSignalStrength(rssi);

        printf("Signal strength: %d%%\n\n", signalStrength);
    }

    return 0;
}