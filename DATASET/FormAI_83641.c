//FormAI DATASET v1.0 Category: Physics simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    float v0, theta, x, y, t = 0, dt = 0.01;
    float g = 9.8; // acceleration due to gravity

    printf("Enter initial velocity(m/s): ");
    scanf("%f", &v0);
    printf("Enter angle of projection(degrees): ");
    scanf("%f", &theta);

    // convert angle from degrees to radians
    theta = theta * PI / 180;

    x = y = 0; // initial position of projectile

    while(y >= 0)
    {
        // calculate new position of projectile after dt time interval
        x = x + v0*cos(theta)*dt;
        y = y + v0*sin(theta)*dt - 0.5*g*dt*dt;

        printf("Position at time %.2f: (%.2f, %.2f)\n", t, x, y);

        // update time
        t += dt;
    }

    return 0;
}