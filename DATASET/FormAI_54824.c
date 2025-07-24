//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signalStrength(int strength);

int main() {
    printf("Please enter WiFi signal strength (in percentage): ");
    int strength;
    scanf("%d", &strength);
    if (strength < 0 || strength > 100) {
        printf("Invalid input! Please enter a number between 0 and 100");
        exit(0);
    }
    signalStrength(strength);
    return 0;
}

void signalStrength(int strength) {
    if (strength <= 20) {
        printf("Signal strength is weak!\n");
    } else if (strength <= 50) {
        printf("Signal strength is moderate.\n");
        sleep(1);
        signalStrength(strength - 10);
    } else if (strength <= 80) {
        printf("Signal strength is good.\n");
        sleep(1);
        signalStrength(strength - 10);
    } else {
        printf("Signal strength is excellent!\n");
    }
}