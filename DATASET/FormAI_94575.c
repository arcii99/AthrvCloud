//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int red_light = 0, green_light = 0, yellow_light = 0;
    char option;

    // Initialization of random number generator
    srand(time(NULL));

    printf("TRAFFIC LIGHT CONTROLLER\n\n");

    // Loop for traffic light controller
    do {
        // Generating random number (1-3) for traffic light
        int light_color = (rand() % 3) + 1;

        switch (light_color) {
            case 1:
                printf("RED light is ON\n");
                red_light++;
                break;
            case 2:
                printf("YELLOW light is ON\n");
                yellow_light++;
                break;
            case 3:
                printf("GREEN light is ON\n");
                green_light++;
                break;
        }

        // Prompt user for next action
        printf("\nPress 'q' to quit or any other key to continue:\n");
        scanf(" %c", &option);

    } while (option != 'q');

    // Print summary of traffic light duration
    printf("\nTraffic light summary:\n");
    printf(" - RED light was ON for %d times\n", red_light);
    printf(" - YELLOW light was ON for %d times\n", yellow_light);
    printf(" - GREEN light was ON for %d times\n", green_light);

    return 0;
}