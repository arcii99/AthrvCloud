//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates random signal strength for demonstration purposes
int generateSignalStrength() {
    return rand() % 101;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    printf("Wi-Fi Signal Strength Analyzer\n");

    while(1) { // Loop indefinitely
        int signalStrength = generateSignalStrength();

        printf("Signal Strength: %d%% ", signalStrength);

        if(signalStrength > 70) {
            printf("Excellent Signal\n");
        } else if(signalStrength > 50) {
            printf("Good Signal\n");
        } else if(signalStrength > 30) {
            printf("Fair Signal\n");
        } else {
            printf("Poor Signal\n");
        }

        sleep(1); // Wait for 1 second before generating next sample for simulation purposes
    }

    return 0;
}