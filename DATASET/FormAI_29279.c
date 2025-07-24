//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main()
{
    // Define variables
    double position = 0.0;
    double velocity = 0.0;
    double acceleration = 9.81;
    double time = 0.0;
    
    // Prompt user for input
    printf("Enter the initial velocity of the object (m/s): ");
    scanf("%lf", &velocity);
    printf("Enter the initial position of the object (m): ");
    scanf("%lf", &position);
    
    // Create simulation loop
    while (position >= 0.0)
    {
        // Calculate time elapsed
        double delta_t = sqrt((2*position)/acceleration);
        
        // Update time and position
        time += delta_t;
        position = velocity*delta_t - 0.5*acceleration*pow(delta_t, 2);
        
        // Update velocity
        velocity = velocity - acceleration*delta_t;
        
        // Output results
        printf("Time: %.2lf s | Position: %.2lf m | Velocity: %.2lf m/s\n", time, position, velocity);
    }
    
    // Object has reached the ground
    printf("The object has reached the ground at time %.2lf seconds.", time);
    
    return 0;
}