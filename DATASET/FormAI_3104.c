//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxRoadSize 10 // Maximum size of the road in the traffic flow
#define maxVehicleSpeed 5 // Maximum speed of a vehicle

int main() {
    int road[maxRoadSize]; // Creating a road array with a maximum size of 10
    int vehiclePosition = 0; // Initializing the position of the first vehicle
    int numOfVehicles = 5; // Total number of vehicles in the traffic flow

    srand(time(0)); // Seed the random number generator with time

    // Initializing the road array with 0 to indicate an empty space
    for(int i=0; i<maxRoadSize; i++) {
        road[i] = 0;
    }

    // Randomly assigning initial positions to the vehicles
    for(int i=1; i<=numOfVehicles; i++) {
        int randPos = rand() % maxRoadSize;
        while(road[randPos]) {
            randPos = rand() % maxRoadSize;
        }
        road[randPos] = i;
    }

    // Printing the initial traffic flow
    printf("Initial Traffic Flow:\n");
    for(int i=0; i<maxRoadSize; i++) {
        printf("%d ", road[i]);
    }
    printf("\n");

    // Moving the vehicles in the traffic flow
    for(int i=1; i<=maxVehicleSpeed; i++) {
        for(int j=0; j<maxRoadSize; j++) {
            int currentVehicle = road[j];
            if(currentVehicle) {
                int newPos = j + i; // New position of the vehicle after moving
                if(newPos >= maxRoadSize) { // If the vehicle goes out of the road
                    road[j] = 0; // Remove the vehicle from the current position
                }
                else { // If the vehicle stays on the road
                    road[j] = 0; // Remove the vehicle from the current position
                    if(road[newPos]) { // If there is already another vehicle at the new position
                        road[j] = currentVehicle; // Stay in the current position
                    }
                    else { // If the new position is empty
                        road[newPos] = currentVehicle; // Move to the new position
                    }
                }
            }
        }

        // Printing the current traffic flow
        printf("Traffic Flow after %d second(s):\n", i);
        for(int j=0; j<maxRoadSize; j++) {
            printf("%d ", road[j]);
        }
        printf("\n");

        // Checking if the first vehicle has reached the end of the road
        if(road[maxRoadSize-1] == 1) {
            printf("Game Over! The first vehicle has reached the end of the road.\n");
            break;
        }
    }

    return 0; // End of the simulation
}