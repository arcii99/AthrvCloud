//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int signalStrength, signalQuality;
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("Please enter the signal strength (in dBm): ");
    scanf("%d", &signalStrength);

    signalQuality = (int) round((100.0 / 97.0) * (signalStrength + 35.0));
    srand(time(NULL));
    int r = rand() % 10;
    signalQuality += r; // adds a random value to the strength between 0 and 9
    printf("Analyzing signal strength...\n\n");

    if (signalQuality >= 90) {
        printf("Wow, your Wi-Fi signal is excellent! You can stream HD videos without any interruptions!\n");
    } else if (signalQuality >= 80) {
        printf("Great news! Your Wi-Fi signal is good enough to stream your favorite shows without any buffering.\n");
    } else if (signalQuality >= 70) {
        printf("Your Wi-Fi signal is decent. You may experience some buffering while streaming videos.\n");
    } else if (signalQuality >= 60) {
        printf("Your Wi-Fi signal is weak. You may experience a lot of buffering while streaming videos.\n");
    } else {
        printf("Uh-oh. Your Wi-Fi signal is very weak. You may need to move closer to the router or restart your modem.\n");
    }
    return 0;
}