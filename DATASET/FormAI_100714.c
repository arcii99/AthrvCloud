//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define STRONG_SIGNAL_THRESHOLD 80
#define WEAK_SIGNAL_THRESHOLD 30

bool isStrongSignal(int signalStrength) {
    return signalStrength >= STRONG_SIGNAL_THRESHOLD;
}

bool isWeakSignal(int signalStrength) {
    return signalStrength <= WEAK_SIGNAL_THRESHOLD;
}

void printSignalStrength(int signalStrength) {
    if (isStrongSignal(signalStrength)) {
        printf("Strong Signal: %d\n", signalStrength);
    } else if (isWeakSignal(signalStrength)) {
        printf("Weak Signal: %d\n", signalStrength);
    } else {
        printf("Normal Signal: %d\n", signalStrength);
    }
}

int main() {
    srand(time(NULL));
    int signalStrength = 0;
    printf("Starting Wi-Fi analyzer...\n");
    while (true) {
        signalStrength = rand() % 100;
        printSignalStrength(signalStrength);
        sleep(1);
    }
    return 0;
}