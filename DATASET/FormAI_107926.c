//FormAI DATASET v1.0 Category: Physics simulation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main() {
    // Welcome message
    printf("Welcome to the Physics simulation program!\n\n");
    
    // Get input
    double mass, velocity, distance;
    printf("Please enter the mass of the object (in kg): ");
    scanf("%lf", &mass);
    printf("Please enter the initial velocity of the object (in m/s): ");
    scanf("%lf", &velocity);
    printf("Please enter the distance that the object should travel (in m): ");
    scanf("%lf", &distance);
    
    // Calculate force and time
    double force = mass * pow(velocity, 2) / (2 * distance);
    double time = distance / velocity;
    
    // Output results
    printf("\nThe force required to move the object is: %.2lf N\n", force);
    printf("The time taken to move the object is: %.2lf s\n", time);
    
    // Goodbye message
    printf("\nThank you for using the Physics simulation program!\n");
    
    return 0;
}