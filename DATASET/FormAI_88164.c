//FormAI DATASET v1.0 Category: Robot movement control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10 // Size of the map
#define MAX_STEPS 100 // Maximum number of steps the robot can take
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int map[MAP_SIZE][MAP_SIZE] = {0}; // Create the map
    int x = rand() % MAP_SIZE; // Initial x-coordinate position of the robot
    int y = rand() % MAP_SIZE; // Initial y-coordinate position of the robot
    int steps = 0; // Number of steps taken by the robot
    int direction = rand() % 4; // Initial direction of the robot
    
    while(steps < MAX_STEPS) {
        // Print the map with the robot's current position
        for(int i=0; i<MAP_SIZE; i++) {
            for(int j=0; j<MAP_SIZE; j++) {
                if(i==x && j==y) printf("+"); // Print the robot's position
                else printf("%d", map[i][j]); // Print the map
            }
            printf("\n");
        }
        
        // Check if the robot is at the edge of the map
        if(x==0 || x==MAP_SIZE-1 || y==0 || y==MAP_SIZE-1) {
            printf("Robot reached the edge of the map!");
            break; // Exit the loop
        }
        
        // Move the robot in the current direction
        if(direction == NORTH) x--;
        if(direction == EAST) y++;
        if(direction == SOUTH) x++;
        if(direction == WEST) y--;
        
        steps++; // Increment the number of steps taken
        
        // Check if the robot hit a wall
        if(map[x][y] == 1) {
            printf("Robot hit a wall!");
            break; // Exit the loop
        }
        
        // Mark the current location as visited
        map[x][y] = 1;
        
        // Randomly change the direction of the robot
        direction = rand() % 4;
    }
    
    printf("Robot stopped after taking %d steps.\n", steps);
    
    return 0;
}