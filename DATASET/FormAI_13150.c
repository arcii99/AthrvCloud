//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
/* This program simulates the motion of a simple pendulum */

#include <stdio.h>
#include <math.h>

int main()
{
    double l, g, theta, dt, t, x, y;
    int i, n;

    printf("Enter the length of the pendulum (in meters): ");
    scanf("%lf", &l);

    printf("Enter the gravitational acceleration (in meters per second squared): ");
    scanf("%lf", &g);

    printf("Enter the initial angle (in degrees): ");
    scanf("%lf", &theta);

    printf("Enter the time step (in seconds): ");
    scanf("%lf", &dt);

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    theta = theta * M_PI / 180; /* convert degrees to radians */
    x = l * sin(theta);
    y = -l * cos(theta);
    t = 0;

    for (i = 0; i < n; i++) {
        double theta_new = theta - ((g / l) * sin(theta)) * dt;
        x = l * sin(theta_new);
        y = -l * cos(theta_new);

        printf("t = %f, theta = %f, x = %f, y = %f\n", t, theta * 180 / M_PI, x, y);

        theta = theta_new;
        t += dt;
    }

    return 0;
}