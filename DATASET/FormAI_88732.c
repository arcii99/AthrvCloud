//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkSignalStrength(int signalStrength);

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");

    int signalStrength;
    
    printf("Please enter your Wi-Fi signal strength (out of 100): ");
    scanf("%d", &signalStrength);

    if (checkSignalStrength(signalStrength)) {
        printf("Congratulations, your Wi-Fi signal strength is strong! You can stream your favorite movies and play games seamlessly.\n");
    } else {
        printf("Oh no, your Wi-Fi signal strength is weak! You might experience buffering while watching videos and playing games. Try relocating your Wi-Fi router or contacting your internet service provider.\n");
    }

    return 0;
}

bool checkSignalStrength(int signalStrength) {
    if (signalStrength >= 70) {
        return true;
    } else {
        return false;
    }
}