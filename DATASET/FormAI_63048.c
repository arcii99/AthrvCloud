//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 20 // Maximum number of cars on the road
#define MAX_SPEED 120 // Maximum speed limit in km/hr
#define MAX_DISTANCE 1000 // Maximum distance of the road in meters

// Car struct that contains information about a car on the road
typedef struct {
    int speed;
    int position;
} Car;

int main() {
    // Initialize variables
    Car cars[MAX_CARS];
    int num_cars = 5;
    int distance = MAX_DISTANCE;
    int time = 0;

    // Place initial cars on the road randomly
    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].position = rand() % distance;
    }

    // Simulate traffic flow until all cars have reached the end of the road
    while (num_cars > 0) {
        // Print current positions of the cars
        printf("Time %d:\n", time);
        for (int i = 0; i < num_cars; i++) {
            printf("Car %d: Position = %d, Speed = %dkm/hr\n", i+1, cars[i].position, cars[i].speed);
        }
        printf("\n");

        // Move each car based on its speed and the distance to the car in front of it
        for (int i = 0; i < num_cars; i++) {
            int distance_to_next_car = MAX_DISTANCE;
            for (int j = 0; j < num_cars; j++) {
                if (i == j) continue;
                if (cars[j].position > cars[i].position &&
                    cars[j].position - cars[i].position < distance_to_next_car) {
                    distance_to_next_car = cars[j].position - cars[i].position;
                }
            }
            if (distance_to_next_car > cars[i].speed) {
                cars[i].position += cars[i].speed;
            } else {
                cars[i].position += distance_to_next_car;
            }
        }

        // Remove cars that have reached the end of the road
        int i = 0;
        while (i < num_cars) {
            if (cars[i].position >= distance) {
                num_cars--;
                for (int j = i; j < num_cars; j++) {
                    cars[j] = cars[j+1];
                }
            } else {
                i++;
            }
        }

        // Increment time
        time++;
    }

    // Print final results
    printf("All cars have reached the end of the road after %d seconds.\n", time);

    return 0;
}