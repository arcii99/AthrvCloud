//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the traffic light variables
    int red_light, yellow_light, green_light;
    red_light = 1;
    yellow_light = 0;
    green_light = 0;

    // Loop infinitely
    while (1) {
        // Set the traffic lights randomly
        int light = rand() % 3;
        switch (light) {
            case 0:
                red_light = 1;
                yellow_light = 0;
                green_light = 0;
                break;
            case 1:
                red_light = 0;
                yellow_light = 1;
                green_light = 0;
                break;
            case 2:
                red_light = 0;
                yellow_light = 0;
                green_light = 1;
                break;
        }

        // Print the traffic light configuration
        printf("RED: %d  YELLOW: %d  GREEN: %d\n",
               red_light, yellow_light, green_light);

        // Delay for 2 seconds
        sleep(2);
    }

    return 0;
}