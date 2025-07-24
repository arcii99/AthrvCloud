//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SPEED 60     // Maximum speed a vehicle can travel in km/hr
#define MIN_SPEED 5      // Minimum speed a vehicle can travel in km/hr
#define MAX_DISTANCE 50  // Maximum distance between two vehicles in meters
#define MIN_DISTANCE 1   // Minimum distance between two vehicles in meters
#define ROAD_LENGTH 1000 // Length of the simulated road in meters
#define MAX_VEHICLES 50  // Maximum number of vehicles on the road
#define MAX_TIME 5       // Maximum time for the simulation to run in minutes

// Structure to hold information about a vehicle
typedef struct {
    int id;
    int position;
    int speed;
} Vehicle;

// Function to generate a new vehicle with a random speed and position
Vehicle new_vehicle(int id) {
    Vehicle v;
    v.id = id;
    v.speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
    v.position = (rand() % (ROAD_LENGTH - MAX_DISTANCE - 1)) + MAX_DISTANCE;
    return v;
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    Vehicle vehicles[MAX_VEHICLES];
    int num_vehicles = 0;

    int time = 0;  // Current time in minutes
    while(time < MAX_TIME) {
        // Generate a new vehicle with a probability of 20%
        if((float)rand()/(float)RAND_MAX > 0.8 && num_vehicles < MAX_VEHICLES) {
            vehicles[num_vehicles] = new_vehicle(num_vehicles);
            num_vehicles++;
        }

        // Update the position of each vehicle based on their speed and the time elapsed
        for(int i=0; i<num_vehicles; i++) {
            vehicles[i].position += (vehicles[i].speed * 1000 / 60) * 1; // 1 represents 1 second

            // Check if the vehicle has crossed the end of the road
            if(vehicles[i].position > ROAD_LENGTH) {
                vehicles[i].position = 0 - (rand() % MAX_DISTANCE);
            }
        }

        // Print the current state of the road
        printf("Time: %d minutes\n", time);
        printf("Road length: %d meters\n", ROAD_LENGTH);
        printf("Number of vehicles: %d\n", num_vehicles);
        printf("ID\tPosition\tSpeed\n");
        for(int i=0; i<num_vehicles; i++) {
            printf("%d\t%d\t%d\n", vehicles[i].id, vehicles[i].position, vehicles[i].speed);
        }
        printf("\n");

        // Sleep for 1 second to represent the passing of 1 minute
        sleep(1);

        time++;
    }

    return 0;
}