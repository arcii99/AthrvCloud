//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables
int MAX_CARS = 50;
int SPEED_LIMIT = 60;

// Define car struct
struct Car {
    int id;
    int position;
    int speed;
};

// Function to generate a random speed between 40 and 80 km/h
int generateRandomSpeed() {
    return (rand() % (80 - 40 + 1)) + 40;
}

int main() {
    // Set seed for random number generation
    srand(time(NULL));
    
    // Initialize array of cars
    struct Car cars[MAX_CARS];
    
    // Initialize cars with random positions and speeds
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].id = i + 1;
        cars[i].position = generateRandomSpeed() * -1; // Start from the back of the road
        cars[i].speed = generateRandomSpeed();
    }
    
    // Initialize time variable
    int time = 0;
    
    // Simulation loop
    while (1) {
        // Clear the screen
        system("clear");
        
        // Print road with cars
        for (int i = 0; i < MAX_CARS; i++) {
            printf("%c", cars[i].position >= 0 ? 'C' : '-'); // Car or empty space
        }
        
        // Update car positions and speeds
        for (int i = 0; i < MAX_CARS; i++) {
            if (cars[i].position >= 0) { // Only update if car is on the road
                // Calculate distance to next car
                int distanceToNextCar = MAX_CARS; // Assume no car in front
                for (int j = i + 1; j < MAX_CARS; j++) {
                    if (cars[j].position >= 0) { // Only consider cars on the road
                        distanceToNextCar = j - i;
                        break;
                    }
                }
                
                // Change speed based on distance to next car
                if (distanceToNextCar > cars[i].speed) {
                    cars[i].speed++; // Car can speed up
                } else if (distanceToNextCar <= cars[i].speed) {
                    cars[i].speed = distanceToNextCar - 1; // Car slows down to avoid collision
                }
                
                // Update position based on speed
                cars[i].position += cars[i].speed;
                
                // Check for collision with next car
                if (distanceToNextCar == 1 && cars[i].speed > cars[i + 1].speed && cars[i].position >= cars[i + 1].position) {
                    // Collision! Slow down both cars
                    cars[i].speed = cars[i + 1].speed - 1;
                    cars[i + 1].speed = cars[i].speed - 1;
                }
                
                // Check for collision with end of road
                if (cars[i].position >= MAX_CARS) {
                    cars[i].position = -1; // Car has left the road
                }
            }
        }
        
        // Update time
        time++;
        
        // Print time and number of cars on the road
        printf("\nTime: %d\nCars on the road: %d\n", time, MAX_CARS - (int)(sizeof(cars) / sizeof(struct Car)));
        
        // Sleep for 1 second
        usleep(1000000);
    }
    
    return 0;
}