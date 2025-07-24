//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int trafficLight = 0; // 0 - Red, 1 - Yellow, 2 - Green
    int duration = 0; // Duration of each light
    int countdown = 0; // Countdown of remaining time for each light

    while (1) // Infinite loop
    {
        switch (trafficLight)
        {
            // RED light
            case 0:
                duration = 10; // 10 seconds duration
                break;

            // YELLOW light
            case 1:
                duration = 3; // 3 seconds duration
                break;

            // GREEN light
            case 2:
                duration = 15; // 15 seconds duration
                break;
        }

        countdown = duration; // Set countdown to the duration of the light

        // Loop through the countdown
        while (countdown > 0)
        {
            printf("Traffic light is ");

            // Print the current light
            switch (trafficLight)
            {
                case 0:
                    printf("RED\n");
                    break;

                case 1:
                    printf("YELLOW\n");
                    break;

                case 2:
                    printf("GREEN\n");
                    break;
            }

            printf("Time remaining: %d seconds\n", countdown);

            // Wait for 1 second
            sleep(1);

            countdown--; // Decrement the countdown
        }

        // Change the light
        trafficLight = (trafficLight + 1) % 3; // Cycle through 0, 1, 2

        printf("\n");
    }

    return 0;
}