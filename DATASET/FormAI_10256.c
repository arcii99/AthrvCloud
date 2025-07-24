//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 4       // number of lanes
#define MAX_CARS 50       // maximum number of cars in a lane
#define SIMULATION_TIME 60 // length of the simulation in seconds
#define CAR_LENGTH 3       // length of a car in meters
#define INTER_CAR_SPACING 2 // space between individual cars in meters

typedef struct {
    int length; // length of the car in meters
    int pos;    // position of the car in meters
} Car;

void init_lane(Car* lane, int max_cars);                // function to initialize the lane
void print_lane(Car* lane, int lane_id);                // function to print the current state of the lane
void update_lane(Car* lane, int max_cars, int time);    // function to update the lane

int main() {
    srand(time(NULL));
    int time = 0;
    Car lanes[NUM_LANES][MAX_CARS];

    // initialize the lanes
    for (int i = 0; i < NUM_LANES; i++) {
        init_lane(lanes[i], MAX_CARS);
    }

    // run the simulation
    while (time < SIMULATION_TIME) {
        printf("t = %d\n", time);
        for (int i = 0; i < NUM_LANES; i++) {
            update_lane(lanes[i], MAX_CARS, time);
            print_lane(lanes[i], i);
        }
        printf("\n");
        time++;
    }

    return 0;
}

void init_lane(Car* lane, int max_cars) {
    int pos = 0;
    for (int i = 0; i < max_cars; i++) {
        lane[i].length = CAR_LENGTH;
        lane[i].pos = pos;
        pos += CAR_LENGTH + INTER_CAR_SPACING;
    }
}

void print_lane(Car* lane, int lane_id) {
    printf("Lane %d: ", lane_id);
    for (int i = 0; i < MAX_CARS; i++) {
        if (lane[i].pos == -1) {
            printf(" ");
        }
        else {
            printf("%d", i);
        }
    }
    printf("\n");
}

void update_lane(Car* lane, int max_cars, int time) {
    // move each car forward
    for (int i = 0; i < max_cars; i++) {
        if (lane[i].pos != -1) {
            lane[i].pos += 5; // assume a constant speed of 5 m/s
        }
    }

    // spawn a new car at the beginning of the lane if necessary
    if (lane[0].pos >= -CAR_LENGTH) {
        for (int i = max_cars - 1; i >= 0; i--) {
            if (lane[i].pos == -1) {
                lane[i].length = CAR_LENGTH;
                lane[i].pos = -CAR_LENGTH;
                break;
            }
        }
    }

    // check for collisions
    for (int i = 0; i < max_cars; i++) {
        if (lane[i].pos != -1) {
            for (int j = i + 1; j < max_cars; j++) {
                if (lane[j].pos != -1) {
                    if ((lane[j].pos - lane[i].pos) < (lane[i].length + INTER_CAR_SPACING)) {
                        for (int k = i + 1; k < j; k++) {
                            if (lane[k].pos != -1) {
                                lane[k].pos = -1; // remove cars between i and j if there is a collision
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    // remove cars that have exited the lane
    if (lane[max_cars - 1].pos > 100) {
        lane[max_cars - 1].pos = -1;
    }
}