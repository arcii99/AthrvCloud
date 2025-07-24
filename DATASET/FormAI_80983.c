//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Alan Touring
#include <stdio.h>

// function to calculate the signal strength based on RSSI
int calculateSignalStrength(int rssi) {
    if (rssi <= -100) {
        return 0;
    } else if (rssi >= -50) {
        return 100;
    } else {
        return 2 * (rssi + 100);
    }
}

// function to print the signal strength in percentage and bars
void printSignalStrength(int signalStrength) {
    int bars = signalStrength / 20;
    printf("Signal Strength: %d%% (", signalStrength);
    for (int i = 0; i < bars; i++) {
        printf("|");
    }
    for (int i = bars; i < 5; i++) {
        printf(" ");
    }
    printf(")\n");
}

// main function
int main() {
    int rssi;
    printf("Enter RSSI reading in dBm: ");
    scanf("%d", &rssi);
    int signalStrength = calculateSignalStrength(rssi);
    printSignalStrength(signalStrength);
    return 0;
}