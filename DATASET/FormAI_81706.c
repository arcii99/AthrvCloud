//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define MAX_CARS 1000     // Maximum number of cars on the road
#define ROAD_LENGTH 100   // The length of the road (in meters)
#define CAR_LENGTH 4      // The length of each car (in meters)
#define MAX_SPEED 100     // Maximum speed limit (in km/h)
#define MIN_DISTANCE 10   // Minimum distance (in meters) between two cars

struct Car {
    uint16_t id;
    uint8_t speed;
    uint8_t position;
};

void simulate_traffic() {
    printf("Starting traffic simulation...\n");

    // Initializing cars
    struct Car cars[MAX_CARS];
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].position = i * MIN_DISTANCE;
    }

    // Running the simulation
    for (int time_step = 0; time_step < 10; time_step++) {
        printf("==== Time step %d ====\n", time_step);
        for (int i = 0; i < MAX_CARS; i++) {

            // If the car is at the end of the road, reset its position
            if (cars[i].position == ROAD_LENGTH - CAR_LENGTH) {
                cars[i].position = 0;
            }

            // Moving the car to its new position
            cars[i].position += cars[i].speed / 10;

            // Checking for collisions with other cars
            for (int j = 0; j < MAX_CARS; j++) {
                if (i == j) {
                    continue;
                }
                if (abs(cars[i].position - cars[j].position) < MIN_DISTANCE) {
                    cars[i].speed = cars[j].speed;
                    break;
                }
            }
            printf("#%d speed: %d km/h | position: %d meters\n", cars[i].id, cars[i].speed, cars[i].position);
        }
    }

    printf("\nTraffic simulation completed.\n");
}

int main() {
    srand(time(0));
    simulate_traffic();
    return 0;
}