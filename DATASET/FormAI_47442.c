//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int signalStrength = 0;
    int maxStrength = 100;
    int minStrength = 0;
    int attempts = 10;
    int i;

    // Seed random number generator
    srand(time(NULL));

    // Loop to simulate signal readings
    for (i = 1; i <= attempts; i++)
    {
        // Generate random signal strength
        signalStrength = rand() % (maxStrength - minStrength + 1) + minStrength;

        // Analyze signal strength
        if (signalStrength > 80)
        {
            printf("The Wi-Fi signal is excellent! Strength: %d\n", signalStrength);
        }
        else if (signalStrength > 60)
        {
            printf("The Wi-Fi signal is good. Strength: %d\n", signalStrength);
        }
        else if (signalStrength > 40)
        {
            printf("The Wi-Fi signal is fair. Strength: %d\n", signalStrength);
        }
        else
        {
            printf("The Wi-Fi signal is poor. Strength: %d\n", signalStrength);
        }
    }

    return 0;
}