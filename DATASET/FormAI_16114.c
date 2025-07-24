//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shocked
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Traffic light time in seconds
    const int RED_LIGHT_TIME = 5;
    const int YELLOW_LIGHT_TIME = 2;
    const int GREEN_LIGHT_TIME = 7;

    // Set initial state to red light for North-South direction
    enum TrafficLightState
    {
        NORTH_SOUTH_RED,
        NORTH_SOUTH_YELLOW,
        NORTH_SOUTH_GREEN,
        EAST_WEST_RED,
        EAST_WEST_YELLOW,
        EAST_WEST_GREEN
    } trafficLight = NORTH_SOUTH_RED;

    printf("Traffic light is now red for North-South direction. \n");

    while (true)
    {
        switch (trafficLight)
        {
            case NORTH_SOUTH_RED:
                // Allow for some delay between switching lights
                printf("Waiting for %d seconds...\n", RED_LIGHT_TIME);
                sleep(RED_LIGHT_TIME);

                printf("Change light to green for North-South direction.\n");
                trafficLight = NORTH_SOUTH_GREEN;
                break;

            case NORTH_SOUTH_GREEN:
                printf("Waiting for %d seconds...\n", GREEN_LIGHT_TIME);
                sleep(GREEN_LIGHT_TIME);

                printf("Change light to yellow for North-South direction.\n");
                trafficLight = NORTH_SOUTH_YELLOW;
                break;

            case NORTH_SOUTH_YELLOW:
                printf("Waiting for %d seconds...\n", YELLOW_LIGHT_TIME);
                sleep(YELLOW_LIGHT_TIME);

                printf("Change light to red for North-South direction.\n");
                trafficLight = EAST_WEST_GREEN;
                break;

            case EAST_WEST_RED:
                printf("Waiting for %d seconds...\n", RED_LIGHT_TIME);
                sleep(RED_LIGHT_TIME);

                printf("Change light to green for East-West direction.\n");
                trafficLight = EAST_WEST_GREEN;
                break;

            case EAST_WEST_GREEN:
                printf("Waiting for %d seconds...\n", GREEN_LIGHT_TIME);
                sleep(GREEN_LIGHT_TIME);

                printf("Change light to yellow for East-West direction.\n");
                trafficLight = EAST_WEST_YELLOW;
                break;

            case EAST_WEST_YELLOW:
                printf("Waiting for %d seconds...\n", YELLOW_LIGHT_TIME);
                sleep(YELLOW_LIGHT_TIME);

                printf("Change light to red for East-West direction.\n");
                trafficLight = NORTH_SOUTH_RED;
                break;

            default:
                printf("Invalid Traffic Light State");
                break;
        }
    }

    return 0;
}