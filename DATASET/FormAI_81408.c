//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 60  // Maximum speed limit of the roads
#define MAX_CARS 20   // Maximum number of cars on the road
#define MAX_TIME 120  // Maximum simulation time in seconds

#define CAR_LENGTH 5  // Length of a car in meters
#define GAP_LENGTH 10 // Gap between two cars in meters

int main() {
    srand(time(NULL));       // Seed for random number generation
    
    int simulation_time = 0;  // Total time elapsed in the simulation
    int car_count = 0;        // Number of cars on the road
    int car_speeds[MAX_CARS]; // Speeds of each car on the road
    int car_positions[MAX_CARS]; // Positions of each car on the road
    
    while (simulation_time < MAX_TIME) {
        // Generate a new car with random speed
        if (rand() < RAND_MAX * 0.1 && car_count < MAX_CARS) {
            car_positions[car_count] = 0;
            car_speeds[car_count] = rand() % (MAX_SPEED + 1);
            car_count++;
        }
        
        // Update position of each car based on their speed and gaps
        for (int i = 0; i < car_count; i++) {
            int next_car_position = MAX_TIME * car_speeds[i] + CAR_LENGTH; // Position of the next car
            if (i == car_count - 1) {
                next_car_position = MAX_TIME; // Last car has no next car
            } else {
                next_car_position = car_positions[i+1] - GAP_LENGTH;
            }
            int new_pos = car_positions[i] + car_speeds[i]; // Calculate new position
            car_positions[i] = (new_pos < next_car_position) ? new_pos : next_car_position; // Check for collisions
        }
        
        // Print the current state of the road at every second
        printf("Time: %ds\n", simulation_time);
        for (int i = 0; i < car_count; i++) {
            for (int j = 0; j < car_positions[i]; j++) {
                printf(" "); // Print empty spaces before the car's position
            }
            printf("+"); // Print the car
        }
        printf("\n\n");
        
        // Increment simulation time
        simulation_time++;
    }
    
    return 0;
}