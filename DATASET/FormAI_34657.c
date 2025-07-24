//FormAI DATASET v1.0 Category: Physics simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    double init_velocity, launch_angle, horizontal_range, max_height, time;
    
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &init_velocity);
    
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &launch_angle);
    
    launch_angle = launch_angle * (PI / 180); // convert to radians
    
    horizontal_range = (pow(init_velocity, 2) * sin(2 * launch_angle)) / 9.8;
    max_height = pow(init_velocity, 2) * pow(sin(launch_angle), 2) / (2 * 9.8);
    time = (2 * init_velocity * sin(launch_angle)) / 9.8;
    
    printf("\nHorizontal range: %.2lf meters\n", horizontal_range);
    printf("Maximum height: %.2lf meters\n", max_height);
    printf("Time of flight: %.2lf seconds\n", time);
    
    return 0;
}