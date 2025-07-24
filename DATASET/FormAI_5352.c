//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int signalStrength;

    printf("Enter the signal strength between 0 and 100: ");
    scanf("%d", &signalStrength);

    if(signalStrength < 0 || signalStrength > 100)
    {
        printf("Invalid signal strength entered.\n");
        exit(EXIT_FAILURE);
    }

    if(signalStrength < 30)
    {
        printf("Signal strength is low.\n");
    }
    else if(signalStrength < 60)
    {
        printf("Signal strength is average.\n");
    }
    else
    {
        printf("Signal strength is strong.\n");
    }

    return 0;
}