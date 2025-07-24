//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_RSSI 100
#define MIN_RSSI 0

void printSignalStrength(int rssi);

int main() {
    int rssi;

    printf("Enter the RSSI value (between 0 to 100): ");
    scanf("%d", &rssi);

    if (rssi < MIN_RSSI || rssi > MAX_RSSI) {
        printf("Error: Invalid RSSI value!");
        exit(0);
    }

    printf("The signal strength is: ");
    printSignalStrength(rssi);

    return 0;
}

void printSignalStrength(int rssi) {
    if (rssi >= 90) {
        printf("Excellent");
    } else if (rssi >= 75) {
        printf("Good");
    } else if (rssi >= 50) {
        printf("Fair");
    } else if (rssi >= 25) {
        printf("Weak");
    } else {
        printf("Very Weak");
    }
}