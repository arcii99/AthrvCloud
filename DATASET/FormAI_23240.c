//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Linus Torvalds
#include <stdio.h>

int main()
{
    int interval, currentTime;
    char light;

    interval = 10;  // Change the interval to set the duration of each light
    light = 'r';    // Start with the red light

    while (1) {
        printf("Current Light: %c\n", light);
        printf("Time Remaining: %d\n\n", interval - currentTime);

        // Wait for 1 second
        sleep(1);

        // Update the current time and check if the interval has elapsed
        currentTime++;
        if (currentTime == interval) {
            // Reset the current time and change the light
            currentTime = 0;

            if (light == 'r') {
                light = 'y';
            } else if (light == 'y') {
                light = 'g';
            } else {
                light = 'r';
            }
        }
    }

    return 0;
}