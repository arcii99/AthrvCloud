//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables for traffic flow simulation
    int num_lanes = 4;
    int num_cars = 100;
    int num_seconds = 3600;
    int road_length = 3000;
    int car_length = 5;
    int car_speed = 55;

    // create random starting positions and speeds for cars
    int starting_positions[num_cars]; 
    int car_speeds[num_cars];
    srand((unsigned) time(NULL));
    for (int i = 0; i < num_cars; i++) {
        starting_positions[i] = (rand() % (road_length - car_length)) + 1;
        car_speeds[i] = (rand() % (car_speed - 10)) + 10;
    }

    // initialize arrays to track car positions
    int positions[num_lanes][num_cars];
    for (int i = 0; i < num_lanes; i++) {
        for (int j = 0; j < num_cars; j++) {
            positions[i][j] = starting_positions[j];
        }
    }

    // simulate traffic flow for num_seconds seconds
    for (int i = 0; i < num_seconds; i++) {
        // update car positions based on speed
        for (int j = 0; j < num_cars; j++) {
            int lane = rand() % num_lanes;
            int new_position = positions[lane][j] + car_speeds[j];
            if (new_position >= road_length) {
                new_position = new_position - road_length;
            }
            positions[lane][j] = new_position;
        }

        // check for collisions and slow down if necessary
        for (int j = 0; j < num_cars; j++) {
            int lane = rand() % num_lanes;
            int position = positions[lane][j];
            for (int k = 0; k < num_cars; k++) {
                if (j != k && lane == lane && 
                    abs(position - positions[lane][k]) < car_length) {
                    car_speeds[j] = car_speeds[j] - 10;
                }
            }
        }
    }

    // print out final car positions and speeds
    for (int i = 0; i < num_lanes; i++) {
        printf("Lane %d:\n", i+1);
        for (int j = 0; j < num_cars; j++) {
            printf("\tCar %d position: %d, speed: %d\n", j+1, positions[i][j], car_speeds[j]);
        }
    }

    return 0;
}