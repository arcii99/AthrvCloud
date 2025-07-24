//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

bool isInRange(int signalStrength, int min, int max)
{
    if(signalStrength >= min && signalStrength <= max)
        return true;
    return false;
}

int main()
{
    int signalStrength;
    printf("Enter the signal strength (0-100): ");
    scanf("%d", &signalStrength);

    // Checking different ranges of signal strength
    if(isInRange(signalStrength, 80, 100))
        printf("Excellent Signal Strength\n");
    else if(isInRange(signalStrength, 60, 79))
        printf("Good Signal Strength\n");
    else if(isInRange(signalStrength, 40, 59))
        printf("Average Signal Strength\n");
    else if(isInRange(signalStrength, 20, 39))
        printf("Weak Signal Strength\n");
    else
        printf("Very Weak Signal Strength\n");

    return 0;
}