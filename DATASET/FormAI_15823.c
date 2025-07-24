//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 5
#define MAX_DECELERATION 2

struct car_t {
    int speed;
    int position;
};

int main() {
    // Initialize cars
    struct car_t cars[MAX_CARS];
    int num_cars = 20;
    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].position = rand() % 100;
    }

    // Start simulation
    int time = 0;
    while (time < 100) {
        // Print current state of traffic
        printf("Time: %d\n", time);
        for (int i = 0; i < num_cars; i++) {
            printf("Car %d: position=%d, speed=%d\n", i, cars[i].position, cars[i].speed);
        }

        // Update positions and speeds of cars
        for (int i = 0; i < num_cars; i++) {
            // Calculate distance to car in front
            int distance_to_car_in_front = 9999;
            for (int j = 0; j < num_cars; j++) {
                if (j == i) continue;
                if (cars[j].position > cars[i].position) {
                    distance_to_car_in_front = cars[j].position - cars[i].position;
                    break;
                }
            }

            // Update speed based on distance to car in front
            if (cars[i].speed > distance_to_car_in_front) {
                cars[i].speed = distance_to_car_in_front - rand() % MAX_DECELERATION;
                if (cars[i].speed < 0) cars[i].speed = 0;
            } else {
                cars[i].speed += rand() % 2 - 1;
                if (cars[i].speed < 0) cars[i].speed = 0;
                else if (cars[i].speed > MAX_SPEED) cars[i].speed = MAX_SPEED;
            }

            // Update position based on speed
            cars[i].position += cars[i].speed;
        }

        // Increment time
        time++;
    }

    return 0;
}