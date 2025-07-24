//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CARS 100         // Maximum number of cars that can be on the road
#define TOTAL_TIME 3600      // Total time of simulation (in seconds)
#define SPEED_LIMIT 40       // Speed limit on the road (in km/h)
#define CAR_LENGTH 4         // Length of each car (in meters)
#define INTERSECTION_LENGTH 8 // Length of the intersection (in meters)

// Function to generate a randomly chosen number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the distance travelled by a car in one second
double distance_travelled(double speed) {
    return (speed * 1000) / 3600;
}

// Function to simulate the movement of cars for one second
void simulate_one_second(int num_cars, double speeds[], double positions[]) {
    // Move each car
    for (int i = 0; i < num_cars; i++) {
        // Calculate the distance travelled by the car in one second
        double distance = distance_travelled(speeds[i]);
        // Calculate the new position of the car
        double new_pos = positions[i] + distance;
        // Check if the car has reached the end of the road
        if (new_pos >= 1000) {
            // Car has exited the road
            speeds[i] = 0;
            positions[i] = 0;
        } else {
            // Update the position of the car
            positions[i] = new_pos;
        }
    }
    // Check if any car has collided with another car
    for (int i = 0; i < num_cars - 1; i++) {
        for (int j = i + 1; j < num_cars; j++) {
            if (positions[j] - positions[i] <= CAR_LENGTH) {
                // Cars have collided
                speeds[i] = 0;
                speeds[j] = 0;
            }
        }
    }
}

// Function to simulate the movement of cars through an intersection
void simulate_intersection(int num_cars, double speeds[], double positions[]) {
    int green_light_pos = random_number(500, 700); // Position of green light
    int yellow_light_pos = green_light_pos + INTERSECTION_LENGTH; // Position of yellow light
    // Move cars through intersection
    for (int i = 0; i < num_cars; i++) {
        if (positions[i] >= green_light_pos && positions[i] < yellow_light_pos) {
            // Car is passing through green light
            speeds[i] = SPEED_LIMIT;
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Initialize the speeds and positions of cars
    double speeds[MAX_CARS] = {0};
    double positions[MAX_CARS] = {0};
    int num_cars = 0;
    // Generate the initial set of cars randomly
    while (num_cars < MAX_CARS) {
        // Generate random speed and position
        double speed = random_number(1, SPEED_LIMIT);
        double pos = random_number(1, 1000);
        // Check if the new car will collide with an existing car
        bool will_collide = false;
        for (int i = 0; i < num_cars; i++) {
            if (pos - positions[i] <= CAR_LENGTH) {
                will_collide = true;
                break;
            }
        }
        // Add the car if it will not collide with an existing car
        if (!will_collide) {
            speeds[num_cars] = speed;
            positions[num_cars] = pos;
            num_cars++;
        }
    }
    // Run the simulation
    for (int t = 0; t < TOTAL_TIME; t++) {
        // Simulate the movement of cars for one second
        simulate_one_second(num_cars, speeds, positions);
        // Simulate the movement of cars through the intersection
        simulate_intersection(num_cars, speeds, positions);
    }
    // Print the final positions of all cars
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d: %.2f meters\n", i+1, positions[i]);
    }
    return 0;
}