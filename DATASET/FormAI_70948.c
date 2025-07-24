//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20
#define NUM_CARS 10

void print_road(int road[ROAD_LENGTH][2], int time_step) {
    printf("Time Step: %d\n", time_step);
    for (int i = 0; i < ROAD_LENGTH; i++) {
        int car_index = road[i][0];
        if (car_index != -1) {
            printf("C ");
        } else {
            printf(". ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int road[ROAD_LENGTH][2];
    // initialize road to -1 (no car)
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i][0] = -1;
    }

    // add cars to beginning of road
    for (int i = 0; i < NUM_CARS; i++) {
        road[i][0] = i;
    }

    int time_step = 0;

    // simulate traffic flow
    while (road[ROAD_LENGTH - 1][0] == -1) {
        print_road(road, time_step);

        // update positions of cars
        for (int i = 0; i < ROAD_LENGTH; i++) {
            int car_index = road[i][0];
            if (car_index != -1) {
                if (i + 1 < ROAD_LENGTH && road[i + 1][0] == -1) {
                    // car can move forward
                    road[i][0] = -1;
                    road[i + 1][0] = car_index;
                }
            }
        }

        time_step++;
    }

    printf("All cars made it to the end of the road in %d time steps.\n", time_step);

    return 0;
}