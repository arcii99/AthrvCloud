//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int time_count = 0;

    /* Declare and initialize the traffic light phases */
    enum TrafficLightPhase {RED, GREEN, YELLOW, BLINK_YELLOW};
    enum TrafficLightPhase current_phase = RED;

    while(1)
    {
        /* Print the current phase */
        printf("Current phase: ");
        switch(current_phase)
        {
            case RED:
                printf("Red\n");
                break;
            case GREEN:
                printf("Green\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case BLINK_YELLOW:
                printf("Blink Yellow\n");
                break;
        }

        /* Wait for one second */
        sleep(1);
        time_count++;

        /* Check if the current phase needs to be changed */
        switch(current_phase)
        {
            case RED:
                if(time_count >= 10) // Switch from red to green after 10 seconds
                {
                    current_phase = GREEN;
                    time_count = 0;
                }
                break;
            case GREEN:
                if(time_count >= 15) // Switch from green to yellow after 15 seconds
                {
                    current_phase = YELLOW;
                    time_count = 0;
                }
                break;
            case YELLOW:
                if(time_count >= 3) // Switch from yellow to red after 3 seconds
                {
                    current_phase = RED;
                    time_count = 0;
                }
                break;
            case BLINK_YELLOW:
                if(time_count >= 5) // Switch from blink yellow to red after 5 seconds
                {
                    current_phase = RED;
                    time_count = 0;
                }
                break;
        }

        /* Check for special conditions */
        time_t now = time(NULL);
        if(now % 2 == 0 && current_phase == YELLOW) // Blink yellow every other second
        {
            current_phase = BLINK_YELLOW;
        }
    }

    return 0;
}