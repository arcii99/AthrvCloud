//FormAI DATASET v1.0 Category: Physics simulation ; Style: cheerful
#include <stdio.h>

int main()
{
    float init_height, bounce_height, bounce_coefficient;
    float height, velocity;
    int time = 0;
    
    // User input
    printf("Enter initial height of ball: ");
    scanf("%f", &init_height);
    printf("Enter height of bounce: ");
    scanf("%f", &bounce_height);
    printf("Enter coefficient of restitution: ");
    scanf("%f", &bounce_coefficient);
    
    // Calculation loop
    height = init_height;
    velocity = 0;
    while (height > 0)
    {
        // Update velocity and position
        velocity = velocity - 9.81 * 0.01;
        height = height + velocity * 0.01;
        time++;
        
        // Check for bounce
        if (height <= bounce_height)
        {
            velocity = -velocity * bounce_coefficient;
            height = bounce_height;
            printf("Bounce at time %d\n", time);
        }
        
        // Output current state
        printf("Time: %d sec, Height: %.2f m, Velocity: %.2f m/s\n", time, height, velocity);
    }
    
    // Output final state
    printf("The ball hit the ground after %d sec.\n", time);
    return 0;
}