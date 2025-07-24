//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 10
#define NUM_COLS 20
#define NUM_VEHICLES 5

// Function prototypes
void initializeHighway(int highway[NUM_ROWS][NUM_COLS]);
void printHighway(int highway[NUM_ROWS][NUM_COLS]);
void updateHighway(int highway[NUM_ROWS][NUM_COLS]);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create the highway array
    int highway[NUM_ROWS][NUM_COLS];
    
    // Initialize the highway
    initializeHighway(highway);
    
    // Print the initial state of the highway
    printHighway(highway);
    
    // Run the simulation for a certain number of iterations
    int numIterations = 10;
    for (int i = 0; i < numIterations; i++) {
        // Update the highway
        updateHighway(highway);
        
        // Print the updated state of the highway
        printHighway(highway);
    }
    
    return 0;
}

// Function to initialize the highway
void initializeHighway(int highway[NUM_ROWS][NUM_COLS]) {
    // Initialize all cells to 0
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            highway[i][j] = 0;
        }
    }
    
    // Add some vehicles to the highway
    for (int i = 0; i < NUM_VEHICLES; i++) {
        // Choose a random type of vehicle
        int vehicleType = rand() % 2 + 1; // Either 1 or 2
        
        // Choose a random position and speed for the vehicle
        int row = rand() % NUM_ROWS;
        int col = rand() % NUM_COLS;
        int speed = rand() % 5 + 1; // Between 1 and 5
        
        // Add the vehicle to the highway
        highway[row][col] = vehicleType * 10 + speed;
    }
}

// Function to print the highway
void printHighway(int highway[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", highway[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to update the highway
void updateHighway(int highway[NUM_ROWS][NUM_COLS]) {
    // Move each vehicle according to its speed
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            int vehicle = highway[i][j];
            if (vehicle != 0) {
                // Find the next empty cell in front of the vehicle
                int nextRow = i;
                int nextCol = j + vehicle % 10;
                while (nextCol < NUM_COLS && highway[nextRow][nextCol] != 0) {
                    nextCol++;
                }
                
                // Move the vehicle to the next cell
                highway[i][j] = 0;
                if (nextCol < NUM_COLS) {
                    highway[nextRow][nextCol] = vehicle;
                }
            }
        }
    }
}