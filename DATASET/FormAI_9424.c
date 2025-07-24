//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <math.h>

float g = 9.81; // acceleration due to gravity

int main()
{
    float height, velocity, angle, time, range;
    const float pi = 3.14159; // value of pi
    
    // Get input values from user
    printf("Enter the height (m): ");
    scanf("%f", &height);
    printf("Enter the velocity (m/s): ");
    scanf("%f", &velocity);
    printf("Enter the angle of projection (degrees): ");
    scanf("%f", &angle);
    
    // Convert angle from degrees to radians
    angle = angle * pi / 180;
    
    // Time of flight of projectile
    time = (2 * velocity * sin(angle)) / g;
    
    // Maximum height achieved by projectile
    float max_height = height + (pow(velocity, 2) * pow(sin(angle), 2)) / (2 * g);
    
    // Horizontal range
    range = (pow(velocity, 2) * sin(2 * angle)) / g;
    
    // Display the results to the user
    printf("\nTime of flight: %.2f seconds\n", time);
    printf("Maximum height reached: %.2f meters\n", max_height);
    printf("Horizontal range: %.2f meters\n", range);
    
    return 0;
}