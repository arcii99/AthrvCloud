//FormAI DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

#define G 9.807 //acceleration due to gravity on Earth

int main()
{
    float mass, height, initial_velocity, time_step, final_velocity, acceleration, time, distance;
    int i;

    printf("Enter the mass in kg: ");
    scanf("%f", &mass);

    printf("Enter the initial height in meters: ");
    scanf("%f", &height);

    printf("Enter the initial velocity in m/s: ");
    scanf("%f", &initial_velocity);

    printf("Enter the time step in seconds: ");
    scanf("%f", &time_step);

    acceleration = G;

    time = 0.0; //initial time
    distance = height; //initial distance

    for(i = 0; distance >= 0; i++) //loop until the object hits the ground
    {
        distance = height - (initial_velocity * time) + (0.5 * acceleration * pow(time, 2)); //calculate the distance
        final_velocity = initial_velocity + (acceleration * time); //calculate the final velocity
        time += time_step; //increment the time

        printf("Time: %.2f seconds\tDistance: %.2f meters\tVelocity: %.2f m/s\n", time, distance, final_velocity);
    }

    printf("Object has hit the ground at %.2f seconds.\n", time - time_step); //print the time at which the object hit the ground

    return 0;
}