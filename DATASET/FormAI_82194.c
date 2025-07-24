//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_LENGTH 40 // length of each lane
#define NUM_LANES 3 // number of lanes
#define MIN_CAR_GAP 3 // minimum gap between cars
#define SIMULATION_TIME 60 // total simulation time (in seconds)
#define CAR_SYMBOL 'X' // symbol representing car
#define EMPTY_SYMBOL '-' // symbol representing empty space

int main() {
    srand(time(NULL)); // initialize random seed

    int lanes[NUM_LANES][LANE_LENGTH]; // 2D array to represent lanes
    int car_counters[NUM_LANES] = {0}; // array to keep track of car positions
    int car_gap_counters[NUM_LANES] = {0}; // array to keep track of car gaps
    int time_counter = 0; // counter for simulation time

    // initialize lanes with empty symbols
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < LANE_LENGTH; j++) {
            lanes[i][j] = EMPTY_SYMBOL;
        }
    }

    // main simulation loop
    while (time_counter < SIMULATION_TIME) {
        // add new cars
        for (int i = 0; i < NUM_LANES; i++) {
            if (car_gap_counters[i] == 0) {
                // add car to lane if space is available
                if (lanes[i][0] == EMPTY_SYMBOL) {
                    lanes[i][0] = CAR_SYMBOL;
                    car_counters[i]++;
                    car_gap_counters[i] = rand() % MIN_CAR_GAP + 1;
                }
            } else {
                car_gap_counters[i]--;
            }
        }

        // move cars forward
        for (int i = 0; i < NUM_LANES; i++) {
            for (int j = LANE_LENGTH - 1; j > 0; j--) {
                if (lanes[i][j - 1] == CAR_SYMBOL) {
                    lanes[i][j] = CAR_SYMBOL;
                    car_counters[i]++;
                    if (j == 1) {
                        lanes[i][0] = EMPTY_SYMBOL;
                    }
                } else {
                    lanes[i][j] = lanes[i][j - 1];
                }
            }
        }

        // print current state of lanes
        printf("Time: %d\n", time_counter);
        for (int i = 0; i < NUM_LANES; i++) {
            printf("| ");
            for (int j = 0; j < LANE_LENGTH; j++) {
                printf("%c ", lanes[i][j]);
            }
            printf("|\n");
        }
        printf("\n");

        // increment simulation time
        time_counter++;
    }

    return 0;
}