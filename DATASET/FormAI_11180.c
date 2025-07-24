//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // generate random signal strength values between 0 and 100
    srand(time(NULL));
    int signalStrength[10];
    for (int i = 0; i < 10; i++) {
        signalStrength[i] = rand() % 101;
    }

    // print out the signal strength values
    printf("Signal Strength Values: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", signalStrength[i]);
    }
    printf("\n");

    // calculate the average signal strength
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += signalStrength[i];
    }
    float average = (float) sum / 10;

    // print out the average signal strength
    printf("Average Signal Strength: %.2f\n", average);

    // calculate and print out the number of weak signals (less than 50)
    int numWeakSignals = 0;
    for (int i = 0; i < 10; i++) {
        if (signalStrength[i] < 50) {
            numWeakSignals++;
        }
    }
    printf("Number of Weak Signals: %d\n", numWeakSignals);

    // calculate and print out the number of strong signals (greater than or equal to 80)
    int numStrongSignals = 0;
    for (int i = 0; i < 10; i++) {
        if (signalStrength[i] >= 80) {
            numStrongSignals++;
        }
    }
    printf("Number of Strong Signals: %d\n", numStrongSignals);

    return 0;
}