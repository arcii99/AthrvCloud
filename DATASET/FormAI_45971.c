//FormAI DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
/* The following is a simulation of a simple pendulum in Physics using C language
   The program requires a user input for the length of the pendulum and the initial displacement angle.
   Based on these parameters, the program calculates the motion of the pendulum and displays it on the screen */

#include <stdio.h>
#include <math.h>

int main() {

    double length, angle, period, time, omega, acceleration, theta, x, y;
    const double g = 9.81;

    // taking inputs from user
    printf("Enter the length of the pendulum (in meters): ");
    scanf("%lf", &length);
    printf("Enter the angle of displacement (in degrees): ");
    scanf("%lf", &angle);

    // converting degrees to radians
    theta = angle * M_PI / 180.0;

    // calculating period of oscillation
    period = 2.0 * M_PI * sqrt(length / g);

    printf("The period of oscillation is: %.2f seconds\n\n", period);

    // simulation loop
    for (time = 0.0; time < period; time += 0.01) {
        omega = sqrt(g / length);
        theta = angle * cos(omega * time);
        acceleration = -g / length * sin(theta);
        x = length * sin(theta);
        y = length * cos(theta);
        printf("Time: %.2fs    Position: (%.2fm, %.2fm)\n", time, x, y);
    }

    return 0;
}