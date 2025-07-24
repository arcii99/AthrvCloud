//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int changeDirection(int currentDir);
int moveForward(int direction, int xPos, int yPos);
int moveBackward(int direction, int xPos, int yPos);
void simulateRemoteControlVehicle();

int main() {
    simulateRemoteControlVehicle();

    return 0;
}

// Changes the direction of the vehicle randomly
int changeDirection(int currentDir) {
    srand(time(0));
    int newDir = currentDir;
    while (newDir == currentDir) {
        newDir = rand() % 4; // 0: North, 1: East, 2: South, 3: West
    }
    return newDir;
}

// Moves the vehicle one unit forward in the given direction
int moveForward(int direction, int xPos, int yPos) {
    int newXPos = xPos;
    int newYPos = yPos;
    switch (direction) {
        case 0:
            newYPos++;
            break;
        case 1:
            newXPos++;
            break;
        case 2:
            newYPos--;
            break;
        case 3:
            newXPos--;
            break;
    }
    printf("Vehicle moves one unit forward, current position: (%d, %d)\n", newXPos, newYPos);
    return newXPos * 100 + newYPos;
}

// Moves the vehicle one unit backward in the given direction
int moveBackward(int direction, int xPos, int yPos) {
    int newXPos = xPos;
    int newYPos = yPos;
    switch (direction) {
        case 0:
            newYPos--;
            break;
        case 1:
            newXPos--;
            break;
        case 2:
            newYPos++;
            break;
        case 3:
            newXPos++;
            break;
    }
    printf("Vehicle moves one unit backward, current position: (%d, %d)\n", newXPos, newYPos);
    return newXPos * 100 + newYPos;
}

// Simulates the remote control vehicle by randomly changing its direction and moving it forward or backward
void simulateRemoteControlVehicle() {
    int direction = 0; // Start at North direction
    int currentPos = 500; // Start at position (5, 0)
    int xPos = currentPos / 100;
    int yPos = currentPos % 100;
    
    for (int i = 0; i < 10; i++) {
        int moveType = rand() % 2; // 0: Move forward, 1: Move backward
        if (moveType == 0) {
            currentPos = moveForward(direction, xPos, yPos);
        } else {
            currentPos = moveBackward(direction, xPos, yPos);
        }
        xPos = currentPos / 100;
        yPos = currentPos % 100;
        direction = changeDirection(direction);
    }
}