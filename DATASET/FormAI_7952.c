//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIFI_STRENGTH 100

int getWifiSignalStrength() {
    return (rand() % (MAX_WIFI_STRENGTH + 1));
}

void printSignalStrength(int strength) {
    printf("Signal Strength: ");
    for (int i = 0; i < strength; i++) {
        printf("=");
    }
    printf(">\n\n");
}

void analyzeSignalStrength(int strength, int level) {
    if (level == 0) {
        printf("Initial Signal Strength: %d\n", strength);
        printf("------------------------------------------\n");
        printSignalStrength(strength);
    }
    if (strength <= 10) {
        printf("Signal strength is very weak, please move closer to the router.\n");
    } else if (strength > 10 && strength <= 30) {
        printf("Signal strength is weak, please move closer to the router or try changing the channel.\n");
    } else if (strength > 30 && strength <= 60) {
        printf("Signal strength is good, no need to move closer.\n");
    } else if (strength > 60 && strength <= 80) {
        printf("Signal strength is very good, you are close to the router.\n");
    } else if (strength > 80) {
        printf("You are sitting next to the router, signal strength is excellent!\n");
    }

    if (level < 5) {
        int newStrength = getWifiSignalStrength();
        printf("\nNew Signal Strength: %d\n", newStrength);
        printf("------------------------------------------\n");
        printSignalStrength(newStrength);
        analyzeSignalStrength(newStrength, level + 1);
    } else {
        printf("\nEnd of Signal Strength Analysis.\n");
    }
}

int main() {
    analyzeSignalStrength(getWifiSignalStrength(), 0);
    return 0;
}