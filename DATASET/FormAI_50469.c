//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX_VAL 200
#define MIN_VAL -200

void printSignalStrength(int signalStrength) {
    int bars = (signalStrength - MIN_VAL) * 5 / (MAX_VAL - MIN_VAL); //Calculating number of bars
    if (bars > 0) {
        printf("Signal Strength: ");
        for (int i = 0; i < bars; i++) {
            printf("|"); //Printing bars based on signal strength
        }
    }
    else {
        printf("No signal"); //No signal if signal strength is below minimum value
    }
}

int calculateSignalStrength(int rssi, int frequency, int signalNoise) {
    double rss = rssi;
    double freq = frequency;
    double snr = signalNoise;
    double signalPower = pow(10, rss / 10);
    double noisePower = pow(10, snr / 10);
    double bandwidth = 20;
    double signalStrength = 10 * log10(signalPower / (noisePower * bandwidth * 1000));
    return (int)signalStrength; //Calculating signal strength from RSSI, frequency and signal noise
}

int main() {
    int rssi, frequency, signalNoise;
    printf("Enter RSSI value: ");
    scanf("%d", &rssi);
    printf("Enter frequency value: ");
    scanf("%d", &frequency);
    printf("Enter signal noise: ");
    scanf("%d", &signalNoise);
    int signalStrength = calculateSignalStrength(rssi, frequency, signalNoise); //Calculating signal strength
    printf("\n");
    printSignalStrength(signalStrength); //Printing signal strength
    printf("\n\n");
    return 0;
}