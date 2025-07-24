//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 60
#define MIN_GAP 2
#define MAX_GAP 5

// Define the struct for Car
typedef struct Car {
    int id; // ID of the car
    int speed; // Speed of the car in km/hr
    int position; // Position of the car on the road in km
} Car;

// Function to print the cars on the road
void printCarsOnRoad(Car *cars, int numCars, int roadLength) {
    // Create an array to represent the road
    char road[roadLength+1];
    int i;

    // Initialize the road to be empty
    for (i = 0; i < roadLength; i++) {
        road[i] = '-';
    }
    road[roadLength] = '\0';

    // Add the cars to the road
    for (i = 0; i < numCars; i++) {
        int pos = cars[i].position;
        if (pos >= 0 && pos < roadLength) {
            char id = cars[i].id + '0';
            road[pos] = id;
        }
    }

    // Print the road
    printf("%s\n", road);
}

// Function to simulate the traffic flow
void simulateTrafficFlow(int numCars, int roadLength) {
    // Create an array of cars
    Car cars[numCars];

    // Initialize the cars
    int i;
    for (i = 0; i < numCars; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].position = rand() % roadLength;
    }

    // Sort the cars by position
    int j;
    for (i = 0; i < numCars; i++) {
        for (j = i + 1; j < numCars; j++) {
            if (cars[i].position > cars[j].position) {
                Car temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }
        }
    }

    // Print the initial state of the road
    printf("Initial State:\n");
    printCarsOnRoad(cars, numCars, roadLength);

    // Simulate the traffic flow
    int time = 1;
    while (1) {
        // Update the positions of the cars
        for (i = 0; i < numCars; i++) {
            // Calculate the gap between this car and the one in front
            int gap = -1;
            for (j = i + 1; j < numCars; j++) {
                if (cars[j].position > cars[i].position) {
                    gap = cars[j].position - cars[i].position - 1;
                    break;
                }
            }
            if (gap == -1) {
                gap = roadLength - cars[i].position - 1;
            }

            // Calculate the new speed of the car based on the gap
            int newSpeed = cars[i].speed;
            if (gap > MIN_GAP) {
                newSpeed = (gap - MIN_GAP) / MAX_GAP + 1;
                if (newSpeed > cars[i].speed) {
                    newSpeed = cars[i].speed + 1;
                }
            }
            if (newSpeed > MAX_SPEED) {
                newSpeed = MAX_SPEED;
            }

            // Calculate the new position of the car based on the speed
            int pos = cars[i].position + newSpeed;
            if (pos >= roadLength) {
                pos = pos - roadLength;
            }

            // Set the new speed and position of the car
            cars[i].speed = newSpeed;
            cars[i].position = pos;
        }

        // Sort the cars by position
        for (i = 0; i < numCars; i++) {
            for (j = i + 1; j < numCars; j++) {
                if (cars[i].position > cars[j].position) {
                    Car temp = cars[i];
                    cars[i] = cars[j];
                    cars[j] = temp;
                }
            }
        }

        // Print the state of the road
        printf("\nTime: %d\n", time);
        printCarsOnRoad(cars, numCars, roadLength);

        // Check if all the cars have stopped
        int allStopped = 1;
        for (i = 0; i < numCars; i++) {
            if (cars[i].speed > 0) {
                allStopped = 0;
                break;
            }
        }
        if (allStopped) {
            printf("\nAll the cars have stopped.\n");
            break;
        }

        // Increment time
        time++;
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Simulate the traffic flow with 10 cars on a 50km road
    simulateTrafficFlow(10, 50);

    return 0;
}