//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LANES 3
#define MAX_SPEED 60

// A car structure to hold its position and speed
typedef struct Car {
    int speed;
    int position;
} Car;

// Function to initiate a car's attributes
void init_car(Car *car) {
    car->speed = rand() % (MAX_SPEED + 1);
    car->position = 0;
}

// Function to check for collision
int check_collision(Car *car, Car *other_car) {
    if (car->position == other_car->position) {
        if (car->speed > other_car->speed) {
            other_car->position--;
            return 1;
        } else {
            car->position--;
            return 1;
        }
    }
    return 0;
}

// Function to move a car forward
void move_car(Car *car) {
    car->position += car->speed;
}

// Main function for running the traffic simulation
int main() {
    srand(time(NULL)); // Set seed for random number generator

    Car lanes[MAX_LANES][MAX_SPEED];

    for (int i = 0; i < MAX_LANES; i++) {
        for (int j = 0; j < MAX_SPEED; j++) {
            init_car(&lanes[i][j]);
        }
    }

    int tick = 0;
    int collisions = 0;
    int cars_moved = 0;

    // Loop to simulate a certain number of ticks
    while (tick < 100) {
        // Loop through all cars to check for collisions and move them forward
        for (int i = 0; i < MAX_LANES; i++) {
            for (int j = 0; j < MAX_SPEED; j++) {
                Car *car = &lanes[i][j];

                // Check for collision with cars in the same lane
                for (int k = j + 1; k < MAX_SPEED; k++) {
                    Car *other_car = &lanes[i][k];
                    collisions += check_collision(car, other_car);
                }

                // Check for collision with cars in the adjacent lanes
                if (i > 0) {
                    Car *other_car = &lanes[i-1][j];
                    collisions += check_collision(car, other_car);
                }
                if (i < MAX_LANES-1) {
                    Car *other_car = &lanes[i+1][j];
                    collisions += check_collision(car, other_car);
                }

                move_car(car);
                cars_moved++;
            }
        }
        tick++;
    }

    printf("Total collisions: %d\n", collisions);
    printf("Total cars moved: %d\n", cars_moved);

    return 0;
}