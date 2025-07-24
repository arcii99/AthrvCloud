//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265

// Robot State
bool robotActive = true;
double robotXPos = 0;
double robotYPos = 0;
double robotHeading = 0; // degrees

// Robot Movement Constants
double moveSpeed = 1; // units per second
double turnSpeed = 90; // degrees per second

// Utility Functions
double degreesToRadians(double degrees) {
    return degrees * PI / 180;
}

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

// Movement Functions
void moveForward(double distance) {
    double newX = robotXPos + distance * cos(degreesToRadians(robotHeading));
    double newY = robotYPos + distance * sin(degreesToRadians(robotHeading));
    printf("Moving robot from (%f, %f) to (%f, %f)\n", robotXPos, robotYPos, newX, newY);
    robotXPos = newX;
    robotYPos = newY;
}

void turnLeft(double angle) {
    double newHeading = fmod(robotHeading + angle, 360);
    printf("Turning robot from heading %f to heading %f\n", robotHeading, newHeading);
    robotHeading = newHeading;
}

void turnRight(double angle) {
    double newHeading = fmod(robotHeading - angle, 360);
    printf("Turning robot from heading %f to heading %f\n", robotHeading, newHeading);
    robotHeading = newHeading;
}

// Main Function
int main() {
    printf("Starting Robot Movement Program\n");
    
    // Move robot forward 10 units and turn left 45 degrees
    moveForward(10);
    turnLeft(45);
    
    // Move robot forward 5 units and turn right 90 degrees
    moveForward(5);
    turnRight(90);
    
    printf("Robot Movement Program Complete\n");
    return 0;
}