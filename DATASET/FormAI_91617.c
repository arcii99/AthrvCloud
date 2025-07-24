//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main() {
    int signalStrength;
    bool isInRange;

    printf("Enter the signal strength (0-100): ");
    scanf("%d", &signalStrength);

    if (signalStrength > MAX_SIGNAL_STRENGTH || signalStrength < MIN_SIGNAL_STRENGTH) {
        printf("Invalid signal strength entered. Exiting...\n");
        return 0;
    }

    printf("Signal strength entered: %d\n", signalStrength);

    if (signalStrength >= 70) {
        printf("The signal strength is excellent.\n");
    } else if (signalStrength >= 50) {
        printf("The signal strength is good.\n");
    } else if (signalStrength >= 30) {
        printf("The signal strength is fair.\n");
    } else {
        printf("The signal strength is poor.\n");
    }

    isInRange = signalStrength >= 60 && signalStrength <= 80;

    if (isInRange) {
        printf("The signal is within range.\n");
    } else {
        printf("The signal is not within range.\n");
    }

    return 0;
}