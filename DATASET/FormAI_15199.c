//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the max speed of the vehicle
#define MAX_SPEED 100

/* Vehicle struct that stores information about the remote control vehicle */
typedef struct {
    int speed;
    int battery;
    int distance;
} Vehicle;

int main() {
    // Set the seed for rand to the current time
    srand(time(NULL));

    // Initialize a new vehicle with a speed of 0, full battery (100%), and distance of 0
    Vehicle rc_vehicle = {0, 100, 0};

    // Print introductory message
    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    // Begin the simulation loop
    while (rc_vehicle.battery > 0) {
        // Generate a random speed between 0 and MAX_SPEED for the vehicle
        rc_vehicle.speed = rand() % (MAX_SPEED + 1);

        // Generate a random distance between 0 and 20 for the vehicle
        rc_vehicle.distance = rand() % 21;

        // Decrement the vehicle's battery by the amount of distance traveled
        rc_vehicle.battery -= rc_vehicle.distance;

        // Print the current status of the vehicle
        printf("Vehicle Status:\n");
        printf("Speed: %d\n", rc_vehicle.speed);
        printf("Battery: %d%%\n", rc_vehicle.battery);
        printf("Distance Traveled: %d meters\n", rc_vehicle.distance);

        // If the vehicle's battery is less than or equal to 0, end the simulation
        if (rc_vehicle.battery <= 0) {
            printf("Vehicle has run out of battery. Simulation Over!\n");
        }

        // Wait for some time before continuing the simulation
        printf("\nPress any key to continue...");
        getchar();
        system("clear");
    }

    return 0;
}