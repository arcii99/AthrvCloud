//FormAI DATASET v1.0 Category: Robot movement control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define global variables for robot location and direction
int robotX = 0;
int robotY = 0;
int robotDir = 0; // 0 for North, 1 for East, 2 for South, 3 for West

// Define functions for each robot movement
void moveForward() {
    switch (robotDir) {
        case 0:
            robotY++;
            break;
        case 1:
            robotX++;
            break;
        case 2:
            robotY--;
            break;
        case 3:
            robotX--;
            break;
    }
}

void moveBackward() {
    switch (robotDir) {
        case 0:
            robotY--;
            break;
        case 1:
            robotX--;
            break;
        case 2:
            robotY++;
            break;
        case 3:
            robotX++;
            break;
    }
}

void turnLeft() {
    robotDir = (robotDir + 3) % 4; // Modulo operation ensures value stays between 0 and 3
}

void turnRight() {
    robotDir = (robotDir + 1) % 4; // Modulo operation ensures value stays between 0 and 3
}

// Define function for printing robot location in a user-friendly format
void printLocation() {
    printf("The robot is currently at (%d, %d) facing ", robotX, robotY);
    switch (robotDir) {
        case 0:
            printf("North.\n");
            break;
        case 1:
            printf("East.\n");
            break;
        case 2:
            printf("South.\n");
            break;
        case 3:
            printf("West.\n");
            break;
    }
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));
    
    // Generate random movement commands and execute them
    int numMoves = rand() % 11 + 10; // Random number between 10 and 20
    printf("Executing %d movements...\n\n", numMoves);
    for (int i = 0; i < numMoves; i++) {
        int moveType = rand() % 4; // Random number between 0 and 3
        switch (moveType) {
            case 0:
                printf("Moving forward...\n");
                moveForward();
                break;
            case 1:
                printf("Moving backward...\n");
                moveBackward();
                break;
            case 2:
                printf("Turning left...\n");
                turnLeft();
                break;
            case 3:
                printf("Turning right...\n");
                turnRight();
                break;
        }
        printLocation();
    }

    return 0;
}