//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>

// Enumerating the traffic light colors
enum traffic_light {RED, YELLOW, GREEN};

int main()
{
    // Start with RED traffic light
    enum traffic_light current_light = RED;

    while(1)
    {
        switch(current_light)
        {
            // If the current light is RED, wait for 10 seconds and change to GREEN
            case RED:
            {
                printf("\n\nRED light... STOP!\n");
                printf("Waiting for 10 sec...\n");
                sleep(10);
                current_light = GREEN;
                break;
            }

            // If the current light is YELLOW, wait for 3 seconds and change to RED
            case YELLOW:
            {
                printf("\n\nYELLOW light... GET READY!\n");
                printf("Waiting for 3 sec...\n");
                sleep(3);
                current_light = RED;
                break;
            }

            // If the current light is GREEN, wait for 15 seconds and change to YELLOW
            case GREEN:
            {
                printf("\n\nGREEN light... GO!\n");
                printf("Waiting for 15 sec...\n");
                sleep(15);
                current_light = YELLOW;
                break;
            }
        }
    }

    return 0;
}