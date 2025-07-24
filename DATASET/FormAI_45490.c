//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the simulation
#define MAX_TRAFFIC 120
#define MAX_SPEED 100
#define SIM_TIME 60
#define SIM_TICKS 10

// Define the car struct
typedef struct Car {
    int speed;
    int position;
} Car;

// Define the traffic simulation function
void simulate_traffic() {
    // Initialize the cars array
    Car cars[MAX_TRAFFIC];

    // Initialize the random number generator
    srand(time(NULL));

    // Generate random speeds and positions for the cars
    for (int i = 0; i < MAX_TRAFFIC; i++) {
        cars[i].speed = rand() % MAX_SPEED;
        cars[i].position = rand() % SIM_TIME;
    }

    // Run the simulation
    for (int tick = 1; tick <= SIM_TICKS; tick++) {
        printf("Tick %d:\n", tick);

        // Update the positions of the cars
        for (int i = 0; i < MAX_TRAFFIC; i++) {
            cars[i].position += cars[i].speed;

            // Reset the position if it goes over the simulation time limit
            if (cars[i].position > SIM_TIME) {
                cars[i].position = 0;
            }
        }

        // Print the positions of the cars
        for (int i = 0; i < MAX_TRAFFIC; i++) {
            printf("Car %d - Speed: %d, Position: %d\n", i, cars[i].speed, cars[i].position);
        }
    }
}

int main() {
    simulate_traffic();
    return 0;
}