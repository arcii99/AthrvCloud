//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    WEST_TO_EAST=1,
    EAST_TO_WEST=2,
    NORTH_TO_SOUTH=3,
    SOUTH_TO_NORTH=4
} direction;

int main() {
    int west_to_east_cars = 0, east_to_west_cars = 0, north_to_south_cars = 0, south_to_north_cars = 0;
    int cars_waiting[4] = {0, 0, 0, 0};
    int i, j, pos;
    direction dir;
    srand(time(0)); // seed for random number generation
 
    for (i = 0; i < 60; i++) {
        dir = rand() % 4 + 1; // generate random direction
        switch (dir) {
            case WEST_TO_EAST:
                printf("Car Heading West to East has arrived!\n");
                cars_waiting[WEST_TO_EAST-1]++; // increment count of cars waiting in this direction
                break;
            case EAST_TO_WEST:
                printf("Car Heading East to West has arrived!\n");
                cars_waiting[EAST_TO_WEST-1]++; // increment count of cars waiting in this direction
                break;
            case NORTH_TO_SOUTH:
                printf("Car Heading North to South has arrived!\n");
                cars_waiting[NORTH_TO_SOUTH-1]++; // increment count of cars waiting in this direction
                break;
            case SOUTH_TO_NORTH:
                printf("Car Heading South to North has arrived!\n");
                cars_waiting[SOUTH_TO_NORTH-1]++; // increment count of cars waiting in this direction
                break;
        }
 
        for (j = 0; j < 4; j++) { // check if there are any cars waiting and let them through
            if (cars_waiting[j] > 0) {
                cars_waiting[j]--;
                switch (j+1) {
                    case WEST_TO_EAST:
                        printf("Car Heading West to East is passing through intersection.\n");
                        west_to_east_cars++;
                        break;
                    case EAST_TO_WEST:
                        printf("Car Heading East to West is passing through intersection.\n");
                        east_to_west_cars++;
                        break;
                    case NORTH_TO_SOUTH:
                        printf("Car Heading North to South is passing through intersection.\n");
                        north_to_south_cars++;
                        break;
                    case SOUTH_TO_NORTH:
                        printf("Car Heading South to North is passing through intersection.\n");
                        south_to_north_cars++;
                        break;
                }
            }
        }

        printf("\nCurrent Traffic Flow:\n");
        printf("West to East: %d cars\n", west_to_east_cars);
        printf("East to West: %d cars\n", east_to_west_cars);
        printf("North to South: %d cars\n", north_to_south_cars);
        printf("South to North: %d cars\n", south_to_north_cars);
        printf("\n");
    }
 
    return 0;
}