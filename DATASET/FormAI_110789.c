//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initializing variables
    int signal_strength = 0;
    int noise_level;
    int i;

    // Generating random noise level
    srand(time(0));
    noise_level = rand() % 10 + 1;

    // Generating signal strength with some interference
    for (i = 1; i <= 5; i++)
    {
        signal_strength += rand() % 5 + 1;
        signal_strength -= noise_level;
    }

    // Displaying signal strength and noise level
    printf("Wi-Fi Signal Strength: %d dBm\n", signal_strength);
    printf("Noise Level: %d dBm\n", noise_level);

    // Analyzing the signal quality
    if (signal_strength >= -50)
    {
        printf("Signal quality: Excellent!\n");
    }
    else if (signal_strength >= -60)
    {
        printf("Signal quality: Good!\n");
    }
    else if (signal_strength >= -70)
    {
        printf("Signal quality: Fair.\n");
    }
    else if (signal_strength >= -80)
    {
        printf("Signal quality: Poor.\n");
    }
    else
    {
        printf("Signal quality: Very poor!\n");
    }

    return 0;
}