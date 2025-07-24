//FormAI DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

#define TIME_STEP 0.1 // time step for simulation in seconds
#define MASS 1.0 // mass of the object in kilograms
#define GRAV_ACCEL 9.81 // acceleration due to gravity in m/s^2

int main()
{
    double position = 0.0; // initial position of the object in meters
    double velocity = 10.0; // initial velocity of the object in m/s

    printf("Position (m)\tVelocity (m/s)\n");
    printf("--------------------------\n");

    for (double time = 0.0; time <= 10.0; time += TIME_STEP)
    {
        double acceleration = -GRAV_ACCEL; // acceleration due to gravity

        // calculate new velocity and position
        velocity += acceleration * TIME_STEP;
        position += velocity * TIME_STEP;

        // check if object hits ground
        if (position < 0.0)
        {
            position = 0.0;
            velocity = -velocity * 0.8; // simulate elastic collision with ground
            if (velocity < 0.1) // object has come to rest
            {
                velocity = 0.0;
                acceleration = 0.0;
            }
        }

        printf("%.2f\t\t%.2f\n", position, velocity);

        // check if object is suspended in the air
        if (position > 0 && velocity == 0 && acceleration == -GRAV_ACCEL) 
        {
            printf("Object is suspended in the air at %.2f meters.\n", position);
            break;
        }
    }

    return 0;
}