//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function to calculate signal strength
int calculateSignalStrength(int signal_power, int distance)
{
    int signal_strength = signal_power / (pow(distance, 2));

    return signal_strength;
}

void main()
{
    int signal_power = 20;
    int distance = 5;
    int signal_strength = calculateSignalStrength(signal_power, distance);

    printf("Signal Power: %d Watts\n", signal_power);
    printf("Distance: %d meters\n", distance);
    printf("Signal Strength: %d Watts/m^2\n", signal_strength);
}