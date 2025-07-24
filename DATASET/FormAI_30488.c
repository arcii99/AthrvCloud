//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of cars on the road
#define MAX_CARS 20

// Define the length of the road
#define ROAD_LENGTH 1000

// Define the speed limit
#define SPEED_LIMIT 60

// Define the time interval for updating the car positions
#define TIME_INTERVAL 1 

// Define the acceleration and deceleration rates
#define ACCELERATION 2
#define DECELERATION 3

// Define the car structure
typedef struct {
    int position;
    int speed;
} Car;

int main() {
    int i, j, k;
    int num_cars = 0;
    Car cars[MAX_CARS];

    // Initialize random number generator
    srand(time(NULL));

    // Generate a random number of cars between 5 and MAX_CARS
    num_cars = rand() % (MAX_CARS - 5 + 1) + 5;

    // Initialize cars' position and speed
    for (i = 0; i < num_cars; i++) {
        cars[i].position = rand() % ROAD_LENGTH;
        cars[i].speed = rand() % (SPEED_LIMIT + 1);
    }

    // Simulate traffic flow for 10 time intervals
    for (i = 0; i < 10; i++) {
        // Print the current positions and speeds of all cars
        printf("Time Interval %d\n", i + 1);
        for (j = 0; j < num_cars; j++) {
            printf("Car %d: Position = %d, Speed = %d\n", j + 1, cars[j].position, cars[j].speed);
        }
        printf("\n");

        // Update the position and speed of each car based on its distance from the car in front of it
        for (j = 0; j < num_cars; j++) {
            int distance = ROAD_LENGTH;
            for (k = 0; k < num_cars; k++) {
                if (k == j) {
                    continue;
                }
                int d = cars[k].position - cars[j].position;
                if (d < 0) {
                    d += ROAD_LENGTH;
                }
                if (d < distance) {
                    distance = d;
                }
            }
            
            if (distance == ROAD_LENGTH) {
                // No car in front, speed up by acceleration rate
                cars[j].speed = cars[j].speed + ACCELERATION;
            } else {
                // Decelerate if the distance to the car in front is smaller than the current speed, otherwise speed up by acceleration rate
                if (distance < cars[j].speed) {
                    cars[j].speed = cars[j].speed - DECELERATION;
                } else {
                    cars[j].speed = cars[j].speed + ACCELERATION;
                }
            }

            // Apply speed limit
            if (cars[j].speed > SPEED_LIMIT) {
                cars[j].speed = SPEED_LIMIT;
            }

            // Calculate the new position of the car
            cars[j].position = cars[j].position + cars[j].speed * TIME_INTERVAL;
            if (cars[j].position > ROAD_LENGTH) {
                cars[j].position -= ROAD_LENGTH;
            }
        }
    }

    return 0;
}