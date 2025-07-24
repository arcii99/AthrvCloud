//FormAI DATASET v1.0 Category: Physics simulation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    double time = 0, dt = 0.01;
    double velocity = 0, acceleration = 0;
    double position = 0;
    double k = 1, m = 1, b = 0.2;

    while (time <= 10) {
        // Calculating acceleration using F=ma equation
        acceleration = -(k / m) * position - (b / m) * velocity;
        // Updating velocity and position using Euler's method
        velocity = velocity + acceleration * dt;
        position = position + velocity * dt;
        // Printing the values of time, velocity, and position
        printf("%.2f  %.2f  %.2f\n", time, velocity, position);
        time = time + dt;
    }

    return 0;
}