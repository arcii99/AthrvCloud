//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main()
{
    char str[MAX_SIZE];
    bool isInRange = false;
    int signalStrength;

    // Input signal strength
    printf("Enter signal strength: ");
    fgets(str, MAX_SIZE, stdin);
    signalStrength = atoi(str);

    // Check if signal strength is within range
    if (signalStrength >= -70 && signalStrength <= -30)
    {
        isInRange = true;
    }

    // Output signal strength and range status
    printf("Signal Strength: %d dBm\n", signalStrength);
    if (isInRange)
    {
        printf("Signal strength is within range.\n");
    }
    else
    {
        printf("Signal strength is out of range.\n");
    }

    return 0;
}