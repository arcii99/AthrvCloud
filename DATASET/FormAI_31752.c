//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Global variables
int fuel = 100;
int location = 0;
int distance_to_planet = 1000;
int speed = 50;

// Function to move spaceship towards planet
void travel() {
    while(distance_to_planet > 0) {
        // Calculate remaining fuel
        fuel -= (speed/10);
        // Calculate remaining distance
        distance_to_planet -= speed;
        // Update spaceship location
        location += speed;
        printf("Distance to planet: %dkm\tFuel: %d liters\tLocation: %dkm\n", distance_to_planet, fuel, location);
        usleep(500000);
    }
}

// Function to refuel spaceship
void refuel() {
    while(fuel < 100) {
        fuel += 10;
        printf("Refueling... fuel: %d\n", fuel);
        usleep(500000);
    }
    printf("Fueling complete!\n");
}

// Main function
int main() {
    // Create threads
    pthread_t travel_thread;
    pthread_t refuel_thread;
    
    // Create travel thread
    if(pthread_create(&travel_thread, NULL, (void*)travel, NULL)) {
        fprintf(stderr, "Error creating travel thread");
        return 1;
    }
    
    // Create refuel thread
    if(pthread_create(&refuel_thread, NULL, (void*)refuel, NULL)) {
        fprintf(stderr, "Error creating refuel thread");
        return 1;
    }
    
    // Wait for threads to join
    if(pthread_join(travel_thread, NULL)) {
        fprintf(stderr, "Error joining travel thread");
        return 1;
    }
    
    if(pthread_join(refuel_thread, NULL)) {
        fprintf(stderr, "Error joining refuel thread");
        return 1;
    }
    
    // Print successful landing message
    printf("Spaceship successfully landed on planet!\n");
    
    return 0;
}