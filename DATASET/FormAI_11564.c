//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main()
{
    int signal_strength;

    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    printf("Please enter the signal strength in dBm (between -100 and 0):\n");
    scanf("%d", &signal_strength);

    if (signal_strength < -100 || signal_strength > 0) {
        printf("Invalid input! Please enter a value between -100 and 0.\n");
        exit(1);
    }

    float signal_strength_percentage = ((float)(signal_strength - MIN_SIGNAL_STRENGTH) /
                                         (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH)) * 100.0;

    int num_bars = round(signal_strength_percentage / 10);
    printf("Signal strength: %d dBm\n", signal_strength);
    printf("Signal strength percentage: %.2f%%\n", signal_strength_percentage);
    printf("Number of bars: %d\n\n", num_bars);

    for (int i = 0; i < num_bars; i++) {
        printf("▮");
    }
    for (int i = 0; i < 10 - num_bars; i++) {
        printf("▯");
    }
    printf("\n");

    printf("Thank you for using the Wi-Fi Signal Strength Analyzer!\n");

    return 0;
}