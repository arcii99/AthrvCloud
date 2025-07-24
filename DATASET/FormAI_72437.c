//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int signal_strength[10]; // let's assume we have 10 Wi-Fi signal strength measurements
    float avg_signal_strength = 0;
    float variance = 0;
    float std_deviation = 0;
    int i;

    printf("Enter the Wi-Fi signal strength measurements (values between 0 and 100):\n");

    // loop to get input from user
    for(i = 0; i < 10; i++)
    {
        printf("Measurement %d: ", i+1);
        scanf("%d", &signal_strength[i]);
        avg_signal_strength += signal_strength[i]; // add the measurements to calculate the average
    }

    avg_signal_strength /= 10; // calculate the average

    // loop to calculate the variance
    for(i = 0; i < 10; i++)
    {
        variance += pow(signal_strength[i] - avg_signal_strength, 2);
    }

    variance /= 9; // calculate the variance

    std_deviation = sqrt(variance); // calculate the standard deviation

    printf("\nAverage signal strength: %.2f", avg_signal_strength);
    printf("\nSignal strength variance: %.2f", variance);
    printf("\nSignal strength standard deviation: %.2f", std_deviation);

    return 0;
}