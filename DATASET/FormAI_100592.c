//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

int main() {
    // Initializing variables
    int signal_strength[10];
    int i, max, min, sum = 0;
    float avg;

    // Taking input from user for signal strength
    printf("Enter the signal strength of 10 Wi-Fi Networks:\n");

    for(i=0; i<10; i++) {
        printf("Wi-Fi Network %d: ", i+1);
        scanf("%d", &signal_strength[i]);
    }

    // Finding maximum, minimum, and average signal strength
    max = min = signal_strength[0];

    for(i=0; i<10; i++) {
        if(max < signal_strength[i])
            max = signal_strength[i];
        if(min > signal_strength[i])
            min = signal_strength[i];
        sum += signal_strength[i];
    }

    avg = (float) sum / 10;

    // Displaying the results
    printf("\nMaximum Signal Strength: %d\n", max);
    printf("Minimum Signal Strength: %d\n", min);
    printf("Average Signal Strength: %.2f\n", avg);

    // Displaying Wi-Fi Networks with good signal strength (above average)
    printf("\nWi-Fi Networks with Good Signal Strength:\n");

    for(i=0; i<10; i++) {
        if(signal_strength[i] > avg)
            printf("Wi-Fi Network %d: %d\n", i+1, signal_strength[i]);
    }

    return 0;
}