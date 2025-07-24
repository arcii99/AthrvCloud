//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARS 50
#define LANE_LENGTH 500
#define NUM_LANES 3
#define MAX_SPEED 70
#define MIN_SPEED 40
#define MAX_DISTANCE 100
#define PROB_LANE_CHANGE 0.2

// Define a struct to represent a car
typedef struct {
    int speed;
    int distance;
    int lane;
} Car;

// Initialize the cars in random lanes and distances
void init_cars(Car *cars) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        cars[i].distance = rand() % LANE_LENGTH + 1;
        cars[i].lane = rand() % NUM_LANES;
    }
}

// Update the position of the cars based on their speed and distance
void update_cars(Car *cars) {
    for (int i = 0; i < NUM_CARS; i++) {
        // Calculate the distance to the car in front
        int j;
        int distance_to_car_in_front = LANE_LENGTH;
        for (j = 0; j < NUM_CARS; j++) {
            if (i != j && cars[i].lane == cars[j].lane && cars[j].distance > cars[i].distance) {
                int distance = cars[j].distance - cars[i].distance;
                if (distance < distance_to_car_in_front) {
                    distance_to_car_in_front = distance;
                }
            }
        }
        // Update the distance of the car based on its speed and the distance to the car in front
        if (distance_to_car_in_front > MAX_DISTANCE) {
            cars[i].distance += cars[i].speed;
        } else if (cars[i].speed < distance_to_car_in_front) {
            cars[i].distance += cars[i].speed;
        } else {
            cars[i].distance = cars[j].distance - MAX_DISTANCE;
        }
        // If the car is at the end of the lane, loop back to the beginning
        if (cars[i].distance > LANE_LENGTH) {
            cars[i].distance = 0;
        }
        // Check if the car should change lanes
        if (rand() < PROB_LANE_CHANGE * RAND_MAX) {
            int new_lane = rand() % NUM_LANES;
            if (new_lane != cars[i].lane) {
                int clear = 1;
                for (j = 0; j < NUM_CARS; j++) {
                    if (i != j && cars[j].lane == new_lane && cars[j].distance > cars[i].distance) {
                        int distance = cars[j].distance - cars[i].distance;
                        if (distance < MAX_DISTANCE) {
                            clear = 0;
                            break;
                        }
                    }
                }
                if (clear) {
                    cars[i].lane = new_lane;
                }
            }
        }
    }
}

// Print the current state of the lanes and the cars on them
void print_lanes(Car *cars) {
    int lanes[NUM_LANES][LANE_LENGTH];
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < LANE_LENGTH; j++) {
            lanes[i][j] = -1;
        }
    }
    for (int i = 0; i < NUM_CARS; i++) {
        lanes[cars[i].lane][cars[i].distance] = i;
    }
    printf("Lane 1: ");
    for (int j = 0; j < LANE_LENGTH; j++) {
        if (lanes[0][j] == -1) {
            printf("-");
        } else {
            printf("%d", cars[lanes[0][j]].speed);
        }
    }
    printf("\n");
    printf("Lane 2: ");
    for (int j = 0; j < LANE_LENGTH; j++) {
        if (lanes[1][j] == -1) {
            printf("-");
        } else {
            printf("%d", cars[lanes[1][j]].speed);
        }
    }
    printf("\n");
    printf("Lane 3: ");
    for (int j = 0; j < LANE_LENGTH; j++) {
        if (lanes[2][j] == -1) {
            printf("-");
        } else {
            printf("%d", cars[lanes[2][j]].speed);
        }
    }
    printf("\n");
}

int main() {
    Car cars[NUM_CARS];
    init_cars(cars);
    for (int i = 0; i < 10; i++) {
        printf("Step %d:\n", i);
        print_lanes(cars);
        update_cars(cars);
    }
    return 0;
}