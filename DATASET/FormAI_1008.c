//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandomNumber(int lower, int upper);
void simulateCarMovement(int distance);

int main()
{
    int obstacleDistance = generateRandomNumber(10, 20);
    printf("Obstacle distance ahead: %d\n", obstacleDistance);
    
    simulateCarMovement(obstacleDistance);
    
    return 0;
}

// Generate a random number between given lower and upper bounds
int generateRandomNumber(int lower, int upper) {
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// Simulate car movement for given distance
void simulateCarMovement(int distance) {
    int currentPosition = 0;
    printf("Starting car position: %d\n", currentPosition);
    while(currentPosition < distance) {
        int moveDistance = generateRandomNumber(1, 5);
        currentPosition += moveDistance;
        printf("Car moved forward by %d units. Current position: %d\n", moveDistance, currentPosition);
    }
    printf("Car reached the obstacle.\n");
}