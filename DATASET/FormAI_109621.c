//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void signalStrengthAnalyzer(int signalStrength);

int main() {

    int signalStrength;

    printf("Enter WiFi signal strength between 1 and 100: ");
    scanf("%d", &signalStrength);

    signalStrengthAnalyzer(signalStrength);

    return 0;
}

void signalStrengthAnalyzer(int signalStrength) {

    if (signalStrength >= 90) {
        printf("Signal strength is excellent!\n");
    } else if (signalStrength >= 70 && signalStrength < 90) {
        printf("Signal strength is good.\n");
    } else if (signalStrength >= 50 && signalStrength < 70) {
        printf("Signal strength is fair.\n");
    } else if (signalStrength < 50 && signalStrength > 0) {
        printf("Signal strength is poor.\n");
    } else if (signalStrength == 0) {
        printf("No signal.\n");
    } else {
        printf("Invalid signal strength.\n");
    }

}