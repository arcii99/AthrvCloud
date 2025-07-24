//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the Wi-Fi Signal Strength
float getSignalStrength(int txPower, int rssi) {
    if (rssi == 0) {
        return -100.0;
    }
    float ratio = rssi * 1.0 / txPower;
    if (ratio < 1.0) {
        return pow(ratio, 10);
    }
    else {
        return (0.89976) * pow(ratio, 7.7095) + 0.111;
    }
}

int main() {
    int txPower, rssi;
    printf("Enter the TX Power: ");
    scanf("%d", &txPower);
    printf("Enter the RSSI: ");
    scanf("%d", &rssi);
    float signalStrength = getSignalStrength(txPower, rssi);
    printf("Signal Strength: %.2f dBm\n", signalStrength);
    return 0;
}