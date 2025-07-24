//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float mass, velocity, acceleration, time, distance;
    
    // Input
    printf("Enter the mass of the object in kg: ");
    scanf("%f", &mass);
    
    printf("Enter the initial velocity of the object in m/s: ");
    scanf("%f", &velocity);
    
    printf("Enter the acceleration of the object in m/s^2: ");
    scanf("%f", &acceleration);
    
    printf("Enter the time elapsed in seconds: ");
    scanf("%f", &time);
    
    // Calculation
    distance = (velocity * time) + (0.5 * acceleration * time * time);
    
    // Output
    printf("\n\nThe distance travelled by the object is %.2f meters\n", distance);
    
    return 0;
}