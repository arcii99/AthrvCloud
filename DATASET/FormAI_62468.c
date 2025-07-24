//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 60
#define MIN_GAP 2
#define MAX_GAP 5
#define ROAD_LENGTH 1000
#define NUM_CARS 20
#define SIMULATION_DURATION 1000

typedef struct {
    int position;
    int speed;
} Car;

void update_cars(Car cars[], int num_cars) {
    int i;
    for (i = 0; i < num_cars; i++) {
        int distance_to_next_car = cars[i + 1].position - cars[i].position;
        int gap = distance_to_next_car - MIN_GAP;
        if (gap < 0) {
            cars[i].speed = 0;
        } else {
            int target_speed = gap;
            if (target_speed > MAX_SPEED) {
                target_speed = MAX_SPEED;
            }
            if (target_speed < cars[i].speed) {
                cars[i].speed = target_speed;
            } else {
                cars[i].speed += 1;
                if (cars[i].speed > target_speed) {
                    cars[i].speed = target_speed;
                }
            }
        }
    }
}

void print_cars(Car cars[], int num_cars) {
    int i;
    for (i = 0; i < num_cars; i++) {
        printf("Car %d: position=%d, speed=%d\n", i, cars[i].position, cars[i].speed);
    }
}

void simulate_traffic_flow() {
    Car cars[NUM_CARS];
    int i;
    for (i = 0; i < NUM_CARS; i++) {
        cars[i].position = (i * ROAD_LENGTH) / NUM_CARS;
        cars[i].speed = MAX_SPEED;
    }

    for (i = 0; i < SIMULATION_DURATION; i++) {
        printf("Time %d:\n", i);
        print_cars(cars, NUM_CARS);
        update_cars(cars, NUM_CARS);
    }
}

int main() {
    srand(time(NULL));

    simulate_traffic_flow();

    return 0;
}