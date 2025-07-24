//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Alan Touring
// Wi-Fi Signal Strength Analyzer in Alan Touring Style

#include <stdio.h>
#include <stdlib.h>

#define MIN_SIGNAL_STRENGTH 0
#define MAX_SIGNAL_STRENGTH 100

int main() {
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");

    int currentSignalStrength = 0;

    // loop until user enters valid signal strength
    while (currentSignalStrength < MIN_SIGNAL_STRENGTH || currentSignalStrength > MAX_SIGNAL_STRENGTH) {
        printf("Please enter the current Wi-Fi signal strength (between 0-100): ");
        scanf("%d", &currentSignalStrength);

        // if user enters invalid signal strength, ask again
        if (currentSignalStrength < MIN_SIGNAL_STRENGTH || currentSignalStrength > MAX_SIGNAL_STRENGTH) {
            printf("Invalid signal strength! Please enter again.\n");
        }
    }

    // based on user input, determine signal strength level
    if (currentSignalStrength >= 0 && currentSignalStrength < 30) {
        printf("Signal strength is Poor.\n");
    } else if (currentSignalStrength >= 30 && currentSignalStrength < 50) {
        printf("Signal strength is Fair.\n");
    } else if (currentSignalStrength >= 50 && currentSignalStrength < 70) {
        printf("Signal strength is Good.\n");
    } else if (currentSignalStrength >= 70 && currentSignalStrength <= 100) {
        printf("Signal strength is Excellent.\n");
    } 

    printf("Thank you for using Wi-Fi Signal Strength Analyzer!\n");
    return 0;
}