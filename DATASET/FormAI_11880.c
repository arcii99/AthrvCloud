//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>

#define MAX_SPEED 100
#define MAX_ANGLE 180

void moveForward(int speed);
void moveBackward(int speed);
void turnLeft(int angle);
void turnRight(int angle);

int main()
{
    int speed = 50;
    int angle = 90;
    
    moveForward(speed);
    turnLeft(angle);
    moveBackward(speed);
    turnRight(angle);
    
    return 0;
}

void moveForward(int speed)
{
    printf("Moving forward at speed %d\n", speed);
    // Add code to control robot movement forward at given speed
}

void moveBackward(int speed)
{
    printf("Moving backward at speed %d\n", speed);
    // Add code to control robot movement backward at given speed
}

void turnLeft(int angle)
{
    if (angle > MAX_ANGLE)
    {
        angle = MAX_ANGLE;
    }
    printf("Turning left at angle %d\n", angle);
    // Add code to control robot movement to turn left at given angle
}

void turnRight(int angle)
{
    if (angle > MAX_ANGLE)
    {
        angle = MAX_ANGLE;
    }
    printf("Turning right at angle %d\n", angle);
    // Add code to control robot movement to turn right at given angle
}