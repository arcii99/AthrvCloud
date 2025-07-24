//FormAI DATASET v1.0 Category: Robot movement control ; Style: future-proof
#include <stdio.h>

/* Constants */
#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGLE 180
#define MIN_ANGLE 0

/* Function Declarations */
void moveForward(int speed);
void moveBackward(int speed);
void turnRight(int angle);
void turnLeft(int angle);

/* Main Function */
int main()
{
    int speed = 50;
    int angle = 90;
    
    moveForward(speed);
    turnRight(angle);
    moveBackward(speed);
    turnLeft(angle);
    
    return 0;
}

/* Function Definitions */
void moveForward(int speed)
{
    if(speed > MAX_SPEED)
    {
        printf("Error: speed too high. Setting speed to max.\n");
        speed = MAX_SPEED;
    }
    else if(speed < MIN_SPEED)
    {
        printf("Error: speed too low. Setting speed to min.\n");
        speed = MIN_SPEED;
    }
    
    printf("Moving forward at speed %d.\n", speed);
}

void moveBackward(int speed)
{
    if(speed > MAX_SPEED)
    {
        printf("Error: speed too high. Setting speed to max.\n");
        speed = MAX_SPEED;
    }
    else if(speed < MIN_SPEED)
    {
        printf("Error: speed too low. Setting speed to min.\n");
        speed = MIN_SPEED;
    }
    
    printf("Moving backward at speed %d.\n", speed);
}

void turnRight(int angle)
{
    if(angle > MAX_ANGLE)
    {
        printf("Error: angle too high. Setting angle to max.\n");
        angle = MAX_ANGLE;
    }
    else if(angle < MIN_ANGLE)
    {
        printf("Error: angle too low. Setting angle to min.\n");
        angle = MIN_ANGLE;
    }
    
    printf("Turning right at angle %d.\n", angle);
}

void turnLeft(int angle)
{
    if(angle > MAX_ANGLE)
    {
        printf("Error: angle too high. Setting angle to max.\n");
        angle = MAX_ANGLE;
    }
    else if(angle < MIN_ANGLE)
    {
        printf("Error: angle too low. Setting angle to min.\n");
        angle = MIN_ANGLE;
    }
    
    printf("Turning left at angle %d.\n", angle);
}