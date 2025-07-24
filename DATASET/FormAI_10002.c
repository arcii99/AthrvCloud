//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20 // length of the road in units
#define TRAFFIC_DENSITY 0.2 // traffic density as a fraction

typedef enum {
    EMPTY,
    CAR
} RoadCell;

int main() {
    // seed random number generator for placing cars
    srand(time(NULL));

    // initialize road
    RoadCell road[ROAD_LENGTH];
    int i;
    for (i = 0; i < ROAD_LENGTH; i++) {
        road[i] = EMPTY;
    }

    // calculate number of cars to place on road based on traffic density
    int num_cars = (int)(TRAFFIC_DENSITY * ROAD_LENGTH);

    // randomly place cars on road
    for (i = 0; i < num_cars; i++) {
        int pos = rand() % ROAD_LENGTH;
        while (road[pos] == CAR) {
            pos = rand() % ROAD_LENGTH;
        }
        road[pos] = CAR;
    }

    // print initial state of road
    printf("Initial state of road:\n");
    for (i = 0; i < ROAD_LENGTH; i++) {
        printf("%c", road[i] == EMPTY ? '.' : 'X');
    }
    printf("\n");

    // simulate traffic flow
    int time_step;
    for (time_step = 0; time_step < 10; time_step++) {
        // initialize new road with all cells empty
        RoadCell new_road[ROAD_LENGTH];
        for (i = 0; i < ROAD_LENGTH; i++) {
            new_road[i] = EMPTY;
        }

        // move cars forward
        for (i = 0; i < ROAD_LENGTH; i++) {
            if (road[i] == CAR) {
                if (i == ROAD_LENGTH - 1 || road[i+1] == CAR) {
                    new_road[i] = CAR;
                } else {
                    new_road[i+1] = CAR;
                }
            }
        }

        // update road
        for (i = 0; i < ROAD_LENGTH; i++) {
            road[i] = new_road[i];
        }

        // print state of road at current time step
        printf("State of road at time step %d:\n", time_step+1);
        for (i = 0; i < ROAD_LENGTH; i++) {
            printf("%c", road[i] == EMPTY ? '.' : 'X');
        }
        printf("\n");
    }

    return 0;
}