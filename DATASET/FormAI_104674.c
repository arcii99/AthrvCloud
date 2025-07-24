//FormAI DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793 // define pi as a constant

// function to calculate the next x position of the robot
double calculateX(double currentX, double distance, double angle) {
    return currentX + distance * cos(angle);
}

// function to calculate the next y position of the robot
double calculateY(double currentY, double distance, double angle) {
    return currentY + distance * sin(angle);
}

int main() {
    double currentX = 0.0; // starting x position of the robot
    double currentY = 0.0; // starting y position of the robot
    double currentAngle = 0.0; // starting angle of the robot in radians
    double distance = 10.0; // distance to move the robot
    double angle = PI/4; // angle to turn the robot in radians

    // move the robot forward and to the right at a 45 degree angle
    currentX = calculateX(currentX, distance, currentAngle + angle);
    currentY = calculateY(currentY, distance, currentAngle + angle);
    printf("New position: (%lf, %lf)\n", currentX, currentY);

    // turn the robot to the left 90 degrees
    currentAngle += PI/2;
    printf("New angle: %lf\n", currentAngle);

    // move the robot forward and to the left at a 45 degree angle
    currentX = calculateX(currentX, distance, currentAngle - angle);
    currentY = calculateY(currentY, distance, currentAngle - angle);
    printf("New position: (%lf, %lf)\n", currentX, currentY);

    return 0;
}