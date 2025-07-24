//FormAI DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <math.h>

//Constants
#define PI 3.14159265358979323846

int main()
{
    //Variables
    float initialX, initialY, time, velocity, angle, accelerationX, accelerationY, positionX, positionY;

    //Get initial position
    printf("Enter the initial X and Y coordinates (in meters): ");
    scanf("%f%f", &initialX, &initialY);

    //Get initial velocity
    printf("Enter the initial velocity (in meters per second): ");
    scanf("%f", &velocity);

    //Get angle of velocity vector
    printf("Enter the angle of the velocity vector (in degrees): ");
    scanf("%f", &angle);

    //Convert angle to radians
    angle = angle * PI / 180.0;

    //Get acceleration components
    printf("Enter the X and Y components of acceleration (in meters per second squared): ");
    scanf("%f%f", &accelerationX, &accelerationY);

    //Get time elapsed
    printf("Enter the time elapsed (in seconds): ");
    scanf("%f", &time);

    //Calculate final position
    positionX = initialX + velocity*cos(angle)*time + 0.5*accelerationX*pow(time, 2);
    positionY = initialY + velocity*sin(angle)*time + 0.5*accelerationY*pow(time, 2);

    //Print final position
    printf("Final position: (%f, %f)", positionX, positionY);

    return 0;
}