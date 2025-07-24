//FormAI DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // acceleration due to gravity

int main()
{
    // user input
    double height, angle, velocity;
    printf("Enter the height of the projectile (in meters): ");
    scanf("%lf", &height);
    printf("Enter the angle of launch (in degrees): ");
    scanf("%lf", &angle);
    printf("Enter the initial velocity (in meters per second): ");
    scanf("%lf", &velocity);

    // conversion from degrees to radians
    angle = angle * M_PI / 180;

    // variables
    double time = 0;
    double xpos = 0;
    double ypos = height;
    double xvel = velocity * cos(angle);
    double yvel = velocity * sin(angle);
    double xacc = 0;
    double yacc = -GRAVITY;

    // simulation loop
    while(ypos > 0)
    {
        // update time
        time += 0.01;

        // calculate new x and y positions
        xpos = xvel * time;
        ypos = height + yvel * time + 0.5 * yacc * pow(time, 2);

        // calculate new x and y velocities
        xvel += xacc * 0.01;
        yvel += yacc * 0.01;

        // display current position
        printf("Time: %6.2f sec | Position: (%6.2f, %6.2f)\n", time, xpos, ypos);
    }

    return 0;
}