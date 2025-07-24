//FormAI DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include<stdio.h>

// Function to calculate the final velocity of a projectile
float calculate_final_velocity(float initial_velocity, float angle)
{
    float velocity_x = initial_velocity * cos(angle);
    float velocity_y = initial_velocity * sin(angle);
    float time = 2 * velocity_y / 9.8;
    return velocity_x * time;
}

int main()
{
    float initial_velocity, angle;
    printf("Enter the initial velocity of the projectile (in m/s): ");
    scanf("%f", &initial_velocity);
    printf("Enter the angle of projection (in degrees): ");
    scanf("%f", &angle);
    angle = angle * 3.14159 / 180; // Converting angle to radians
    printf("The final velocity of the projectile is: %f m/s", calculate_final_velocity(initial_velocity, angle));
    return 0;
}