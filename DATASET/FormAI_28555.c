//FormAI DATASET v1.0 Category: Physics simulation ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main()
{
    float initial_velocity, angle, distance, acceleration_x, acceleration_y, time;
    
    // User Input
    
    printf("Enter the initial velocity(m/s): ");
    scanf("%f", &initial_velocity);
    
    printf("Enter the angle of projection(degrees): ");
    scanf("%f", &angle);
    
    printf("Enter the distance(m): ");
    scanf("%f", &distance);
    
    printf("Enter the acceleration in x direction(m/s^2): ");
    scanf("%f", &acceleration_x);
    
    printf("Enter the acceleration in y direction(m/s^2): ");
    scanf("%f", &acceleration_y);
    
    // Calculation of variables
    
    float radians = angle * M_PI / 180.0;
    float velocity_x = initial_velocity * cos(radians);
    float velocity_y = initial_velocity * sin(radians);
    float time_of_flight = 2 * velocity_y / acceleration_y;
    float height = pow(velocity_y, 2) / (2 * acceleration_y);
    float range = velocity_x * time_of_flight;
    float final_velocity_x = velocity_x + acceleration_x * time_of_flight;
    float final_velocity_y = velocity_y + acceleration_y * time_of_flight;
    
    // Output
    
    printf("\nThe velocity in x direction: %.2f m/s", velocity_x);
    printf("\nThe velocity in y direction: %.2f m/s", velocity_y);
    printf("\nThe time of flight: %.2f seconds", time_of_flight);
    printf("\nThe maximum height reached: %.2f meters", height);
    printf("\nThe horizontal range: %.2f meters", range);
    printf("\nThe final velocity in x direction: %.2f m/s", final_velocity_x);
    printf("\nThe final velocity in y direction: %.2f m/s", final_velocity_y);
    
    return 0;
}