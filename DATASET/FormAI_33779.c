//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define TRAFFIC_LIGHT_PERIOD 10 
#define MIN_CAR_DISTANCE 5
#define MAX_CAR_SPEED 8

typedef struct {
    int position;
    int speed;
} Car;

typedef enum {
    RED,
    GREEN
} TrafficLight;

int main() {
    srand(time(NULL));
    Car cars[MAX_CARS];
    TrafficLight trafficLight = GREEN;
    int i, j, k;
    int numCars = 0;
    int time = 0;

    // Initialize cars array
    for (i = 0; i < MAX_CARS; i++) {
        cars[i].position = -1;
        cars[i].speed = 0;
    }

    // Main loop
    while (1) {
        time++;

        // Spawn new cars
        if (numCars < MAX_CARS && rand() % 10 == 0) {
            int carPos = 0;
            for (i = 0; i < numCars; i++) {
                if (cars[i].position - carPos < MIN_CAR_DISTANCE) {
                    carPos = cars[i].position - MIN_CAR_DISTANCE;
                }
            }

            cars[numCars].position = carPos;
            cars[numCars].speed = (rand() % MAX_CAR_SPEED) + 1;
            numCars++;
        }

        // Move cars
        for (i = 0; i < numCars; i++) {
            int distanceToNextCar = MAX_CARS;

            // Find distance to next car
            for (j = i + 1; j < numCars; j++) {
                if (cars[j].position > cars[i].position) {
                    distanceToNextCar = cars[j].position - cars[i].position;
                    break;
                }
            }

            // Accelerate
            if (cars[i].speed < distanceToNextCar - MIN_CAR_DISTANCE && cars[i].speed < MAX_CAR_SPEED) {
                cars[i].speed++;
            }

            // Decelerate
            if (trafficLight == RED && cars[i].position < TRAFFIC_LIGHT_PERIOD && cars[i].speed > 0) {
                cars[i].speed--;
            }

            // Move
            cars[i].position += cars[i].speed;
        }

        // Check for collisions
        for (i = 0; i < numCars; i++) {
            for (j = i + 1; j < numCars; j++) {
                if (cars[i].position == cars[j].position) {
                    printf("Collision at time %d between car %d and car %d!\n", time, i + 1, j + 1);
                    return 0;
                }
            }
        }

        // Print road
        for (i = 0; i < 80; i++) {
            char c = '-';
            for (j = 0; j < numCars; j++) {
                if (cars[j].position == i) {
                    c = 'o';
                    break;
                }

                if (trafficLight == RED && i == TRAFFIC_LIGHT_PERIOD) {
                    c = 'X';
                }
            }

            printf("%c", c);
        }
        printf("\n");

        // Change traffic light
        if (time % 20 == 0) {
            if (trafficLight == RED) {
                trafficLight = GREEN;
            } else {
                trafficLight = RED;
            }
        }

        // Sleep for a bit to slow down the simulation
        usleep(500000);
    }

    return 0;
}