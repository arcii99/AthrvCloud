//FormAI DATASET v1.0 Category: Physics simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float mass, velocity, time, force, acceleration, distance;
    
    printf("Enter mass of the object in kg: ");
    scanf("%f", &mass);
    
    printf("Enter initial velocity in m/s: ");
    scanf("%f", &velocity);
    
    printf("Enter time taken in seconds: ");
    scanf("%f", &time);
    
    force = mass * acceleration;
    acceleration = (2 * distance)/ (time * time);
    distance = (0.5 * acceleration * time * time) + (velocity * time);
    
    printf("\nThe force exerted on the object is %.2f N\n", force);
    printf("The acceleration of the object is %.2f m/s^2\n", acceleration);
    printf("The distance travelled by the object is %.2f m\n", distance);
    
    return 0;
}