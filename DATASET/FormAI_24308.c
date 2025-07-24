//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: happy
#include <stdio.h>

int main()
{
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");

    int signalStrength[] = {70, 80, 60, 90, 75, 85, 50, 100}; // dummy signal strength values
    int numDevices = sizeof(signalStrength) / sizeof(signalStrength[0]); // calculate number of devices

    printf("Scanning for devices...\n");

    printf("Number of devices found: %d\n", numDevices);

    printf("Analyzing signal strength...\n");

    int sumSignal = 0;
    int maxSignal = 0;

    for (int i = 0; i < numDevices; i++)
    {
        if (signalStrength[i] > maxSignal)
        {
            maxSignal = signalStrength[i];
        }

        sumSignal += signalStrength[i];
    }

    int avgSignal = sumSignal / numDevices;

    printf("Signal Strength Analysis Results:\n");
    printf("------------------------------\n");
    printf("Highest Signal Strength Found: %d\n", maxSignal);
    printf("Average Signal Strength: %d\n", avgSignal);

    if (maxSignal > 90)
    {
        printf("Wow! That's an excellent signal strength!\n");
    }
    else if (maxSignal > 75)
    {
        printf("Nice! Your Wi-Fi signal strength is pretty strong.\n");
    }
    else
    {
        printf("Hmm...Your Wi-Fi signal strength could use some improvement.\n");
    }

    printf("Thank you for using the Wi-Fi Signal Strength Analyzer! Enjoy your internet surfing!\n");

    return 0;
}