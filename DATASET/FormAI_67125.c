//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: automated
#include <stdio.h>

// function to set drone speed
void setSpeed(int speed) {
    printf("Setting drone speed to %d\n", speed);
}

// function to move drone up
void moveUp(int distance) {
    printf("Moving drone up by %d meters\n", distance);
}

// function to move drone down
void moveDown(int distance) {
    printf("Moving drone down by %d meters\n", distance);
}

// function to move drone left
void moveLeft(int distance) {
    printf("Moving drone left by %d meters\n", distance);
}

// function to move drone right
void moveRight(int distance) {
    printf("Moving drone right by %d meters\n", distance);
}

// function to take photo
void takePhoto() {
    printf("Taking photo\n");
}

int main() {
    // initializing drone
    printf("Initializing drone...\n");
    
    // setting drone speed
    setSpeed(10);
    
    // moving drone up
    moveUp(5);
    
    // moving drone right
    moveRight(3);
    
    // taking photo
    takePhoto();
    
    // moving drone left
    moveLeft(3);
    
    // moving drone down
    moveDown(5);
    
    // setting drone speed to 0 to stop the drone
    setSpeed(0);
    
    // landing the drone
    printf("Landing drone...\n");
    
    return 0;
}