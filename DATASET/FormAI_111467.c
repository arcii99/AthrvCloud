//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include <stdio.h> 

// Define constants 
#define MAX_SPEED 100 
#define TURN_SPEED 50 
#define STOP_SPEED 0 

// Define control values 
int speed = STOP_SPEED; 
int direction = 0; 
int isMoving = 0; 

// Function to move the vehicle 
void move() { 
    // Check if the vehicle is already moving 
    if(isMoving) { 
        printf("Vehicle is already in motion.\n"); 
        return; 
    } 

    // Set the speed and direction 
    speed = MAX_SPEED; 
    direction = 1; 
    isMoving = 1; 

    // Display the movement 
    printf("Vehicle is now moving at %d mph in direction %d.\n", speed, direction); 
} 

// Function to turn the vehicle 
void turn(int newDirection) { 
    // Check if the vehicle is moving 
    if(speed == STOP_SPEED) { 
        printf("Vehicle is not moving, cannot turn.\n"); 
        return; 
    } 

    // Set the new direction 
    direction = newDirection; 

    // Display the turn 
    printf("Vehicle has turned to direction %d.\n", direction); 
} 

// Function to stop the vehicle 
void stop() { 
    // Check if the vehicle is already stopped 
    if(speed == STOP_SPEED) { 
        printf("Vehicle is already stopped.\n"); 
        return; 
    } 

    // Set the speed and direction 
    speed = STOP_SPEED; 
    direction = 0; 
    isMoving = 0; 

    // Display the stop 
    printf("Vehicle has stopped.\n"); 
} 

int main() { 
    // Test the functions 
    move(); 
    turn(1); 
    move(); 
    turn(-1); 
    move(); 
    stop(); 

    return 0; 
}