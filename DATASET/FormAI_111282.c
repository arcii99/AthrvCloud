//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIGNAL_STRENGTH 100

int analyzeSignalStrength(char* signalStrength);

int main()
{
    char* signalStrength = "70%";
    int strength = analyzeSignalStrength(signalStrength);

    printf("Wi-Fi signal strength: %d%%\n", strength);

    return 0;
}

int analyzeSignalStrength(char* signalStrength)
{
    // remove non-numeric characters from signal strength string
    char* temp = signalStrength;
    while (*temp)
    {
        if (!isdigit(*temp))
        {
            strcpy(temp, temp+1);
        }
        else
        {
            temp++;
        }
    }

    // convert signal strength to integer and scale to range 0-100
    int strength = atoi(signalStrength) * MAX_SIGNAL_STRENGTH / 100;

    return strength;
}