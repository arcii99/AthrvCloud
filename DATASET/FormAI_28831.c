//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int generateSignalStrength() {
    return rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    int signalStrength = generateSignalStrength();
    printf("Signal strength: %d\n", signalStrength);

    if (signalStrength > 80) {
        printf("Signal strength is excellent.\n");
    } else if (signalStrength > 60) {
        printf("Signal strength is good.\n");
    } else if (signalStrength > 40) {
        printf("Signal strength is fair.\n");
    } else {
        printf("Signal strength is poor.\n");
    }

    return 0;
}