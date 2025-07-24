//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void analyzerFunction (int signalStrength) {
    printf("Signal strength is: %d\n", signalStrength);
}

int main() {
    int sigStrength = 0;
    srand(time(NULL));

    while (1) {
        sigStrength = rand() % 100;
        analyzerFunction(sigStrength);
        sleep(1);
    }

    return 0;
}