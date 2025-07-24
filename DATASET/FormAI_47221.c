//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void takeoff();
void land();
void moveForward(int distance);
void moveBackward(int distance);
void turnLeft(int degrees);
void turnRight(int degrees);
void increaseAltitude(int altitude);
void decreaseAltitude(int altitude);

int main() {
    printf("Welcome to the C Drone Remote Control program!\n");

    // Takeoff the drone
    takeoff();

    // Move the drone forward by 50 meters
    moveForward(50);

    // Turn the drone left by 90 degrees
    turnLeft(90);

    // Increase the altitude by 20 meters
    increaseAltitude(20);

    // Move the drone backward by 30 meters
    moveBackward(30);

    // Turn the drone right by 45 degrees
    turnRight(45);

    // Decrease the altitude by 10 meters
    decreaseAltitude(10);

    // Land the drone
    land();
    
    return 0;
}

void takeoff() {
    printf("Drone: Taking off\n");
}

void land() {
    printf("Drone: Landing\n");
}

void moveForward(int distance) {
    printf("Drone: Moving forward by %d meters\n", distance);
}

void moveBackward(int distance) {
    printf("Drone: Moving backward by %d meters\n", distance);
}

void turnLeft(int degrees) {
    printf("Drone: Turning left by %d degrees\n", degrees);
}

void turnRight(int degrees) {
    printf("Drone: Turning right by %d degrees\n", degrees);
}

void increaseAltitude(int altitude) {
    printf("Drone: Increasing altitude by %d meters\n", altitude);
}

void decreaseAltitude(int altitude) {
    printf("Drone: Decreasing altitude by %d meters\n", altitude);
}