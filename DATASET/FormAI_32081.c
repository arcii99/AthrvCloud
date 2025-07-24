//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>

void analyzeSignalStrength(int signal_strength) {
    if (signal_strength <= 20) {
        printf("Signal strength is very weak.\n");
    } else if (signal_strength <= 40) {
        printf("Signal strength is weak.\n");
    } else if (signal_strength <= 60) {
        printf("Signal strength is moderate.\n");
    } else if (signal_strength <= 80) {
        printf("Signal strength is strong.\n");
    } else {
        printf("Signal strength is very strong.\n");
    }
}

int main() {
    int signal_strength;
    printf("Enter the Wi-Fi signal strength (out of 100): ");
    scanf("%d", &signal_strength);
    analyzeSignalStrength(signal_strength);
    return 0;
}