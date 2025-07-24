//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIGNAL 100  // maximum signal strength

void analyzeSignal(int signalStrength);

int main() {
    int signalStrength;

    // seed the random number generator
    srand(time(NULL));

    // simulate signal strengths ranging from 0 to 100
    for (int i = 0; i < 10; i++) {
        signalStrength = rand() % (MAX_SIGNAL + 1);
        analyzeSignal(signalStrength);
    }
    return 0;
}

void analyzeSignal(int signalStrength) {
    char signalBars[20] = {0};
    int numBars;

    // calculate number of bars based on signal strength
    if (signalStrength >= 90) {
        numBars = 5;
    } else if (signalStrength >= 70) {
        numBars = 4;
    } else if (signalStrength >= 50) {
        numBars = 3;
    } else if (signalStrength >= 30) {
        numBars = 2;
    } else if (signalStrength >= 10) {
        numBars = 1;
    } else {
        numBars = 0;
    }

    // create signal bars string
    for (int i = 0; i < numBars; i++) {
        strcat(signalBars, "|");
    }

    // print signal strength and bars
    printf("Signal Strength: %d%% %s\n", signalStrength, signalBars);
}