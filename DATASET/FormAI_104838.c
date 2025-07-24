//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARS 100
#define NUM_LANES 2
#define MAX_SPEED 50
#define MAX_ACCELERATION 3
#define MAX_DECELERATION 2
#define CAR_LENGTH 5
#define LANE_WIDTH 10
#define SIMULATION_TIME 600

typedef struct car {
    int lane;       // 0 or 1
    int position;   // from 0 to lane_length (<= 500)
    int speed;      // from 0 to max_speed (<= 50)
} Car;

int main(void) {
    Car cars[NUM_LANES][NUM_CARS];
    int i, j, t;

    // initialize random seed
    srand(time(NULL));

    // initialize cars
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < NUM_CARS; j++) {
            cars[i][j].lane = i;
            cars[i][j].position = rand() % 500;
            cars[i][j].speed = rand() % MAX_SPEED;
        }
    }

    // simulate traffic flow
    for (t = 0; t < SIMULATION_TIME; t++) {
        for (i = 0; i < NUM_LANES; i++) {
            for (j = 0; j < NUM_CARS; j++) {
                // calculate new speed
                int forward_distance, max_speed;
                if (j == 0) {
                    forward_distance = cars[i][j+1].position - cars[i][j].position - CAR_LENGTH;
                    max_speed = MAX_SPEED;
                } else if (j == NUM_CARS - 1) {
                    forward_distance = cars[i][j].position - cars[i][j-1].position - CAR_LENGTH;
                    max_speed = MAX_SPEED;
                } else {
                    forward_distance = cars[i][j+1].position - cars[i][j].position - CAR_LENGTH;
                    int backward_distance = cars[i][j].position - cars[i][j-1].position - CAR_LENGTH;
                    int min_distance = forward_distance < backward_distance ? forward_distance : backward_distance;
                    max_speed = min_distance - 1 < MAX_SPEED ? min_distance - 1 : MAX_SPEED;
                }
                int random_acceleration = rand() % (2 * MAX_ACCELERATION + 1) - MAX_ACCELERATION;
                cars[i][j].speed += random_acceleration;
                if (cars[i][j].speed > max_speed) {
                    cars[i][j].speed = max_speed;
                }
                if (cars[i][j].speed < 0) {
                    cars[i][j].speed = 0;
                }

                // calculate new position
                cars[i][j].position += cars[i][j].speed;
                if (cars[i][j].position >= LANE_WIDTH) {
                    cars[i][j].position %= LANE_WIDTH;
                }
            }
        }

        // print current state
        for (i = 0; i < NUM_LANES; i++) {
            printf("Lane %d:\n", i);
            for (j = 0; j < NUM_CARS; j++) {
                printf("%d\t", cars[i][j].position);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}