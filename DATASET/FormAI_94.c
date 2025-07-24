//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for space dimensions
#define SPACE_WIDTH 10
#define SPACE_HEIGHT 10
#define SPACE_DEPTH 10

// Define a struct to represent a point in space
typedef struct {
    int x;
    int y;
    int z;
} Point;

// Define a function to generate a random point in space
Point generate_random_point() {
    Point p;
    p.x = rand() % SPACE_WIDTH;
    p.y = rand() % SPACE_HEIGHT;
    p.z = rand() % SPACE_DEPTH;
    return p;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a starting point for the mission
    Point starting_point = generate_random_point();
    
    // Print out the mission information
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Your mission is to explore the galaxy and find a rare metal.\n");
    printf("You will start at point (%d, %d, %d).\n", starting_point.x, starting_point.y, starting_point.z);
    
    // Start the game loop
    Point current_point = starting_point;
    int steps_taken = 0;
    while (1) {
        // Generate a random direction to move in
        int direction = rand() % 6;
        switch (direction) {
            case 0: // Move up
                if (current_point.y < SPACE_HEIGHT - 1) {
                    current_point.y++;
                    steps_taken++;
                }
                break;
            case 1: // Move down
                if (current_point.y > 0) {
                    current_point.y--;
                    steps_taken++;
                }
                break;
            case 2: // Move north
                if (current_point.z < SPACE_DEPTH - 1) {
                    current_point.z++;
                    steps_taken++;
                }
                break;
            case 3: // Move south
                if (current_point.z > 0) {
                    current_point.z--;
                    steps_taken++;
                }
                break;
            case 4: // Move east
                if (current_point.x < SPACE_WIDTH - 1) {
                    current_point.x++;
                    steps_taken++;
                }
                break;
            case 5: // Move west
                if (current_point.x > 0) {
                    current_point.x--;
                    steps_taken++;
                }
                break;
        }
        
        // Check if we have found the rare metal
        if (current_point.x == 0 && current_point.y == 0 && current_point.z == 0) {
            printf("Congratulations! You have found the rare metal in %d steps.\n", steps_taken);
            break;
        }
        
        // Check if we have run out of steps and lost the game
        if (steps_taken >= 100) {
            printf("You have run out of steps and failed to find the rare metal.\n");
            break;
        }
    }
    
    return 0;
}