//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_LENGTH 100
#define MAX_CARS 20
#define MAX_SPEED 5

// Car structure
typedef struct Car {
    int id;
    int speed;
    int position;
} Car;

// Traffic lane structure
typedef struct Lane {
    int length;
    Car cars[MAX_CARS];
} Lane;

// Initialize the lane with cars at random positions and speeds
void initLane(Lane *lane) {
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < MAX_CARS; i++) {
        int position = rand() % lane->length;
        int speed = rand() % MAX_SPEED + 1;

        lane->cars[i] = (Car) { i, speed, position };
    }
}

// Move the car forward by its speed
void moveCar(Lane *lane, int index) {
    Car *car = &lane->cars[index];
    car->position += car->speed;

    if (car->position >= lane->length) {
        car->position = car->position % lane->length;
    }
}

// Update the position of all the cars in the lane
void updateLane(Lane *lane) {
    // Move the cars forward
    for (int i = 0; i < MAX_CARS; i++) {
        moveCar(lane, i);
    }

    // Check for collisions
    for (int i = 0; i < MAX_CARS; i++) {
        Car *car1 = &lane->cars[i];
        
        for (int j = i + 1; j < MAX_CARS; j++) {
            Car *car2 = &lane->cars[j];
            
            if (car1->position == car2->position) {
                // Update the speeds of the cars to avoid collision
                int temp = car1->speed;
                car1->speed = car2->speed;
                car2->speed = temp;
            }
        }
    }
}

// Print the state of the lane
void printLane(Lane *lane) {
    char laneState[LANE_LENGTH];
    for (int i = 0; i < lane->length; i++) {
        laneState[i] = '-';
    }

    for (int i = 0; i < MAX_CARS; i++) {
        Car *car = &lane->cars[i];
        laneState[car->position] = '0' + car->id;
    }

    printf("%s\n", laneState);
}

int main() {
    Lane lane = { LANE_LENGTH };
    initLane(&lane);

    while (1) {
        system("clear");
        updateLane(&lane);
        printLane(&lane);
        usleep(500000); // Wait for 500 milliseconds
    }

    return 0;
}