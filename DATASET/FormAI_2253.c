//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Calculates the signal strength in dBm
float calcSignalStrength(int rssi) {
    return (-10*log10(abs(rssi) + 1));
}

// Main function
int main() {
    int rssi; // Received Signal Strength Indicator
    float signalStrength; //Signal strength in dBm

    printf("Enter RSSI (Received Signal Strength Indicator in dBm): ");
    scanf("%d", &rssi);

    // Calculate the signal strength in dBm
    signalStrength = calcSignalStrength(rssi);

    printf("Signal Strength: %.2f dBm\n", signalStrength);

    return 0;
}