//FormAI DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>

// Constants to define the robot's movement direction
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

// Function prototypes
void move(int direction);
void displayPosition();

// Global variables to track the robot's position
int X = 0;
int Y = 0;

int main()
{
    printf("Starting position (%d, %d)\n", X, Y);
    
    move(RIGHT); // move to the right
    displayPosition();
    
    move(DOWN); // move down
    displayPosition();
    
    move(LEFT); // move to the left
    displayPosition();
    
    move(UP); // move up
    displayPosition();
    
    move(RIGHT); // move to the right
    displayPosition();
    
    return 0;
}

// Move the robot in the given direction
void move(int direction)
{
    switch(direction)
    {
        case LEFT:
            X--;
            break;
        case RIGHT:
            X++;
            break;
        case UP:
            Y++;
            break;
        case DOWN:
            Y--;
            break;
    }
}

// Display the robot's current position
void displayPosition()
{
    printf("Current position: (%d, %d)\n", X, Y);
}