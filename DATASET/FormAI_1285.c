//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20 // maximum number of cars on the road
#define MAX_SPEED 100 // maximum speed of a car
#define MIN_CAR_DISTANCE 5 // minimum distance between two cars
#define ROAD_LENGTH 500 // length of road

int car_positions[MAX_CARS]; // positions of the cars on the road
int car_speeds[MAX_CARS]; // speeds of the cars on the road

void move_car(int car_index, int distance) {
    car_positions[car_index] += distance;
}

bool check_collision(int car_index) {
    int car_position = car_positions[car_index];
    int car_distance = MIN_CAR_DISTANCE;
    for (int i = 0; i < MAX_CARS; i++) {
        if (i == car_index) {
            continue;
        }
        int distance = car_positions[i] - car_position;
        if (distance < 0) {
            distance += ROAD_LENGTH;
        }
        if (distance < car_distance) {
            return true;
        }
    }
    return false;
}

void print_road() {
    printf("|");
    for (int i = 0; i < ROAD_LENGTH; i++) {
        bool car_found = false;
        for (int j = 0; j < MAX_CARS; j++) {
            if (car_positions[j] == i) {
                printf("o");
                car_found = true;
                break;
            }
        }
        if (!car_found) {
            printf("-");
        }
    }
    printf("|\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // initialize the cars
    for (int i = 0; i < MAX_CARS; i++) {
        car_positions[i] = i * (ROAD_LENGTH / MAX_CARS);
        car_speeds[i] = rand() % MAX_SPEED + 1;
    }

    // simulate the traffic flow
    for (int tick = 0; tick < 100; tick++) {
        printf("Tick %d:\n", tick);

        // move the cars
        for (int i = 0; i < MAX_CARS; i++) {
            int distance = car_speeds[i];
            for (int j = 0; j < distance; j++) {
                if (!check_collision(i)) {
                    move_car(i, 1);
                } else {
                    printf("Crash!\n");
                    exit(1);
                }
            }
        }

        print_road();
    }

    return 0;
}