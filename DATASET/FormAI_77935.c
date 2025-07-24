//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_CARS 100
#define MAX_SPEED 60
#define MAX_LANE 3
#define CAR_LENGTH 5
#define CAR_DISTANCE 20
#define UPDATE_RATE 500 // milliseconds

// Define the structure of a car
struct Car {
    int position;
    int lane;
    int speed;
};

// Prototype of function to update car position
void update_position(struct Car *car_arr);

int main(void) {
    struct Car car_arr[NUM_OF_CARS]; // Array of cars
    srand(time(NULL)); // Seed random number generator
    
    // Initialize cars
    for (int i = 0; i < NUM_OF_CARS; i++) {
        car_arr[i].position = i * CAR_DISTANCE; // Equally spaced cars
        car_arr[i].lane = rand() % MAX_LANE; // Random lane
        car_arr[i].speed = (rand() % MAX_SPEED) + 1; // Random speed
    }
    
    // Simulate traffic flow
    while (1) {
        system("clear"); // Clear terminal
        
        // Print current traffic situation
        for (int i = 0; i < NUM_OF_CARS; i++) {
            for (int j = 0; j < MAX_LANE; j++) {
                if (car_arr[i].lane == j) {
                    for (int k = 0; k < car_arr[i].position; k++) {
                        printf(" ");
                    }
                    printf("car");
                    for (int k = car_arr[i].position + CAR_LENGTH; k < (j+1)*150; k++) {
                        printf(" ");
                    }
                    printf("\n");
                }
            }
        }
        
        // Update car position
        update_position(car_arr);
        
        // Wait before updating again
        usleep(UPDATE_RATE * 1000);
    }
    
    return 0;
}

// Function to update car position
void update_position(struct Car *car_arr) {
    int distance;
    for (int i = 0; i < NUM_OF_CARS; i++) {
        // Calculate the distance between this car and the one in front of it
        distance = car_arr[i].position - car_arr[(i-1+NUM_OF_CARS)%NUM_OF_CARS].position;
        if (distance < CAR_DISTANCE + CAR_LENGTH) {
            // If too close, slow down
            car_arr[i].speed = distance - CAR_LENGTH;
        } else if (car_arr[i].speed < MAX_SPEED) {
            // Otherwise, accelerate
            car_arr[i].speed++;
        }
        
        // Update car position based on speed
        car_arr[i].position += car_arr[i].speed;
    }
}