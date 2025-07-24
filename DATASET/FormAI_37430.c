//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main() {
    int signalStrength = rand() % (MAX_SIGNAL_STRENGTH + 1 - MIN_SIGNAL_STRENGTH) + MIN_SIGNAL_STRENGTH;

    printf("Analyzing Wi-Fi Signal Strength:\n");

    if (signalStrength < 20)
        printf("Terrible Signal Strength: %d\n", signalStrength);
    else if (signalStrength < 40)
        printf("Poor Signal Strength: %d\n", signalStrength);
    else if (signalStrength < 60)
        printf("Average Signal Strength: %d\n", signalStrength);
    else if (signalStrength < 80)
        printf("Good Signal Strength: %d\n", signalStrength);
    else
        printf("Excellent Signal Strength: %d\n", signalStrength);

    return 0;
}