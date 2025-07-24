//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 10
#define GREEN_LIGHT 20
#define MAX_CARS 20
 
int main ()
{
    int northbound_cars = 0, eastbound_cars = 0, westbound_cars = 0, southbound_cars = 0;
    int counter = 0, light_counter = 0, time_left = 0, average_wait_time = 0;
    int intersection[4] = {0, 0, 0, 0};
    int cars[4][MAX_CARS];
    int direction, i, j;
    srand(time(NULL));

    // Generate random cars at the intersection
    for (i = 0; i < 4; i++) {
        for (j = 0; j < MAX_CARS; j++) {
            cars[i][j] = rand() % 10;
        }
    }

    // Simulation loop
    while (counter < 100) {
        // Check if the current light is green
        if (time_left == 0) {
            if (light_counter == 0) {
                printf("\nNorth-South light is green\n");
                printf("East-West light is red\n");
                time_left = GREEN_LIGHT;
                light_counter = 1;
                printf("\nNumber of cars waiting at North-South: %d\n", northbound_cars + southbound_cars);
                if (northbound_cars + southbound_cars > 0) {
                    average_wait_time += (northbound_cars + southbound_cars);
                    printf("Average wait time: %d\n", average_wait_time / (northbound_cars + southbound_cars));
                }
            } else {
                printf("\nEast-West light is green\n");
                printf("North-South light is red\n");
                time_left = RED_LIGHT;
                light_counter = 0;
                printf("\nNumber of cars waiting at East-West: %d\n", eastbound_cars + westbound_cars);
                if (eastbound_cars + westbound_cars > 0) {
                    average_wait_time += (eastbound_cars + westbound_cars);
                    printf("Average wait time: %d\n", average_wait_time / (eastbound_cars + westbound_cars));
                }
            }
        }

        // Decrement the time left for the light to change
        time_left--;

        // Update the number of cars waiting at each intersection
        northbound_cars += cars[0][counter % MAX_CARS];
        eastbound_cars += cars[1][counter % MAX_CARS];
        westbound_cars += cars[2][counter % MAX_CARS];
        southbound_cars += cars[3][counter % MAX_CARS];

        // Clear the intersection as cars pass through
        for (i = 0; i < 4; i++) {
            if (intersection[i] > 0) {
                intersection[i]--;
            }
        }

        // Let the cars through the intersection
        for (i = 0; i < 4; i++) {
            if (intersection[i] == 0 && (i == 0 || i == 3) && (northbound_cars > 0 || southbound_cars > 0)) {
                if (northbound_cars > southbound_cars) {
                    direction = 0;
                    northbound_cars--;
                } else {
                    direction = 3;
                    southbound_cars--;
                }
                intersection[i] = cars[i][counter % MAX_CARS];
                printf("Car heading %d passed through intersection %d\n", direction, i+1);
            } else if (intersection[i] == 0 && (i == 1 || i == 2) && (eastbound_cars > 0 || westbound_cars > 0)) {
                if (eastbound_cars > westbound_cars) {
                    direction = 1;
                    eastbound_cars--;
                } else {
                    direction = 2;
                    westbound_cars--;
                }
                intersection[i] = cars[i][counter % MAX_CARS];
                printf("Car heading %d passed through intersection %d\n", direction, i+1);
            }
        }

        counter++;
    }
    return 0;
}