//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate traffic light behavior
// Returns 1 if green light, 0 if red light
int traffic_light(int time)
{
    int green_time = 30; // Green light time in seconds
    int cycle_time = 60; // Cycle time in seconds (green + red)

    if (time % cycle_time < green_time) {
        return 1; // Green light
    } else {
        return 0; // Red light
    }
}

int main()
{
    srand(time(NULL));

    // Initializing variables
    int num_cars = rand() % 21; // Random number of cars between 0 and 20
    int speed = rand() % 61 + 40; // Random speed between 40 and 100 km/h
    int time = 0; // Starting time
    int time_step = 1; // Time step for simulation
    int position[num_cars]; // Array to store position of each car
    int i;

    // Initializing car positions randomly
    for (i = 0; i < num_cars; i++) {
        position[i] = rand() % 1001 - 2000; // Random position between -2000 and 1000 meters
    }

    // Simulating traffic flow for 1 hour (3600 seconds)
    while (time < 3600) {
        int green_light = traffic_light(time); // Check if traffic light is green

        // Updating positions of cars based on speed and traffic light
        for (i = 0; i < num_cars; i++) {
            if (position[i] >= -2000 && position[i] < 0 && !green_light) {
                // Car waiting at red light
            } else {
                position[i] += speed * time_step / 3600;
            }
        }

        // Checking for collisions
        for (i = 0; i < num_cars; i++) {
            int j;
            for (j = i + 1; j < num_cars; j++) {
                if (abs(position[i] - position[j]) < 50) { // Collision if distance between cars less than 50 meters
                    printf("Collision at time %d seconds between car %d and car %d!\n", time, i + 1, j + 1);
                    return 0;
                }
            }
        }

        time += time_step; // Incrementing time
    }

    printf("No collisions occurred in 1 hour.\n");

    return 0;
}