//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIGNAL_INTERVAL 100
#define SIGNAL_THRESHOLD 50

typedef struct Signal {
    int strength; // signal strength value from 0-100
    bool isInRange; // flag indicating if signal is within range
} Signal;

void printSignalStrength(int signalStrength) {
    printf("Signal strength: %d%%\n", signalStrength);
}

void analyzeSignal(Signal* signal) {
    if (signal->strength >= SIGNAL_THRESHOLD) {
        signal->isInRange = true;
    } else {
        signal->isInRange = false;
    }
}

void printSignalData(Signal* signals, int interval) {
    int i;
    for (i = 0; i < interval; i++) {
        printf("Signal %d: ", i);
        printSignalStrength(signals[i].strength);
        printf("Is in range: %s\n", signals[i].isInRange ? "Yes" : "No");
    }
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("============================\n\n");

    Signal signals[MAX_SIGNAL_INTERVAL];
    int interval = 0;

    char input[10];
    do {
        printf("Enter signal strength (0-100), or 'stop' to finish: ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "stop\n") != 0) {
            int strength = atoi(input);
            if (strength < 0 || strength > 100) {
                printf("Invalid input, please enter a number between 0 and 100.\n");
            } else {
                signals[interval].strength = strength;
                analyzeSignal(&signals[interval]);
                interval++;
            }
        }
    } while (strcmp(input, "stop\n") != 0 && interval < MAX_SIGNAL_INTERVAL);

    printf("\n");

    if (interval == 0) {
        printf("No signals recorded.");
    } else {
        printSignalData(signals, interval);
    }

    return 0;
}