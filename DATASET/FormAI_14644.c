//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <math.h>

int main() {
    double acceleration, mass, force;
    const double gravity = 9.8;
    
    // Get the mass
    printf("Enter the mass in kilograms: ");
    scanf("%lf", &mass);
    
    // Calculate the force
    force = mass * gravity;
    printf("The force exerted on the mass by gravity is: %lfN\n", force);
    
    // Get the acceleration
    printf("Enter the acceleration in meters per second squared: ");
    scanf("%lf", &acceleration);
    
    // Calculate the force required
    force = mass * acceleration;
    printf("The force required to accelerate the mass at %lf m/s^2 is: %lfN\n", acceleration, force);
    
    // Get the force
    printf("Enter the force in Newtons: ");
    scanf("%lf", &force);
    
    // Calculate the acceleration
    acceleration = force / mass;
    printf("The acceleration the force will cause on the mass is: %lf m/s^2\n", acceleration);
    
    return 0;
}