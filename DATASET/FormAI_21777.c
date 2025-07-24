//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main()
{
    int signal_strength = 0;
    srand(time(NULL)); // Initialize random seed

    while(1)
    {
        signal_strength = (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH; // Generate random signal strength between 0 and 100
        printf("Current signal strength: %d dBm\n", signal_strength);
        if(signal_strength >= 80) // Strong signal
        {
            printf("Signal is strong!\n");
        }
        else if(signal_strength >= 50 && signal_strength < 80) // Moderate signal
        {
            printf("Signal is moderate.\n");
        }
        else // Weak signal
        {
            printf("Signal is weak.\n");
        }
        sleep(1); // Wait for 1 second before checking signal strength again
    }

    return 0;
}