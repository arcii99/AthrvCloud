//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_SIGNAL_STRENGTH 10 // The minimum signal strength threshold
#define MAX_SIGNAL_STRENGTH 100 // The maximum signal strength threshold

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate random signal strengths for our access points
    int ap1_signal_strength = rand() % 90 + 10;
    int ap2_signal_strength = rand() % 90 + 10;

    // Print the signal strengths for the access points
    printf("Access Point 1 Signal Strength: %d%%\n", ap1_signal_strength);
    printf("Access Point 2 Signal Strength: %d%%\n", ap2_signal_strength);

    // Determine if the signal strength is strong enough to connect
    if (ap1_signal_strength >= MIN_SIGNAL_STRENGTH || ap2_signal_strength >= MIN_SIGNAL_STRENGTH)
    {
        printf("At least one access point has a strong enough signal to connect.\n");

        // Determine which access point has the strongest signal
        if (ap1_signal_strength > ap2_signal_strength)
        {
            printf("Access Point 1 has the strongest signal.\n");

            // Check if the signal strength is high enough to connect
            if (ap1_signal_strength >= MAX_SIGNAL_STRENGTH)
            {
                printf("Access Point 1 signal strength is extremely strong and is probably the best choice to connect to.\n");
            }
            else
            {
                printf("Access Point 1 signal strength is decent but not the best choice to connect to.\n");
            }
        }
        else if (ap2_signal_strength > ap1_signal_strength)
        {
            printf("Access Point 2 has the strongest signal.\n");

            // Check if the signal strength is high enough to connect
            if (ap2_signal_strength >= MAX_SIGNAL_STRENGTH)
            {
                printf("Access Point 2 signal strength is extremely strong and is probably the best choice to connect to.\n");
            }
            else
            {
                printf("Access Point 2 signal strength is decent but not the best choice to connect to.\n");
            }
        }
        else
        {
            printf("Both access points have the same signal strength. Either one is a good choice to connect to.\n");
        }
    }
    else
    {
        printf("No access points have a strong enough signal to connect.\n");
    }

    return 0;
}