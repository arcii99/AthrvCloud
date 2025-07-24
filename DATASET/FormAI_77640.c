//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between given range
int rand_range(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to check if given array contains given number
int contains(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Seed for random number generation
    srand(time(NULL));
    
    // Constants for timing lights
    const int GREEN_TIME = 10;
    const int YELLOW_TIME = 3;
    const int RED_TIME = 10;
    
    // Constants for intersection traffic
    const int NORTH_SOUTH = 0;
    const int EAST_WEST = 1;
    
    // Initialize variables
    int time_elapsed = 0;
    int cars_waiting[2] = {0, 0}; // Number of cars waiting at each traffic direction
    
    // Loop until program is terminated
    while (1) {
        // Check if there are any cars waiting
        if (cars_waiting[NORTH_SOUTH] == 0 && cars_waiting[EAST_WEST] == 0) {
            printf("No cars waiting.\n");
            continue;
        }
        
        // Randomly choose which direction should have green light
        int green_direction = rand_range(NORTH_SOUTH, EAST_WEST);
        printf("Green light for %s.\n", green_direction == NORTH_SOUTH ? "North-South" : "East-West");
        
        // Light is green for GREEN_TIME seconds
        for (int i = 0; i < GREEN_TIME; i++) {
            time_elapsed++;
            
            // Check if any cars arrive during green light
            if (rand_range(0, 1) == 1) {
                cars_waiting[green_direction]++;
                printf("Car arrived at %s during green light.\n", green_direction == NORTH_SOUTH ? "North-South" : "East-West");
            }
            
            // Check if time is up
            if (time_elapsed >= GREEN_TIME + YELLOW_TIME + RED_TIME) {
                break;
            }
        }
        
        // Light is yellow for YELLOW_TIME seconds
        printf("Yellow light.\n");
        for (int i = 0; i < YELLOW_TIME; i++) {
            time_elapsed++;
            
            // Check if any cars arrive during yellow light
            if (rand_range(0, 2) == 1) {
                cars_waiting[green_direction]++;
                printf("Car arrived at %s during yellow light.\n", green_direction == NORTH_SOUTH ? "North-South" : "East-West");
            }
            
            // Check if time is up
            if (time_elapsed >= GREEN_TIME + YELLOW_TIME + RED_TIME) {
                break;
            }
        }
        
        // Light is red for RED_TIME seconds
        printf("Red light.\n");
        for (int i = 0; i < RED_TIME; i++) {
            time_elapsed++;
            
            // Check if any cars arrive during red light
            if (rand_range(0, 3) == 1) {
                int direction = rand_range(NORTH_SOUTH, EAST_WEST);
                if (!contains(cars_waiting, 2, direction)) {
                    cars_waiting[direction]++;
                    printf("Car arrived at %s during red light.\n", direction == NORTH_SOUTH ? "North-South" : "East-West");
                }
            }
            
            // Check if time is up
            if (time_elapsed >= GREEN_TIME + YELLOW_TIME + RED_TIME) {
                break;
            }
        }
        
        // Clear cars waiting in green direction
        cars_waiting[green_direction] = 0;
    }
    
    return 0;
}