//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int cars = 0;
    int green_light = 0;
    int red_light = 0;

    while (1) {
        // Randomly generate number of cars
        cars = rand() % 10;

        // Check if green light
        if (green_light == 0) {
            printf("Red Light: %d cars are waiting\n", cars);
            red_light = 1;
            green_light = 0;
        } else {
            printf("Green Light: %d cars are passing\n", cars);
            red_light = 0;
            green_light = 1;
        }

        // Delay for 3 seconds
        sleep(3);
    }
    return 0;
}