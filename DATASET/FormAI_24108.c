//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main()
{
    float signal_strength;
    int signal_level;

    printf("Enter the signal strength (0-100): ");
    scanf("%f", &signal_strength);

    if(signal_strength < MIN_SIGNAL_STRENGTH || signal_strength > MAX_SIGNAL_STRENGTH)
    {
        printf("Invalid signal strength! Signal strength should be between 0-100.");
        exit(0);
    }

    signal_level = round(signal_strength/20);

    switch(signal_level)
    {
        case 0:
            printf("Signal strength is very poor.");
            break;
        case 1:
            printf("Signal strength is poor.");
            break;
        case 2:
            printf("Signal strength is fair.");
            break;
        case 3:
            printf("Signal strength is good.");
            break;
        case 4:
            printf("Signal strength is excellent.");
            break;
        default:
            printf("Invalid signal strength! Signal strength should be between 0-100.");
            break;
    }

    return 0;
}